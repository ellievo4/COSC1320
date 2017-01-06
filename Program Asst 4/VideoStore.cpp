#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include"VideoStore.h"
#include"Video.h"
#include"Customer.h"
#include"RentedVideo.h"
using namespace std;

VideoStore::VideoStore()
	: noOfVid(0)
{
	for (int i = 0; i<10; i++)
	{
		video[i] = Video();
		customer[i] = Customer();
		rentedVideo[i] = RentedVideo();
	}

	for (int j = 0; j<3; j++)
		counter[j] = 0;
}

int VideoStore::getNoOfVid()
{
	return noOfVid;
}

void VideoStore::load()
{
	int i = 0;
	string title;
	string star1;
	string star2;
	string producer;
	string director;
	string productionCompany;
	string copiesInStock;
	string firstName;
	string lastName;
	int id;
	string title1;
	string title2;
	char comma;

	ifstream inFile("Programming Assignment 4 Data.txt");		//track the stream input data

	//make sure the file is opened
	if(inFile.fail()) 
	{
		cout << "fail to open file" << endl;
		cin >> id;
		exit(0);
	}

	// open file and stream in the first character
	cout << "File is now open" << endl;

	inFile >> noOfVid;
	inFile.ignore(256, '\n');

	while (i<noOfVid)
	{
		getline(inFile,title); 
		video[i].setTitle(title);
		cout << title << endl;

		getline(inFile,star1);
		video[i].setStar1(star1);
		cout << star1 << endl;
		

		getline(inFile,star2);
		video[i].setStar2(star2);
		cout << star2 << endl;
		

		getline(inFile,producer);
		video[i].setProducer(producer);
		cout << producer << endl;
		

		getline(inFile,director);
		video[i].setDirector(director);
		cout << director << endl;
		

		getline(inFile,productionCompany);
		video[i].setProductionCompany(productionCompany);
		cout << productionCompany << endl;
		

		getline(inFile,copiesInStock);
		video[i].setCopiesInStock(copiesInStock);
		cout << copiesInStock << endl;
	
		i++;
		counter[0]++;
	}

	string idd;
	string tempp; //tempp gets the whole line "jack,john,2"
		
	while (getline(inFile,tempp))
	{
		istringstream ss(tempp);

		getline(ss, firstName, ',');
		getline(ss, lastName, ',');
		getline(ss, idd, ',');
		
		cout << firstName << ", " << lastName << ", " << idd << endl;
	}
	
	



	


}


void VideoStore::displayVideos()
{
	for (int i = 0; i< counter[1]; i++)
		cout << video[i].toString() << endl;
}


void VideoStore::searchVideo()
{
	string title;
	int foundIndex = 0;
	cout << "Search option" << endl;
	cout << "Enter a video title: ";
	cin.ignore(256, '\n');
	getline(cin,title);

	for (int i = 0; i< counter[0]; i++)
		if(video[i].getTitle() == title)
			foundIndex = i;

	if (foundIndex != 0)
	{
		cout << "Here is the information of your video: " << endl;
		cout << video[foundIndex].toString() << endl;
	}
	
	else 
		cout << "No video found!" << endl;
}


void VideoStore::rentVideo()
{}


void VideoStore::displayCustomers()
{}


void VideoStore::searchCustomer()
{}


void VideoStore::displayRentedVideos()
{}


void VideoStore::save()
{}
