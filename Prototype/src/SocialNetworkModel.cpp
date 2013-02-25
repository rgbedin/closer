/*
 * SocialNetworkModel.cpp
 *
 *  Created on: 14/02/2013
 *      Author: ricardo
 */

#include "SocialNetworkModel.h"

#include <bb/cascades/GroupDataModel>
#include <bb/cascades/ItemGrouping>
#include <iostream>

using namespace std;
using namespace bb::cascades;

SocialNetworkModel::SocialNetworkModel(QObject* parent)
	: QObject(parent)
	, m_model(new GroupDataModel(this))
	, m_currentAccountId(-1)
{
	// disable grouping in data model
	m_model->setGrouping(ItemGrouping::None);
	// populate the model
	initAccounts();
}

void SocialNetworkModel::selected(const QString &socialNetworkName)
{
	cout << "teste";
}

void SocialNetworkModel::initAccounts()
{
	const QList<SocialNetworkModel> accounts;
	// clear the old model
	m_model->clear();
	// manually creating the list of social networks
	// creates the entry
	QVariantMap entry;
	entry["accountId"] = 1;
	entry["name"] = QLatin1String("Facebook");
	entry["description"] = QLatin1String("Your Facebook profile");
	// add the entry to the model
	m_model->insert(entry);
}

bb::cascades::GroupDataModel* SocialNetworkModel::getModel()
{
	return m_model;
}
