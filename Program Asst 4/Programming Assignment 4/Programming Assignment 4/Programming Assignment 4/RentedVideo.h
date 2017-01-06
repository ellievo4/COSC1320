//COSC 1320 Summer 2015
//Thanh Vo
//Programming Assignment 4
//This is my own work, I will not post

#ifndef RENTEDVIDEO_H
#define RENTEDVIDEO_H
#include <string>
using namespace std;

class RentedVideo
{
private:
	string renterFirstName;		//track renter's first name
	string renterLastName;		//track renter's last name
	int renterID;				//track renter's ID
	string vidTitle1;			//track video title 1 rented
	string vidTitle2;			//track video title 2 rented

public:
	RentedVideo();
	void setRenterFirstName(string first);
	string getRenterFirstName();
	void setRenterLastName(string last);
	string getRenterLastName();
	void setRenterID(int id);
	int getRenterID();
	void setVidTitle1(string tit1);
	string getVidTitle1();
	void setVidTitle2(string tit2);
	string getVidTitle2();
	string toString();
};
#endif