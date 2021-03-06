/*
 *
 *  Copyright (c) 2013
 *  name : mhogo mchungu
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONFIGURATIONOPTIONSDIALOG_H
#define CONFIGURATIONOPTIONSDIALOG_H

#include <QString>
#include <QFile>
#include <QDir>
#include <QDialog>
#include <QCloseEvent>
#include <QMessageBox>

#include <kstandarddirs.h>

#include "language_path.h"

namespace Ui {
class configurationoptionsdialog;
}

class configurationoptionsdialog : public QDialog
{
	Q_OBJECT
public:
	explicit configurationoptionsdialog( QWidget * parent = 0 );
	static QString getConfigPath( void ) ;
	static bool autoStartEnabled( void ) ;
	static void enableAutoStart( void ) ;
	static void disableAutoStart( void ) ;
	static bool reportOnAllAccounts( void ) ;
	static QString localLanguage( void ) ;
	static QString localLanguagePath( void ) ;
	static int getTimeFromConfigFile( void ) ;
	void ShowUI( void ) ;
	void HideUI( void ) ;
	~configurationoptionsdialog();
signals:
	void setTimer( int ) ;
private slots:
	void pushButtonClose( void ) ;
private:
	void reportOnAllAccounts( bool ) ;
	void saveTimeToConfigFile( void ) ;
	void setSupportedLanguages( void ) ;
	void saveLocalLanguage( void ) ;
	void closeEvent( QCloseEvent * ) ;
	Ui::configurationoptionsdialog * m_ui;
};

#endif // CONFIGURATIONOPTIONSDIALOG_H
