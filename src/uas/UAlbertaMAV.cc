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
#include "UAlbertaMAV.h"

//#include "ualberta.h"

UAlbertaMAV::UAlbertaMAV(MAVLinkProtocol* protocol, int id)
:UAS(protocol, id)
{


}

void UAlbertaMAV::receiveMessage(LinkInterface* link, mavlink_message_t message)
{

#if defined(QGC_USE_UALBERTA_MESSAGES)
//	qDebug() << "Message ID: " << message.msgid;
	if (message.sysid == uasId)
	{
		switch(message.msgid)
		{
		case MAVLINK_MSG_ID_UALBERTA_SYS_STATUS:
		{
			qDebug() << "Received UAlberta Status Message";
			mavlink_ualberta_sys_status_t status;
			mavlink_msg_ualberta_sys_status_decode(&message, &status);
			switch (status.mode)
			{
			case UALBERTA_MODE_MANUAL_DIRECT:
				emit servoSource("Direct Manaul");
				break;
			case UALBERTA_MODE_MANUAL_SCALED:
				emit servoSource("Scaled Manual");
				break;
			case UALBERTA_MODE_AUTOMATIC_CONTROL:
				emit servoSource("Automatic Control");
				break;
			}

			break;
		}
		case MAVLINK_MSG_ID_NAV_FILTER_BIAS:
		{
			mavlink_nav_filter_bias_t bias;
			mavlink_msg_nav_filter_bias_decode(&message, &bias);
			quint64 time = getUnixTime();
			// FIXME REMOVE LATER emit valueChanged(uasId, "b_f[0]", "raw", bias.accel_0, time);
			// FIXME REMOVE LATER emit valueChanged(uasId, "b_f[1]", "raw", bias.accel_1, time);
			// FIXME REMOVE LATER emit valueChanged(uasId, "b_f[2]", "raw", bias.accel_2, time);
			// FIXME REMOVE LATER emit valueChanged(uasId, "b_w[0]", "raw", bias.gyro_0, time);
			// FIXME REMOVE LATER emit valueChanged(uasId, "b_w[1]", "raw", bias.gyro_1, time);
			// FIXME REMOVE LATER emit valueChanged(uasId, "b_w[2]", "raw", bias.gyro_2, time);
		}
		break;
		case MAVLINK_MSG_ID_RADIO_CALIBRATION:
		{
			mavlink_radio_calibration_t radioMsg;
			mavlink_msg_radio_calibration_decode(&message, &radioMsg);
			QVector<uint16_t> aileron;
			QVector<uint16_t> elevator;
			QVector<uint16_t> rudder;
			QVector<uint16_t> gyro;
			QVector<uint16_t> pitch;
			QVector<uint16_t> throttle;

			for (int i=0; i<MAVLINK_MSG_RADIO_CALIBRATION_FIELD_AILERON_LEN; ++i)
				aileron << radioMsg.aileron[i];
			for (int i=0; i<MAVLINK_MSG_RADIO_CALIBRATION_FIELD_ELEVATOR_LEN; ++i)
				elevator << radioMsg.elevator[i];
			for (int i=0; i<MAVLINK_MSG_RADIO_CALIBRATION_FIELD_RUDDER_LEN; ++i)
				rudder << radioMsg.rudder[i];
			for (int i=0; i<MAVLINK_MSG_RADIO_CALIBRATION_FIELD_GYRO_LEN; ++i)
				gyro << radioMsg.gyro[i];
			for (int i=0; i<MAVLINK_MSG_RADIO_CALIBRATION_FIELD_PITCH_LEN; ++i)
				pitch << radioMsg.pitch[i];
			for (int i=0; i<MAVLINK_MSG_RADIO_CALIBRATION_FIELD_THROTTLE_LEN; ++i)
				throttle << radioMsg.throttle[i];

			QPointer<RadioCalibrationData> radioData = new RadioCalibrationData(aileron, elevator, rudder, gyro, pitch, throttle);
			emit radioCalibrationReceived(radioData);
			delete radioData;
		}
		break;


		default:
			UAS::receiveMessage(link, message);
			break;
		}
	}
#else

#endif
}
