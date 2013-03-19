/*
 * Card.cpp
 *
 *  Created on: 11/03/2013
 *      Author: ricardo
 */

#include "Card.h"

Card::Card(const QString &company, const QString &name,
		const QString &corporateTitle, const QString &email,
		const QString &phone, const QString &address, const QString &aboutMe,
		const QString &linkedinProfile)
{
	// saves reference to all arguments and class properties
	_company = company;
	_name = name;
	_corporateTitle = corporateTitle;
	_email = email;
	_phone = phone;
	_address = address;
	_aboutMe = aboutMe;
	_linkedinProfile = linkedinProfile;
}

Card::Card(QVariantMap map)
{
	Card(map["company"].toString(), map["name"].toString(),
			map["corporateTitle"].toString(), map["email"].toString(),
			map["phone"].toString(), map["address"].toString(), map["aboutMe"].toString(),
			map["linkedinProfile"].toString());
}

QVariantMap Card::toQVariantMap()
{
	QVariantMap map;
	map["company"] = QString(_company);
	map["name"] = QString(_name);
	map["corporateTitle"] = QString(_corporateTitle);
	map["email"] = QString(_email);
	map["phone"] = QString(_phone);
	map["address"] = QString(_address);
	map["aboutMe"] = QString(_aboutMe);
	map["linkedinProfile"] = QString(_linkedinProfile);
	// 0 -> Card received
	// 1 -> My card
	map["myCard"] = QString("1");
	return map;
}

Card::Card()
{
	// TODO Auto-generated constructor stub
}

Card::~Card()
{
	// TODO Auto-generated destructor stub
}

