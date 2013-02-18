#include "CuteSettings.h"

CuteSettings::CuteSettings(QObject* parent)
	: realSettings(new QSettings(parent))
{ }

CuteSettings::~CuteSettings() {
	realSettings->deleteLater();
}

void CuteSettings::setValue(const QString& key, const QVariant& value) {
	realSettings->setValue(key, value);
}

QVariant CuteSettings::value(const QString& key, const QVariant& defaultValue) const {
	return(realSettings->value(key, defaultValue));
}
