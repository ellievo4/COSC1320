//COSC 1320 Summer 2015
//Thanh Vo
//Programming Assignment 4
//This is my own work, I will not post

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "Video.h"
using namespace std;

class Customer
{
private:
	string firstName;		//track customer's first name
	string lastName;		//track customer's last name
	int id;					//track customer's id

public:
	Customer();
	void setFirstName(string first);
	string getFirstName();
	void setLastName(string last);
	string getLastName();
	void setID(int num);
	int getID();
	string toString();
	friend ostream& operator << (ostream& outputStream, const Customer& cus1);
};
#endif