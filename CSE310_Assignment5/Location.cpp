/*	Author: Jan Christian Chavez-Kortlang
*	Student ID: 1202073942
*	Class: CSE310 - Nakamura M/W @ 10:30am
*/
#include "Location.h"

Location::Location(){};

Location::Location(string zipCode, string city, string state)
{
	m_zipCode = zipCode;
	m_city = city;
	m_state = state;
}

string Location::getZipCode()
{
	return m_zipCode;
}

string Location::getCity()
{
	return m_city;
}

string Location::getState()
{
	return m_state;
}

void Location::setZipCode(string zipCode)
{
	m_zipCode = zipCode;
}

void Location::setCity(string city)
{
	m_city = city;
}

void Location::setState(string state)
{
	m_state = state;
}

void Location::print()
{
	cout << m_zipCode << "\t" << m_city << "\t" << m_state << endl;
}
/*
	Will return 0 if the Locations have equal values.
*/
int Location::compareTo(Location location)
{
	return m_zipCode.compare(location.getZipCode()) + m_city.compare(location.getCity()) + m_state.compare(location.getState());
}
