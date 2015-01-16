/*	Author: Jan Christian Chavez-Kortlang
*	Student ID: 1202073942
*	Class: CSE310 - Nakamura M/W @ 10:30am
*/
#include "LocationNode.h"

LocationNode::LocationNode()
{
	m_nodeCollisionCount = 0;
}; 

LocationNode::LocationNode(string zipCode, string city, string state)
{
	LocationNode();
	m_location.setZipCode(zipCode);
	m_location.setCity(city);
	m_location.setState(state);
};

int LocationNode::getCollisionCount()
{
	return m_nodeCollisionCount;
};

void LocationNode::recordCollision()
{
	m_nodeCollisionCount++;
};

/*
	Returns true if all of the Location object's strings are empty.
*/
bool LocationNode::isEmpty()
{
	return m_location.getZipCode().empty() && m_location.getCity().empty() && m_location.getState().empty();
}

Location* LocationNode::getLocation()
{
	return &m_location;
}

void LocationNode::print()
{
	if (m_location.getZipCode().empty())
		cout << "None\t\t";
	else
		cout << m_location.getZipCode() << "\t\t";

	if (m_location.getCity().empty())
		cout << "None\t\t";
	else
		cout << m_location.getCity() << "\t\t";

	if (m_location.getState().empty())
		cout << "None\t\t";
	else
		cout << m_location.getState() << "\t\t";

	cout << m_nodeCollisionCount << endl;
}
