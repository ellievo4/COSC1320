//COSC 1320 Summer 2015
//Thanh Vo
//Programming Assignment 4
//This is my own work, I will not post

#include<string>
#include"Customer.h"
#include "Video.h"
using namespace std;

//-------------------------------
//initialize all member variables in this class
//-------------------------------
Customer::Customer()
	:firstName("none"), lastName("none"), id(0) {}

//-------------------------------
//set the first name of customer
//-------------------------------
void Customer::setFirstName(string first)
{
	firstName = first;
}

//-------------------------------
//get customer's first name
//-------------------------------
string Customer::getFirstName()
{
	return firstName;
}

//-------------------------------
//set the customer's last name
//-------------------------------
void Customer::setLastName(string last)
{
	lastName = last;
}

//-------------------------------
//get the customer's last name
//-------------------------------
string Customer::getLastName()
{
	return lastName;
}

//-------------------------------
//set the customer's id
//-------------------------------
void Customer::setID(int num)
{
	id = num;
}

//-------------------------------
//get the customer's id
//-------------------------------
int Customer::getID()
{
	return id;
}

//-------------------------------
//return a string of first and last name
//-------------------------------
string Customer::toString()
{
	return (firstName + ", " + lastName + ", ");
}

//-------------------------------
//opearator for printing customer's id to screen
//-------------------------------
ostream& operator << (ostream& outputStream, const Customer& cus1)
{
	outputStream << cus1.id;
	return outputStream;
}