include_directories(${CMAKE_SOURCE_DIR}/lib)

set(kcm_ktp_chat_appearance_SRCS
        appearance-config.cpp
)

set(kcm_ktp_chat_behavior_SRCS
        behavior-config.cpp
)

set(kcm_ktp_chat_appearance_UI
    appearance-config.ui
)

set(kcm_ktp_chat_behavior_UI
    behavior-config.ui
)

kde4_add_ui_files(kcm_ktp_chat_appearance_SRCS ${kcm_ktp_chat_appearance_UI})

kde4_add_plugin(kcm_ktp_chat_appearance
		    ${kcm_ktp_chat_appearance_SRCS})

target_link_libraries(kcm_ktp_chat_appearance ${KDE4_KDECORE_LIBS} ${KDE4_KDEUI_LIBS} ${QT_QTWEBKIT_LIBRARY} ${KDE4_KCMUTILS_LIBS} ktpchat)


kde4_add_ui_files(kcm_ktp_chat_behavior_SRCS ${kcm_ktp_chat_behavior_UI})

kde4_add_plugin(kcm_ktp_chat_behavior
                    ${kcm_ktp_chat_behavior_SRCS})

target_link_libraries(kcm_ktp_chat_behavior ${KDE4_KDECORE_LIBS} ${KDE4_KDEUI_LIBS} ${KDE4_KCMUTILS_LIBS} ktpchat)


install(TARGETS kcm_ktp_chat_appearance
                kcm_ktp_chat_behavior
	  DESTINATION ${PLUGIN_INSTALL_DIR})

install (FILES kcm_ktp_chat_appearance.desktop
               kcm_ktp_chat_behavior.desktop
         DESTINATION ${SERVICES_INSTALL_DIR}
)
