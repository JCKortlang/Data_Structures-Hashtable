/*	Author: Jan Christian Chavez-Kortlang
*	Student ID: 1202073942
*	Class: CSE310 - Nakamura M/W @ 10:30am
*/

#ifndef LOCATIONNODE_H
#define LOCATIONNODE_H

#include "Location.h"

class LocationNode
{
public:
	LocationNode();
	LocationNode(string zipCode, string city, string state);
	Location* getLocation();
	int getCollisionCount();
	void recordCollision();
	bool isEmpty();
	void print();
private:
	int m_nodeCollisionCount;
	Location m_location;
};

#endif
