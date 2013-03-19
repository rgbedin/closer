/*
 * SQLPersistence.h
 *
 *  Created on: 11/03/2013
 *      Author: ricardo
 */

#ifndef SQLPERSISTENCE_H_
#define SQLPERSISTENCE_H_

#include "IPersistence.h"
#include <QtSql/QtSql>
#include <bb/data/SqlDataAccess>

class SQLPersistence : public IPersistence {
private:
	QSqlDatabase mDb;
	QString mTable;
	QString mDbNameWithPath;

	SQLPersistence(); // constructor must be private
	bool copyDbToDataFolder(const QString databaseName);
	QVariantList loadDataBase(const QString databaseName, const QString table);
public:
	static SQLPersistence& getInstance() {
		static SQLPersistence instance;
		return instance;
	}

	virtual void addNewCard(Card &card);
	virtual void updateCard(Card &oldCard, Card &updatedCard);
	virtual void deleteCard(Card &card);
	virtual QVariantList loadAllCards();

	virtual ~SQLPersistence();
};

#endif /* SQLPERSISTENCE_H_ */
