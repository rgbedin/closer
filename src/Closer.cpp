#include "Closer.hpp"
//#include "closerDbHelper.h"

#include <bb/cascades/GroupDataModel>
#include <bb/cascades/ListView>
#include <bb/cascades/NavigationPane>
#include <bb/cascades/QmlDocument>
//#include <bb/cascades/AbstractPane>
//#include <bb/cascades/Application>
//#include <bb/cascades/QmlDocument>

using namespace bb::cascades;

Closer::Closer() {
}

Closer::~Closer() {
	delete closerDbHelper;
}

void Closer::onStart() {
	closerDbHelper = new CloserDbHelper();

	if (!loadQMLScene()) {
		qWarning("Failed to load QML scene.");
	}
}

bool Closer::loadQMLScene() {

	QmlDocument *qmlDocument = QmlDocument::create("asset:///main.qml");

	if (!qmlDocument->hasErrors()) {
		qmlDocument->setContextProperty("_closer", this);

		navigationPane = qmlDocument->createRootObject<NavigationPane>();

		QObject::connect(navigationPane, SIGNAL(share()), this, SLOT(share()));

		if (navigationPane) {

			if (loadFromDb()) {
				Application::instance()->setScene(navigationPane);
				return true;
			}
		}
	}

	return false;
}

bool Closer::loadFromDb() {

	QVariantList sqlData = closerDbHelper->loadDataBase("cards.db", "cards");

	qDebug() << sqlData;

	if (!sqlData.isEmpty()) {

		cardsModel = navigationPane->findChild<GroupDataModel*>("cardsModel");

		cardsModel->clear();

		cardsModel->insertList(sqlData);

		cardsListView = navigationPane->findChild<ListView*>(
				"cardsReceivedList");
	}

//	Application::instance()->setScene(navigationPane);
	return true;
}

//company varchar(30), name varchar(30), corporateTitle varchar(30), email varchar(60), phone varchar(30), address varchar(90), aboutMe varchar(120), linkedinProfile varchar(120));
void Closer::addNewRecord(const QString &company, const QString &name,
		const QString &corporateTitle, const QString &email,
		const QString &phone, const QString &address, const QString &aboutMe,
		const QString &linkedinProfile) {

	QVariantMap map;
	map["company"] = QString(company);
	map["name"] = QString(name);
	map["corporateTitle"] = QString(corporateTitle);
	map["email"] = QString(email);
	map["phone"] = QString(phone);
	map["address"] = QString(address);
	map["aboutMe"] = QString(aboutMe);
	map["linkedinProfile"] = QString(linkedinProfile);
	//0 -> Card received
	//1 -> My card
	map["myCard"] = QString("1");

//	QVariant insertId = closerDbHelper->insert(map);
//
//	if (!insertId.isNull()) {
//		map["id"] = insertId;
//		cardsModel->insert(map);
//	}

	closerDbHelper->insert(map);
	loadFromDb();
//	navigationPane->pop();

}

void Closer::updateSelectedRecord(const QString &company, const QString &name,
		const QString &corporateTitle, const QString &email,
		const QString &phone, const QString &address, const QString &aboutMe,
		const QString &linkedinProfile, const QString &oldCompany,
		const QString &oldName, const QString &oldCorporateTitle,
		const QString &oldEmail, const QString &oldPhone,
		const QString &oldAddress, const QString &oldAboutMe,
		const QString &oldLinkedinProfile) {

	QVariantList indexPath = cardsListView->selected();

	if (!indexPath.isEmpty()) {

		QVariantMap itemMapAtIndex = cardsModel->data(indexPath).toMap();

		itemMapAtIndex["company"] = QString(company);
		itemMapAtIndex["name"] = QString(name);
		itemMapAtIndex["corporateTitle"] = QString(corporateTitle);
		itemMapAtIndex["email"] = QString(email);
		itemMapAtIndex["phone"] = QString(phone);
		itemMapAtIndex["address"] = QString(address);
		itemMapAtIndex["aboutMe"] = QString(aboutMe);
		itemMapAtIndex["linkedinProfile"] = QString(linkedinProfile);

		closerDbHelper->update(itemMapAtIndex, oldCompany, oldName,
				oldCorporateTitle, oldEmail, oldPhone, oldAddress, oldAboutMe,
				oldLinkedinProfile);
		cardsModel->updateItem(indexPath, itemMapAtIndex);

		navigationPane->pop();
	}
}

void Closer::deleteRecord() {

	QVariantList indexPath = cardsListView->selected();

	qDebug() << indexPath;
	qDebug() << cardsModel->data(indexPath);

	if (!indexPath.isEmpty()) {

		QVariantMap map = cardsModel->data(indexPath).toMap();

		qDebug() << map["name"].toString();

		//map["linkedinProfile"]
		if (closerDbHelper->deleteById(map["company"], map["name"],
				map["corporateTitle"], map["email"], map["phone"],
				map["address"], map["aboutMe"])) {

			cardsModel->remove(map);
			loadFromDb();
		}
//		} //end of inner if statement
	} // end of outer if statement
} // end of deleteRecord()

void Closer::popNavigationPane() {
	navigationPane->pop();
}

void Closer::share(QString message) {

	_nfcShareManager = new NfcShareManager();

	qDebug() << "XXXX shareContentChanged message : " << message << endl;

	NfcShareDataContent request;
	QByteArray data(message.toUtf8());
	QUrl url;
	request.setUri(url);
	request.setMimeType("text/plain");
	request.setData(data);
	NfcShareSetContentError::Type rc = _nfcShareManager->setShareContent(request);
	qDebug() << "XXXX shareContentChanged rc =" << rc << endl;
}

