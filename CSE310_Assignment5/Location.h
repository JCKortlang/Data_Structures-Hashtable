/*	Author: Jan Christian Chavez-Kortlang
*	Student ID: 1202073942
*	Class: CSE310 - Nakamura M/W @ 10:30am
*/
#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Location
{
public:
	Location();
	Location(string zipCode, string city, string state);
	string getZipCode();
	string getCity();
	string getState();
	void setZipCode(string zipCode);
	void setCity(string city);
	void setState(string state);
	void print();
	int compareTo(Location location);
private:
	string m_zipCode;
	string m_city;
	string m_state;
};
#endif
