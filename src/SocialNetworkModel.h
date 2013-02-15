/*
 * SocialNetworkModel.h
 *
 *  Created on: 14/02/2013
 *      Author: ricardo
 */

#ifndef SOCIALNETWORKMODEL_H_
#define SOCIALNETWORKMODEL_H_

#include <QObject>
#include <bb/cascades/GroupDataModel>

class SocialNetworkModel : public QObject
{
	Q_OBJECT

	// the model
	Q_PROPERTY(bb::cascades::GroupDataModel* model READ getModel CONSTANT);

public:
	SocialNetworkModel(QObject* parent = 0);
	bb::cascades::GroupDataModel* getModel();

public Q_SLOTS:
	void selected(const QString &socialNetworkName);
    void initAccounts();

private:
	// the accessor methods of the properties
	bb::cascades::GroupDataModel* model() const;

	// the property values
	bb::cascades::GroupDataModel* m_model;

	// The ID of the current account
	long m_currentAccountId;
};

#endif /* SOCIALNETWORKMODEL_H_ */
