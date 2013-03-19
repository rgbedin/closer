/*
 * SQLPersistence.cpp
 *
 *  Created on: 11/03/2013
 *      Author: ricardo
 */

#include "SQLPersistence.h"

using namespace bb::data;

SQLPersistence::SQLPersistence() {
}

SQLPersistence::~SQLPersistence() {
	if (mDb.isOpen()) {
			QSqlDatabase::removeDatabase(mDbNameWithPath);
			mDb.removeDatabase("QSQLITE");
	}
}

void SQLPersistence::addNewCard(Card &card)
{
	// creates the variant map that will be added to the database
	QVariantMap map;

	// sets the fields
	map["company"] = QString(card.getCompany());
	map["name"] = QString(card.getName());
	map["corporateTitle"] = QString(card.getCorporateTitle());
	map["email"] = QString(card.getEmail());
	map["phone"] = QString(card.getPhone());
	map["address"] = QString(card.getAddress());
	map["aboutMe"] = QString(card.getAboutMe());
	map["linkedinProfile"] = QString(card.getLinkedinProfile());

	// 0 -> Card received
	// 1 -> My card
	map["myCard"] = QString("1");

	// prepares the query going to be executed
	QSqlQuery sqlQuery(mDb);
	sqlQuery.prepare(
			"INSERT INTO " + mTable
					+ " (company, name, corporateTitle, email, phone, address, aboutMe, linkedinProfile, myCard)" " VALUES(:company, :name, :corporateTitle, :email, :phone, :address, :aboutMe, :linkedinProfile, :myCard)");

	// binds the values to the query
	sqlQuery.bindValue(":company", map["company"]);
	sqlQuery.bindValue(":name", map["name"]);
	sqlQuery.bindValue(":corporateTitle", map["corporateTitle"]);
	sqlQuery.bindValue(":email", map["email"]);
	sqlQuery.bindValue(":phone", map["phone"]);
	sqlQuery.bindValue(":address", map["address"]);
	sqlQuery.bindValue(":aboutMe", map["aboutMe"]);
	sqlQuery.bindValue(":linkedinProfile", map["linkedinProfile"]);
	sqlQuery.bindValue(":myCard", map["myCard"]);

	// executes the query
	sqlQuery.exec();

	// checks for errors
	QSqlError err = sqlQuery.lastError();
	if (err.isValid()) {
		qWarning() << "SQL reported an error : " << err.text();
	}
}

void SQLPersistence::updateCard(Card &oldCard, Card &updatedCard)
{
	// creates the query
	QSqlQuery sqlQuery(mDb);
	sqlQuery.prepare("UPDATE " + mTable + " SET company=:company, name=:name, corporateTitle=:corporateTitle, email=:email, phone=:phone, address=:address, aboutMe=:aboutMe WHERE company=:oldCompany AND name=:oldName AND corporateTitle=:oldCorporateTitle AND email=:oldEmail AND phone=:oldPhone AND address=:oldAddress AND aboutMe=:oldAboutMe");

	// gets the old card and updated card as maps
	QVariantMap map = updatedCard.toQVariantMap();
	QVariantMap oldMap = oldCard.toQVariantMap();

	// binds the updated card values
	sqlQuery.bindValue(":company", map["company"]);
	sqlQuery.bindValue(":name", map["name"]);
	sqlQuery.bindValue(":corporateTitle", map["corporateTitle"]);
	sqlQuery.bindValue(":email", map["email"]);
	sqlQuery.bindValue(":phone", map["phone"]);
	sqlQuery.bindValue(":address", map["address"]);
	sqlQuery.bindValue(":aboutMe", map["aboutMe"]);
//	sqlQuery.bindValue(":linkedinProfile", map["linkedinProfile"]);

	// binds the old card values
	sqlQuery.bindValue(":oldCompany", oldMap["company"]);
	sqlQuery.bindValue(":oldName", oldMap["name"]);
	sqlQuery.bindValue(":oldCorporateTitle", oldMap["corporateTitle"]);
	sqlQuery.bindValue(":oldEmail", oldMap["email"]);
	sqlQuery.bindValue(":oldPhone", oldMap["phone"]);
	sqlQuery.bindValue(":oldAddress", oldMap["address"]);
	sqlQuery.bindValue(":oldAboutMe", oldMap["aboutMe"]);
//	sqlQuery.bindValue(":oldLinkedinProfile", oldMap["linkedinProfile"]);
//	sqlQuery.bindValue(":myCard", "1");

	// executes the query
	sqlQuery.exec();

	// debug info
	qDebug() << sqlQuery.lastQuery();

	// checks for errors
	QSqlError err = sqlQuery.lastError();
	if (err.isValid()) {
		qWarning() << "SQL reported an error : " << err.text();
	}
}

void SQLPersistence::deleteCard(Card &card)
{
	// creates the query
	QString query = "DELETE FROM " + mTable + " WHERE company='"
					+ card.getCompany() + "' AND name='" + card.getName()
					+ "' AND corporateTitle='" + card.getCorporateTitle()
					+ "' AND email='" + card.getEmail() + "' AND address='"
					+ card.getAddress() + "' AND aboutMe='" + card.getAboutMe()
					+ "'";

	// executes the query
	QSqlQuery sqlQuery(query, mDb);

	QSqlError err = sqlQuery.lastError();

	if (err.isValid()) {
		qWarning() << "SQL reported an error for query: " << query << " error: "
				<< mDb.lastError().text();
	}

}

QVariantList SQLPersistence::loadAllCards()
{
	return loadDataBase("cards.db", "cards");
}

bool SQLPersistence::copyDbToDataFolder(const QString databaseName) {
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

QVariantList SQLPersistence::loadDataBase(const QString databaseName, const QString table)
{
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

		// Second connection

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
