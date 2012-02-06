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

//#include <QString>
//#include <QTimer>
//#include <QLabel>
//#include <QFileDialog>
//#include <QDebug>
//#include <QProcess>
//#include <QPalette>


//#include <UASManager.h>
//#include <UAS.h>
//#include "QGC.h"

UAlbertaControlWidget::UAlbertaControlWidget(QWidget *parent) :
	QWidget(parent),
    uas(0),
    uasMode(0)
{
	ui.setupUi(this);



}

void UAlbertaControlWidget::setUAS(UASInterface* uas)
{
//    if (this->uas != 0)
//    {
//        UASInterface* oldUAS = UASManager::instance()->getUASForId(this->uas);
//        disconnect(ui.controlButton, SIGNAL(clicked()), oldUAS, SLOT(armSystem()));
//        disconnect(ui.liftoffButton, SIGNAL(clicked()), oldUAS, SLOT(launch()));
//        disconnect(ui.landButton, SIGNAL(clicked()), oldUAS, SLOT(home()));
//        disconnect(ui.shutdownButton, SIGNAL(clicked()), oldUAS, SLOT(shutdown()));
//        //connect(ui.setHomeButton, SIGNAL(clicked()), uas, SLOT(setLocalOriginAtCurrentGPSPosition()));
//        disconnect(uas, SIGNAL(modeChanged(int,QString,QString)), this, SLOT(updateMode(int,QString,QString)));
//        disconnect(uas, SIGNAL(statusChanged(int)), this, SLOT(updateState(int)));
//    }
//
//    // Connect user interface controls
//    connect(ui.controlButton, SIGNAL(clicked()), this, SLOT(cycleContextButton()));
//    connect(ui.liftoffButton, SIGNAL(clicked()), uas, SLOT(launch()));
//    connect(ui.landButton, SIGNAL(clicked()), uas, SLOT(home()));
//    connect(ui.shutdownButton, SIGNAL(clicked()), uas, SLOT(shutdown()));
//    //connect(ui.setHomeButton, SIGNAL(clicked()), uas, SLOT(setLocalOriginAtCurrentGPSPosition()));
//    connect(uas, SIGNAL(modeChanged(int,QString,QString)), this, SLOT(updateMode(int,QString,QString)));
//    connect(uas, SIGNAL(statusChanged(int)), this, SLOT(updateState(int)));
//
//    ui.controlStatusLabel->setText(tr("Connected to ") + uas->getUASName());
//
//    this->uas = uas->getUASID();
//    setBackgroundColor(uas->getColor());
}

UAlbertaControlWidget::~UAlbertaControlWidget()
{

}



/**
 * Set the background color based on the MAV color. If the MAV is selected as the
 * currently actively controlled system, the frame color is highlighted
 */
void UAlbertaControlWidget::setBackgroundColor(QColor color)
{
    // UAS color
//    QColor uasColor = color;
//    QString colorstyle;
//    QString borderColor = "#4A4A4F";
//    borderColor = "#FA4A4F";
//    uasColor = uasColor.darker(900);
//    colorstyle = colorstyle.sprintf("QLabel { border-radius: 3px; padding: 0px; margin: 0px; background-color: #%02X%02X%02X; border: 0px solid %s; }",
//                                    uasColor.red(), uasColor.green(), uasColor.blue(), borderColor.toStdString().c_str());
//    setStyleSheet(colorstyle);
//    QPalette palette = this->palette();
//    palette.setBrush(QPalette::Window, QBrush(uasColor));
//    setPalette(palette);
//    setAutoFillBackground(true);
}
