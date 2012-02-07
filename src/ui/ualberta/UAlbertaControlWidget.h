/*=====================================================================

QGroundControl Open Source Ground Control Station

(c) 2009, 2010 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>

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

/**
 * @file
 *   @brief Definition of class UAlbertaControlWidget
 *
 *   @author Bryan Godbolt <godbolt@ece.ualberta.ca
 *
 */

#ifndef _UALBERTACONTROLWIDGET_H_
#define _UALBERTACONTROLWIDGET_H_

#include <QWidget>
#include <UASInterface.h>
#include <ui_UAlbertaControlWidget.h>

/**
 * @brief Widget controlling one MAV
 */
class UAlbertaControlWidget : public QWidget
{
    Q_OBJECT

public:
    UAlbertaControlWidget(QWidget *parent = 0);
    ~UAlbertaControlWidget();

public slots:
    /** @brief Set the system this widget controls */
    void setUAS(UASInterface* uas);
	void setServoSource();
	void setControlMode();
	void setOrigin();

protected:
    int uas;              ///< Reference to the current uas

private:
    Ui::UAlbertaControlWidget ui;

};

#endif
