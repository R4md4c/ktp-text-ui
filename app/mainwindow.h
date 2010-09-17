/***************************************************************************
 *   Copyright (C) 2010 by David Edmundson <kde@davidedmundson.co.uk>      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#ifndef REALCLIENTHANDLER_H
#define REALCLIENTHANDLER_H

#include <KTabWidget>

#include <TelepathyQt4/AbstractClientHandler>
#include <TelepathyQt4/types.h>
#include <TelepathyQt4/Channel>
#include <TelepathyQt4/TextChannel>
#include <TelepathyQt4/ReceivedMessage>
#include <chatconnection.h>

using namespace Tp;

inline ChannelClassList channelClassList();

//In the future I want to have a (potential) list of tab widgets. Like Kopete presently. This may need a bit of a rewrite.

class MainWindow : public KTabWidget, public AbstractClientHandler
{
    Q_OBJECT
public:
    MainWindow();

    virtual void handleChannels(const MethodInvocationContextPtr<> &context,
                                const AccountPtr & account,
                                const ConnectionPtr & connection,
                                const QList< ChannelPtr > & channels,
                                const QList< ChannelRequestPtr > & requestsSatisfied,
                                const QDateTime &  userActionTime,
                                const QVariantMap & handlerInfo
                               );

    bool bypassApproval() const {
        return false;
    }

private slots:
    void updateTabText(QString newTitle);

};

#endif // REALCLIENTHANDLER_H