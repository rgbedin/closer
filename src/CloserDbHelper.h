/*
 * CloserDbHelper.h
 *
 *  Created on: 2013-02-28
 *      Author: user
 */

#ifndef CLOSERDBHELPER_H_
#define CLOSERDBHELPER_H_

#include <QtSql/QtSql>
#include <bb/data/SqlDataAccess>

using namespace bb::data;

class CloserDbHelper {
public:
	CloserDbHelper();
	~CloserDbHelper();

	QVariantList loadDataBase(const QString databaseName, const QString table);
	bool deleteById(QVariant company, QVariant name, QVariant corporateTitle,
			QVariant email, QVariant phone, QVariant address, QVariant aboutMe);
	QVariant insert(QVariantMap map);
	bool update(QVariantMap map, const QString &oldCompany,
			const QString &oldName, const QString &oldCorporateTitle,
			const QString &olderEmail, const QString &olderPhone,
			const QString &olderAddress, const QString &olderAboutMe,
			const QString &olderLinkedinProfile);

private:
	bool copyDbToDataFolder(const QString databaseName);
	bool queryDatabase(const QString query);

	QSqlDatabase mDb;
	QString mTable;
	QString mDbNameWithPath;
};

#endif /* CLOSERDBHELPER_H_ */
