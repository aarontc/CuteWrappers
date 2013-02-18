/****************************************************************************************

	This file is part of CuteWrappers.
	Copyright © 2010, 2012 Aaron Ten Clay <aarontc@aarontc.com>

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

****************************************************************************************/

#ifndef CUTESETTINGS_H
#define CUTESETTINGS_H

#include <QSettings>

class CuteSettings : public QSettings {
	Q_OBJECT

	public:
		CuteSettings(QObject* parent = 0);
		virtual ~CuteSettings();
		virtual void setValue(const QString& key, const QVariant& value);
		virtual QVariant value(const QString& key, const QVariant& defaultValue = QVariant()) const;

	private:
		QSettings* realSettings;
};

#endif // CUTESETTINGS_H
