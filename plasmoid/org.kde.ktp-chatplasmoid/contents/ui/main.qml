import Qt 4.7
import org.kde.telepathy.chat 0.1
import org.kde.plasma.core 0.1 as PlasmaCore
import org.kde.plasma.graphicswidgets 0.1 as PlasmaWidgets
import org.kde.plasma.components 0.1 as PlasmaComponents


Item {

    TelepathyTextObserver {
        id: handler
    }

    id: top
    ListView {
        id: base
        anchors.fill: parent
        orientation: Qt.Horizontal

        model: handler.conversations

        delegate : ConversationDelegate {
            //FIXME: rename the two variables named 'conv' as it's confusing
            id:conv
            anchors.top: parent.top
            anchors.bottom: parent.bottom

            image: model.conversation.target.avatar
            overlayText: model.conversation.messages.unreadCount

            //FIXME: put in a loader to not slow down the model
            PlasmaCore.Dialog {
                id: dialog
                //Set as a Tool window to bypass the taskbar
                windowFlags: Qt.WindowStaysOnTopHint | Qt.Tool
                visible: conv.pressed

                mainItem: ChatWidget {
                    width: 250
                    height: 350
                    conv: model.conversation

                    onCloseRequested: {
                        conv.pressed = false;
                    }
                }
            }

            Connections {
                target: model.conversation.messages
                onPopoutRequested: {
                    conv.pressed = true;
                }
            }

            // needed to let MessageModel know when messages are visible
            // so that it can acknowledge them properly
            Binding {
                target: model.conversation.messages
                property: "visibleToUser"
                value: conv.pressed
            }

            onToggled: {
                if(pressed) {
                    var point = dialog.popupPosition(conv, Qt.AlignBottom);
                    console.log("Showing dialog at (" + point.x + "," + point.y + ")");

                    dialog.x = point.x;
                    dialog.y = point.y;
                }
            }
        }
    }

}