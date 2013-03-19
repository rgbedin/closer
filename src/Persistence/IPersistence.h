/*
 * IPersistence.h
 *
 *  Created on: 11/03/2013
 *      Author: ricardo
 */

#ifndef IPERSISTENCE_H_
#define IPERSISTENCE_H_

#include "Card.h"

class IPersistence {
public:
	IPersistence(){}
	// persistence-related methods
	virtual void addNewCard(Card &card) = 0;
	virtual void updateCard(Card &oldCard, Card &updatedCard) = 0;
	virtual void deleteCard(Card &card) = 0;
	virtual QVariantList loadAllCards() = 0;

	// others
	virtual ~IPersistence(){}
};

#endif /* IPERSISTENCE_H_ */
