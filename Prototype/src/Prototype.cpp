// Tabbed pane project template
#include "Prototype.hpp"

#include <iostream>
#include <fstream>

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/TextArea>
#include <bb/cascades/Page>
#include <bb/cascades/Container>
#include <bb/cascades/LayoutProperties>
#include <bb/cascades/AbsoluteLayoutProperties>
#include <bb/cascades/TextStyle>
#include <bb/cascades/ColorPaint>
#include <bb/data/XmlDataAccess>

#include <QVariant>


#include <SocialNetworkModel.h>

using namespace bb::cascades;
using namespace bb::data;
using namespace std;

AbstractPane *root;
Application *appObj;

using namespace bb::cascades;

Prototype::Prototype(bb::cascades::Application *app)
: QObject(app)
{
    // create scene document from main.qml asset
    // set parent to created document to ensure it exists for the whole application lifetime
    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);

    // creates a link with the QML file
    qml->setContextProperty("_closer", this);
    qml->setContextProperty("_socialNetworkModel", new SocialNetworkModel(app));

    // create root object for the UI
    root = qml->createRootObject<AbstractPane>();
    // set created root object as a scene
    app->setScene(root);
    // saves a reference of the app object
    appObj = app;
}

void Prototype::writeXML(const QString &name, const QString &email, const QString &title, const QString &picture)
{
	//QObject *newButton = root->findChild<QObject*>("doneButton");
	//newButton->setProperty("text", name);

	QVariantMap card;
	card["name"] = QVariant(name);
	card["email"] = QVariant(email);
	card["title"] = QVariant(title);
	card["backGroundImageAddress"] = QVariant("address");

	QVariantList myCardList = QVariantList() << QVariant(card);

	QVariantMap topLevelCardMap;
	topLevelCardMap[".root"] = QVariant("cards");
	topLevelCardMap["card"] = QVariant(myCardList);
	QVariant myData = QVariant(topLevelCardMap);

	QDir home = QDir::home();
	QTemporaryFile file(home.absoluteFilePath("models/mycards.xml"));

	if (file.open()) {
	    // Create an XmlDataAccess object and save the data to the file
	    XmlDataAccess xda;
	    xda.save(myData, &file);
	} else {

		QObject *newButton = root->findChild<QObject*>("doneButton");
			newButton->setProperty("text", name);
	}

}

void Prototype::writeJSON(const QString &name, const QString &email, const QString &title, const QString &picture)
{
	QObject *newButton = root->findChild<QObject*>("doneButton");
	newButton->setProperty("text", name);

	// Create QVariantMap objects to contain the data for each employee
	QVariantMap card;
	card["name"] = QVariant(name);
	card["email"] = QVariant(email);
	card["title"] = QVariant(title);
	card["backGroundImageAddress"] = QVariant("address");

		QVariantList myCardList = QVariantList() << QVariant(card);

	// Retrieve the working directory, and create a temporary .json file in that
	// location
	QDir home = QDir::home();
	QTemporaryFile file(home.absoluteFilePath("myJSONFile.json"));

	// Open the file that was created
	if (file.open()) {
	    // Create a JsonDataAccess object and save the data to the file
	    JsonDataAccess jda;
	    jda.save(myCardList, &file);
	}
}
void Prototype::showSocialNetworkPicker()
{
	// TODO
}
