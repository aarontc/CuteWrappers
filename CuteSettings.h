#ifndef CUTESETTINGS_H
#define CUTESETTINGS_H

#include <QSettings>

class CuteSettings : public QSettings
{
public:
	CuteSettings();
	virtual ~CuteSettings();
	virtual void setValue(const QString& key, const QVariant& value);
	virtual QVariant value(const QString& key, const QVariant& defaultValue = QVariant()) const;

private:
	QSettings* realSettings;
};

#endif // CUTESETTINGS_H
