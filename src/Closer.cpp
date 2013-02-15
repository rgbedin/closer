// Default empty project template
#include "Closer.hpp"

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

using namespace bb::cascades;
using namespace std;

AbstractPane *root;
Application *appObj;

Closer::Closer(bb::cascades::Application *app)
: QObject(app)
{
    // create scene document from main.qml asset
    // set parent to created document to ensure it exists for the whole application lifetime
    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);

    // creates a link with the QML file
    qml->setContextProperty("_closer", this);

    // create root object for the UI
    root = qml->createRootObject<AbstractPane>();
    // set created root object as a scene
    app->setScene(root);
    // saves a reference of the app object
    appObj = app;
}

void Closer::test(const QString &qmlString)
{
	// prints the received string to the standard output
	cout << qmlString.toUtf8().constData();
}

void Closer::addText(float posX, float posY)
{
	// create the text style
	TextStyle* textStyle = new TextStyle;
	textStyle->setFontSizeValue(15);
	textStyle->setColor(QVariant(Qt::white));
	// TODO: set the style to the text area
	// creates a text area object with background invisible
	TextArea* textArea = TextArea::create().backgroundVisible(false);
	// TODO: externalize this string
	textArea->setText("Tap to input text...");
	// sets the layout of the text (position)
	AbsoluteLayoutProperties* layout = AbsoluteLayoutProperties::create().position(posX, posY);
	textArea->setLayoutProperties(layout);
	// adds the text area to the scene
	Container* rootContainer = root->findChild<Container*>("rootContainer");
	rootContainer->add(textArea);
}

void Closer::setBackgroundImage()
{

}
