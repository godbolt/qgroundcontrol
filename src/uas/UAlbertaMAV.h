/*=====================================================================

QGroundControl Open Source Ground Control Station

(c) 2009 - 2011 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>

This file is part of the QGROUNDCONTROL project

    QGROUNDCONTROL is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    QGROUNDCONTROL is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with QGROUNDCONTROL. If not, see <http://www.gnu.org/licenses/>.

======================================================================*/

/*
 * @file UAlbertaMAV.h
 *
 *  @author Bryan Godbolt <godbolt@ece.ualberta.ca>
 *  @date February 5, 2012: Class Creation
 *
 */

#ifndef UALBERTAMAV_H_
#define UALBERTAMAV_H_

#include <UAS.h>

#include <QVector>

class UAlbertaMAV : public UAS
{
	Q_OBJECT
	Q_INTERFACES(UASInterface)
public:
	UAlbertaMAV(MAVLinkProtocol* protocol, int id);

public slots:
	void receiveMessage(LinkInterface* link, mavlink_message_t message);


signals:
	void positionChanged(QVector<float> llh, QVector<float> ned);
	void velcoityChanged(QVector<float> ned);
	void originChanged(QVector<float> llh_origin);
	void gx3Status(QString gx3_status);
	void gx3Message(QString msg);
	void pilotMode(QString pilot_mode);
	void controlMode(QString control_mode);
	void servoSource(QString servo_source);
};

#endif
