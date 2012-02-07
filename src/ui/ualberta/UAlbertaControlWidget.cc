/*=====================================================================

PIXHAWK Micro Air Vehicle Flying Robotics Toolkit

(c) 2009, 2010 PIXHAWK PROJECT  <http://pixhawk.ethz.ch>

This file is part of the PIXHAWK project

    PIXHAWK is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    PIXHAWK is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with PIXHAWK. If not, see <http://www.gnu.org/licenses/>.

======================================================================*/

/**
 * @file
 *
 *
 *   @author Bryan Godbolt <godbolt@ece.ualberta.ca>
 *   @date February 5, 2012: Class Creation
 *
 */

#include "UAlbertaControlWidget.h"

#include <QString>
//#include <QTimer>
//#include <QLabel>
//#include <QFileDialog>
//#include <QDebug>
//#include <QProcess>
//#include <QPalette>
#include <QStringList>


#include <UASManager.h>
#include <UAlbertaMAV.h>
//#include <UAS.h>
//#include "QGC.h"

UAlbertaControlWidget::UAlbertaControlWidget(QWidget *parent) :
	QWidget(parent),
    uas(0)
{
	ui.setupUi(this);
	connect(UASManager::instance(), SIGNAL(activeUASSet(UASInterface*)), this, SLOT(setUAS(UASInterface*)));
	connect(ui.servo_source_button, SIGNAL(clicked()), this, SLOT(setServoSource()));
	connect(ui.control_mode_button, SIGNAL(clicked()), this, SLOT(setControlMode()));
	connect(ui.ned_origin_button, SIGNAL(clicked()), this, SLOT(setOrigin()));


	// note string appear in same order as mavlink enum (necessary for indexing)
	QStringList servo_sources;
	servo_sources << "Direct Manual" << "Scaled Manual" << "Automatic Control";
	ui.servo_source_box->addItems(servo_sources);

	QStringList controller_modes;
	controller_modes << "Attitude PID" << "Translation PID";
	ui.control_mode_box->addItems(controller_modes);



}

UAlbertaControlWidget::~UAlbertaControlWidget()
{

}

void UAlbertaControlWidget::setServoSource()
{

#ifdef QGC_USE_UALBERTA_MESSAGES
	UAlbertaMAV* mav = dynamic_cast<UAlbertaMAV*>(UASManager::instance()->getUASForId(this->uas));
	if (mav)
	{
		qDebug() << "Set servo source to " << ui.servo_source_box->currentText() << " with index: " << ui.servo_source_box->currentIndex();
		mavlink_message_t msg;
		mavlink_msg_ualberta_action_pack(uas, 0, &msg, UALBERTA_SET_SERVO_SOURCE, ui.servo_source_box->currentIndex());
		mav->sendMessage(msg);
	}
#endif
}

void UAlbertaControlWidget::setControlMode()
{
#ifdef QGC_USE_UALBERTA_MESSAGES

	UAlbertaMAV* mav = dynamic_cast<UAlbertaMAV*>(UASManager::instance()->getUASForId(uas));
	if (mav)
	{
		qDebug() << "Set Control Mode to " << ui.control_mode_box->currentText() << " with index: " << ui.control_mode_box->currentIndex();
		mavlink_message_t msg;
		mavlink_msg_ualberta_action_pack(uas, 0, &msg, UALBERTA_SET_CONTROL_MODE, ui.control_mode_box->currentIndex());
		mav->sendMessage(msg);
	}
#endif
}

void UAlbertaControlWidget::setOrigin()
{
#ifdef QGC_USE_UALBERTA_MESSAGES

	UAlbertaMAV* mav = dynamic_cast<UAlbertaMAV*>(UASManager::instance()->getUASForId(uas));
	if (mav)
	{
		qDebug() << "Set Origin";
		mavlink_message_t msg;
		mavlink_msg_ualberta_action_pack(uas, 0, &msg, UALBERTA_SET_ORIGIN, 0);
		mav->sendMessage(msg);
	}
#endif
}

void UAlbertaControlWidget::setUAS(UASInterface* uas)
{
	if (uas != 0)
	{
		UAlbertaMAV* mav = dynamic_cast<UAlbertaMAV*>(UASManager::instance()->getUASForId(this->uas));
		if (mav)
		{
			disconnect(mav, SIGNAL(servo_source(QString)), ui.servo_source_label, SLOT(setText(QString)));
			disconnect(mav, SIGNAL(controlMode(QString)), ui.control_mode_label, SLOT(setText(QString)));
			disconnect(mav, SIGNAL(pilotMode(QString)), ui.pilot_mode_label, SLOT(setText(QString)));
			disconnect(mav, SIGNAL(gx3Message(QString)), ui.gx3_message_label, SLOT(setText(QString)));
			disconnect(mav, SIGNAL(gx3Status(QString)), ui.gx3_state_label, SLOT(setText(QString)));
		}
	}

	UAlbertaMAV* mav = dynamic_cast<UAlbertaMAV*>(uas);
	if (mav)
	{
		connect(mav, SIGNAL(servoSource(QString)), ui.servo_source_label, SLOT(setText(QString)));
		connect(mav, SIGNAL(controlMode(QString)), ui.control_mode_label, SLOT(setText(QString)));
		connect(mav, SIGNAL(pilotMode(QString)), ui.pilot_mode_label, SLOT(setText(QString)));
		connect(mav, SIGNAL(gx3Message(QString)), ui.gx3_message_label, SLOT(setText(QString)));
		connect(mav, SIGNAL(gx3Status(QString)), ui.gx3_state_label, SLOT(setText(QString)));
	}

    this->uas = uas->getUASID();
}
