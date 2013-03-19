/*
 * Card.h
 *
 *  Created on: 11/03/2013
 *      Author: ricardo
 */

#ifndef CARD_H_
#define CARD_H_

#include <bb/cascades/Application>
#include <bb/cascades/DataModel>
#include <bb/data/SqlDataAccess>
#include <QObject>

class Card {
private:
	QString _company;
	QString _name;
	QString _corporateTitle;
	QString _email;
	QString _phone;
	QString _address;
	QString _aboutMe;
	QString _linkedinProfile;

public:
	Card(); // default constructor

	// constructors
	Card(const QString &company, const QString &name,
		const QString &corporateTitle, const QString &email,
		const QString &phone, const QString &address, const QString &aboutMe,
		const QString &linkedinProfile);
	Card(QVariantMap map);

	// helpers
	QVariantMap toQVariantMap();

	virtual ~Card();

	// getters and setters

	QString getAboutMe() const { return _aboutMe; }
	void setAboutMe(QString aboutMe) { _aboutMe = aboutMe; }

	QString getAddress() const { return _address; }
	void setAddress(QString address) { _address = address; }

	QString getCompany() const { return _company; }
	void setCompany(QString company) { _company = company; }

	QString getCorporateTitle() const { return _corporateTitle; }
	void setCorporateTitle(QString corporateTitle) { _corporateTitle = corporateTitle; }

	QString getEmail() const { return _email; }
	void setEmail(QString email) { _email = email; }

	QString getLinkedinProfile() const { return _linkedinProfile; }
	void setLinkedinProfile(QString linkedinProfile) { _linkedinProfile = linkedinProfile; }

	QString getName() const { return _name; }
	void setName(QString name) { _name = name; }

	QString getPhone() const { return _phone; }
	void setPhone(QString phone) { _phone = phone; }
};

#endif /* CARD_H_ */
