//COSC 1320 Summer 2015
//Thanh Vo
//Programming Assignment 4
//This is my own work, I will not post

#include <string>
#include "RentedVideo.h"
using namespace std;

//---------------------------------
//initialize member variables in this class
//---------------------------------
RentedVideo::RentedVideo()
	: renterFirstName("none"), renterLastName("none"), renterID(0), vidTitle1("none"), vidTitle2("none") {}

//---------------------------------
//set first name of renter
//---------------------------------
void RentedVideo::setRenterFirstName(string first)
{
	renterFirstName = first;
}

//---------------------------------
//get first name of renter
//---------------------------------
string RentedVideo::getRenterFirstName() 
{
	return renterFirstName;
}

//---------------------------------
//set last name of renter
//---------------------------------
void RentedVideo::setRenterLastName(string last)
{
	renterLastName = last;
}

//---------------------------------
//get last name of renter
//---------------------------------
string RentedVideo::getRenterLastName() 
{
	return renterLastName;
}

//---------------------------------
//set renter ID
//---------------------------------
void RentedVideo::setRenterID(int id)
{
	renterID = id;
}

//---------------------------------
//get renter ID
//---------------------------------
int RentedVideo::getRenterID() 
{
	return renterID;
}

//---------------------------------
//set video title 1 rented
//---------------------------------
void RentedVideo::setVidTitle1(string tit1)
{
	vidTitle1 = tit1;
}

//---------------------------------
//get video title 1 rented
//---------------------------------
string RentedVideo::getVidTitle1() 
{
	return vidTitle1;
}

//---------------------------------
//set video title 2 rented
//---------------------------------
void RentedVideo::setVidTitle2(string tit2)
{
	vidTitle2 = tit2;
}

//---------------------------------
//get video title 2 rented
//---------------------------------
string RentedVideo::getVidTitle2() 
{ 
	return vidTitle2;
}

//---------------------------------
//return a line renter's first name, video title 1 rented (if any), video title 2 rented (if any)
//---------------------------------
string RentedVideo::toString()
{
	if ((vidTitle1 != "none") && (vidTitle2 != "none"))
		return (renterFirstName + ", " + renterLastName + ", " + vidTitle1 + ", " + vidTitle2);
	else if (vidTitle1 == "none")
		return (renterFirstName + ", " + renterLastName + ", " + vidTitle2);
	else
		return (renterFirstName + ", " + renterLastName + ", " + vidTitle1);
}