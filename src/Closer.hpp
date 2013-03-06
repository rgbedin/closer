// Tabbed pane project template
#ifndef Prototype_HPP_
#define Prototype_HPP_

#include <bb/cascades/Application>
#include <bb/cascades/DataModel>
#include <bb/data/SqlDataAccess>
#include <QObject>

#include <bb/system/NfcShareManager>

#include "CloserDbHelper.h"

using namespace bb::cascades;
using namespace bb::data;
using namespace bb::system;

namespace bb {
namespace cascades {
class GroupDataModel;
class ListView;
class NavigationPane;
}
}

//class CloserDbHelper;

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class Closer: public QObject {
Q_OBJECT
public:
	Closer();
	~Closer();

	void onStart();

	bool loadFromDb();

	Q_INVOKABLE
	void addNewRecord(const QString &company, const QString &name,
			const QString &corporateTitle, const QString &email,
			const QString &phone, const QString &address,
			const QString &aboutMe, const QString &linkedinProfile);

	Q_INVOKABLE
	void updateSelectedRecord(const QString &company, const QString &name,
			const QString &corporateTitle, const QString &email,
			const QString &phone, const QString &address,
			const QString &aboutMe, const QString &linkedinProfile,
			const QString &oldCompany, const QString &oldName,
			const QString &oldCorporateTitle, const QString &oldEmail,
			const QString &oldPhone, const QString &oldAddress,
			const QString &oldAboutMe, const QString &oldLinkedinProfile);

	Q_INVOKABLE
	void deleteRecord();

	Q_INVOKABLE
	void popNavigationPane();

	bool loadQMLScene();

	CloserDbHelper *closerDbHelper;
	GroupDataModel *cardsModel;
	ListView *cardsListView;
	NavigationPane *navigationPane;

public slots:
	void share(QString message);

private:
	NfcShareManager *_nfcShareManager;
};

#endif /* Prototype_HPP_ */
