/*
 * CloserDbHelper.cpp
 *
 *  Created on: 2013-02-28
 *      Author: user
 */

#include "CloserDbHelper.h"

using namespace bb::data;

CloserDbHelper::CloserDbHelper() {
}

CloserDbHelper::~CloserDbHelper() {
	if (mDb.isOpen()) {
		QSqlDatabase::removeDatabase(mDbNameWithPath);
		mDb.removeDatabase("QSQLITE");
	}
}

bool CloserDbHelper::copyDbToDataFolder(const QString databaseName) {
	// First, we check to see if the file already exists in the
	// data folder (that is, the file was copied already).
	QString dataFolder = QDir::homePath();
	QString newFileName = dataFolder + "/" + databaseName;
	QFile newFile(newFileName);

	if (!newFile.exists()) {
		// If the file is not already in the data folder, we copy
		// it from the assets folder (read-only) to the data folder
		// (read-write).
		QString appFolder(QDir::homePath());
		appFolder.chop(4);
		QString originalFileName = appFolder + "app/native/assets/sql/"
				+ databaseName;
		QFile originalFile(originalFileName);

		if (originalFile.exists()) {
			return originalFile.copy(newFileName);
		} else {
			qDebug() << "Failed to copy file, database file does not exist.";
			return false;
		}
	}

	return true;
}

QVariantList CloserDbHelper::loadDataBase(const QString databaseName,
		const QString table) {
	QVariantList sqlData;

	if (copyDbToDataFolder(databaseName)) {
		// Load database entries using an SqlDataAccess object into a
		// QVariantList, which can be used in a GroupDataModel to
		// display a sorted list.
		mDbNameWithPath = "data/" + databaseName;

		// Set up an SqlDataAccess object.
		SqlDataAccess sqlDataAccess(mDbNameWithPath);

		// Set a query to obtain all entries in the table and load into
		// our QVariantList.
		sqlData = sqlDataAccess.execute("select * from " + table).value<
				QVariantList>();

		if (sqlDataAccess.hasError()) {
			DataAccessError err = sqlDataAccess.error();
			qWarning() << "SQL error: type=" << err.errorType() << ": "
					<< err.errorMessage();
			return sqlData;
		}

		//SECOND CONNECTION

		mDb = QSqlDatabase::addDatabase("QSQLITE",
				"database_helper_connection");
		mDb.setDatabaseName(mDbNameWithPath);

		if (!mDb.isValid()) {
			qWarning()
					<< "Could not set database name, probably due to an invalid driver.";
			return sqlData;
		}

		bool success = mDb.open();

		if (!success) {
			qWarning() << "Could not open database.";
			return sqlData;
		}

		// Store the name of the table (used in the insert/update/delete
		// functions).
		mTable = table;
	}

	return sqlData;
}

bool CloserDbHelper::deleteById(QVariant company, QVariant name,
		QVariant corporateTitle, QVariant email, QVariant phone,
		QVariant address, QVariant aboutMe) {
	// Query for deleting an entry in the table.
	if (company.canConvert(QVariant::String)
			&& name.canConvert(QVariant::String)
			&& corporateTitle.canConvert(QVariant::String)
			&& email.canConvert(QVariant::String)
			&& phone.canConvert(QVariant::String)
			&& address.canConvert(QVariant::String)
			&& aboutMe.canConvert(QVariant::String)) {
		QString query = "DELETE FROM " + mTable + " WHERE company='"
				+ company.toString() + "' AND name='" + name.toString()
				+ "' AND corporateTitle='" + corporateTitle.toString()
				+ "' AND email='" + email.toString() + "' AND address='"
				+ address.toString() + "' AND aboutMe='" + aboutMe.toString()
				+ "'";
		return queryDatabase(query);
	}

	qWarning() << "Failed to delete item: " << company;

	return false;
}

QVariant CloserDbHelper::insert(QVariantMap map) {

	QSqlQuery sqlQuery(mDb);
	//company varchar(30), name varchar(30), corporateTitle varchar(30), email varchar(60), phone varchar(30), address varchar(90), aboutMe varchar(120), linkedinProfile varchar(120));
	sqlQuery.prepare(
			"INSERT INTO " + mTable
					+ " (company, name, corporateTitle, email, phone, address, aboutMe, linkedinProfile, myCard)" " VALUES(:company, :name, :corporateTitle, :email, :phone, :address, :aboutMe, :linkedinProfile, :myCard)");

	sqlQuery.bindValue(":company", map["company"]);
	sqlQuery.bindValue(":name", map["name"]);
	sqlQuery.bindValue(":corporateTitle", map["corporateTitle"]);
	sqlQuery.bindValue(":email", map["email"]);
	sqlQuery.bindValue(":phone", map["phone"]);
	sqlQuery.bindValue(":address", map["address"]);
	sqlQuery.bindValue(":aboutMe", map["aboutMe"]);
	sqlQuery.bindValue(":linkedinProfile", map["linkedinProfile"]);
	//0 -> Card received
	//1 -> My card
	sqlQuery.bindValue(":myCard", map["myCard"]);
	sqlQuery.exec();

	QSqlError err = sqlQuery.lastError();

	if (err.isValid()) {
		qWarning() << "SQL reported an error : " << err.text();
	}

	return sqlQuery.lastInsertId();
}

bool CloserDbHelper::update(QVariantMap map, const QString &oldCompany,
		const QString &oldName, const QString &oldCorporateTitle,
		const QString &oldEmail, const QString &oldPhone,
		const QString &oldAddress, const QString &oldAboutMe,
		const QString &oldLinkedinProfile) {
	QSqlQuery sqlQuery(mDb);

//	sqlQuery.prepare("UPDATE " + mTable + " SET company=:company,name=:name,corporateTitle=:corporateTitle,email=:email,phone=:phone,address=:address,aboutMe=:aboutMe,linkedinProfile=:linkedinProfile,myCard=:myCard WHERE company=:oldCompany AND name=:oldName AND corporateTitle=:oldCorporateTitle AND email=:oldEmail AND phone=:oldPhone AND address=:oldAddress AND aboutMe=:oldAboutMe AND linkedinProfile=:oldLinkedinProfile AND myCard=:myCard");

	sqlQuery.prepare("UPDATE " + mTable + " SET company=:company, name=:name, corporateTitle=:corporateTitle, email=:email, phone=:phone, address=:address, aboutMe=:aboutMe WHERE company=:oldCompany AND name=:oldName AND corporateTitle=:oldCorporateTitle AND email=:oldEmail AND phone=:oldPhone AND address=:oldAddress AND aboutMe=:oldAboutMe");


	sqlQuery.bindValue(":company", map["company"]);
	sqlQuery.bindValue(":name", map["name"]);
	sqlQuery.bindValue(":corporateTitle", map["corporateTitle"]);
	sqlQuery.bindValue(":email", map["email"]);
	sqlQuery.bindValue(":phone", map["phone"]);
	sqlQuery.bindValue(":address", map["address"]);
	sqlQuery.bindValue(":aboutMe", map["aboutMe"]);
//	sqlQuery.bindValue(":linkedinProfile", map["linkedinProfile"]);
	sqlQuery.bindValue(":oldCompany", oldCompany);
	sqlQuery.bindValue(":oldName", oldName);
	sqlQuery.bindValue(":oldCorporateTitle", oldCorporateTitle);
	sqlQuery.bindValue(":oldEmail", oldEmail);
	sqlQuery.bindValue(":oldPhone", oldPhone);
	sqlQuery.bindValue(":oldAddress", oldAddress);
	sqlQuery.bindValue(":oldAboutMe", oldAboutMe);
//	sqlQuery.bindValue(":oldLinkedinProfile", oldLinkedinProfile);
//	sqlQuery.bindValue(":myCard", "1");
//	sqlQuery.bindValue(":id", map["id"].toString());
	sqlQuery.exec();

	qDebug() << sqlQuery.lastQuery();

	QSqlError err = sqlQuery.lastError();

	if (!err.isValid()) {
		return true;
	}

	qWarning() << "SQL reported an error : " << err.text();

	return false;
}

bool CloserDbHelper::queryDatabase(const QString query) {

	// Execute the query.
	QSqlQuery sqlQuery(query, mDb);

	QSqlError err = sqlQuery.lastError();

	if (err.isValid()) {
		qWarning() << "SQL reported an error for query: " << query << " error: "
				<< mDb.lastError().text();
		return false;
	}

	return true;
}
