//COSC 1320 Summer 2015
//Thanh Vo
//Programming Assignment 4
//This is my own work, I will not post

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include"VideoStore.h"
#include"Video.h"
#include"Customer.h"
#include"RentedVideo.h"
using namespace std;

//------------------------------
//initialize all member variables of this class
//------------------------------
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

//------------------------------
//load in the data from text file and assign to data in 3 arrays 
//------------------------------
void VideoStore::load()
{
	int i = 0;						//track all indexes
	string title;					//track video title
	string star1;					//track movie star 1
	string star2;					//track movie star 2
	string producer;				//track movie producer
	string director;				//track movie director
	string productionCompany;		//track production company of video
	int copiesInStock;				//track number of copies of video
	string firstName;				//track customer first name
	string lastName;				//track customer last name
	int id;							//track customer id
	int num;						//track renter's id
	string titleone;				//track video title 1 rented
	string titletwo;				//track video title 2 rented
	int countt;						//track the count of comma
	int loop;						//track the index of the loop that counts comma

	ifstream inFile("Programming Assignment 4 Data.txt");		//track the stream input data

	//make sure the file is opened
	if(inFile.fail()) 
	{
		cout << "fail to open file" << endl;
		exit(0);
	}

	// open file and stream in the first character
	cout << "File is now open" << endl;

	//stream in the number of video
	inFile >> noOfVid;
	inFile.ignore(256, '\n');

	//stream in data for the list of video
	while (i<noOfVid)
	{
		getline(inFile,title); 
		video[i].setTitle(title);

		getline(inFile,star1);
		video[i].setStar1(star1);

		getline(inFile,star2);
		video[i].setStar2(star2);

		getline(inFile,producer);
		video[i].setProducer(producer);

		getline(inFile,director);
		video[i].setDirector(director);

		getline(inFile,productionCompany);
		video[i].setProductionCompany(productionCompany);

		inFile >> copiesInStock;
		video[i].setCopiesInStock(copiesInStock);
		inFile.ignore(256, '\n');
	
		i++;
		counter[0]++;
	}

	string tempp;	//track a whole line of text
	i = 0;
	while (getline(inFile,tempp))
	{
		istringstream ss(tempp);		//track method to stream in a line of text 

		//check if the first character is digit, if so exit this while loop
		if(isdigit(tempp.at(0)))
		break;
  
		//get first name
		getline(ss, firstName, ',');
		customer[i].setFirstName(firstName);

		//get last name
		getline(ss, lastName, ',');
		customer[i].setLastName(lastName);

		//get id
		ss >> id;
		customer[i].setID(id);

		//number of index and customer increase by 1
		counter[1]++;
		i++;
	}

	i=0;
	do
	{
		//initial titletwo, countt and loop
		titletwo = "";
		countt = 0;
		loop = 0;

		istringstream ss(tempp);		//track method to stream in a line of text 

		//stream in renter ID and video title 1
		ss >> num; 
		rentedVideo[i].setRenterID(num);
		ss.ignore(500, ',');
		getline(ss, titleone, ',');
		rentedVideo[i].setVidTitle1(titleone);
  
		//count comma in the line
		while (loop < tempp.length())
		{
			if (tempp[loop] == ',')
				countt++;
			loop++;
		}
  
		//if there are 2 comma, stream in video title 2
		if (countt == 2)
		{
			getline(ss, titletwo, ',');
			rentedVideo[i].setVidTitle2(titletwo);
		}

		//number of index and rented video increase by 1
		counter[2]++;
		i++;
	} while (getline(inFile,tempp));
 
	//close file
	 inFile.close();
}

//------------------------------
//display video list to screen
//------------------------------
void VideoStore::displayVideos()
{
	cout << "Display videos option" << endl;
	for (int i = 0; i< counter[0]; i++)
	{
		cout << video[i].toString();
		cout << video[i] << endl;
		cout << endl;
	}
}

//------------------------------
//search for the video whose title is entered from keyboard by user
//------------------------------
void VideoStore::searchVideo()
{
	string title;
	int foundIndex = -1;		//track the position of data set containing title input in array video

	//insert title
	cout << "Search video option" << endl;
	cout << "Enter a video title: ";
	cin.ignore(256, '\n');
	getline(cin, title);

	//search title
	for (int i = 0; i< counter[0]; i++)
		if(video[i].getTitle() == title)
			foundIndex = i;

	//display if there is one
	if (foundIndex != -1)
	{
		cout << "Here is the information of your video: " << endl;
		cout << video[foundIndex].toString();
		cout << video[foundIndex] << endl;
	}
	
	//notify if there is none
	else 
		cout << "No video found!" << endl;

	cout<< endl;
}

//------------------------------
//rent a video in which add a new data set to array videoRented and customer
//------------------------------
void VideoStore::rentVideo()
{
	string first;				//track customer first name
	string last;				//track customer last name
	int rentID;					//track renter's ID
	char answer;				//track customer's answer for another video
	string titleOne;			//track video title 1 rented
	string titleTwo;			//track video title 2 rented
	int foundIndex1 = -1;		//track the position of data set containing title 1 input in array video
	int foundIndex2 = -1;		//track the position of data set containing title 2 input in array video
	int count = 0;				//track the count of video rented so far

	//introduction
	cout << "Rent option" << endl;
	cout << "You can rent up to 2 videos per visit" << endl;

	//enter customer data: first name, last name and ID
	cout << "Please enter first name: ";
	cin >> first;
	customer[counter[1]].setFirstName(first);
	cout << "Please enter last name: ";
	cin >> last;
	customer[counter[1]].setLastName(last);
	rentID = customer[counter[1]-1].getID();
	rentID++;
	customer[counter[1]].setID(rentID);
	rentedVideo[counter[2]].setRenterID(rentID);
	
	//number of customer increases by 1
	counter[1]++;

	//display videos
	displayVideos();

	//enter title one
	cout << "Please enter a video title: ";
	cin.ignore(256, '\n');
	getline(cin, titleOne);

	//search title
	for (int i = 0; i< counter[0]; i++)
		if(video[i].getTitle() == titleOne)
			foundIndex1 = i; 
	
	if (foundIndex1 == -1) 
		cout << "Video not found" << endl;

	else
	{
		//set title 1 to the rented video list
		rentedVideo[counter[2]].setVidTitle1(titleOne);

		// number of copies decreases by 1
		int noOfCopies = video[foundIndex1].getCopiesInStock() - 1;
		video[foundIndex1].setCopiesInStock(noOfCopies);
		count++;

		// show notification
		cout << "Rent successfully" << endl;
	}

	//ask for second video
		cout << "Do you want to rent another video (Y/N)?";
		cin >> answer;
	
	while ((count < 2) && (answer != 'N'))
	{
			//enter title two
			cout << "Please enter a video title: ";
			cin.ignore(256, '\n');
			getline(cin, titleTwo);

			//search title
			for (int i = 0; i< counter[0]; i++)
				if(video[i].getTitle() == titleTwo)
					foundIndex2 = i; 
	
			//if there is no title matching title two
			if (foundIndex2 == -1) 
				cout << "Video not found" << endl;

			else
			{
				//set title 2 to the rented video list
				rentedVideo[counter[2]].setVidTitle2(titleTwo);

				// number of copies decreases by 1
				int noOfCopies = video[foundIndex2].getCopiesInStock() - 1;
				video[foundIndex2].setCopiesInStock(noOfCopies);
				count ++;

				// show notification
				cout << "Rent successfully" << endl;
			}

			//ask for second video again in case user mistypes the name of video title 2
			cout << "Do you want to rent another video (Y/N)?";
			cin >> answer;
	}

	//number of rented video increases by 1
	counter[2]++;
	cout << "Exit rent option" << endl;
}


//------------------------------
//display a list of customer
//------------------------------
void VideoStore::displayCustomers()
{
	cout << "Display customers option" << endl;
	for (int i = 0; i < counter[1]; i++)
	{
		cout << customer[i].toString();
		cout << customer[i] << endl;
	}
}

//------------------------------
//search for customers whose last name is entered from keyboard by user
//------------------------------
void VideoStore::searchCustomer()
{
	string lastName;		//track customer last name

	//insert last name of customer
	cout << "Search customer option" << endl;
	cout << "Enter customer last name: ";
	cin.ignore(256, '\n');
	getline(cin,lastName, '\n');

	//output notification
	cout << "Here is the information of your customer (blank if there is none): " << endl;

	//search for last name of customer
	for (int i=0; i < counter[1]; i++)
	{
		//display if there are some	
		if(customer[i].getLastName() == lastName)
		{
			cout << customer[i].toString();
			cout << customer[i] << endl;
		}
	}
	
	cout<< endl;
}

//------------------------------
//display the list of rented video
//------------------------------
void VideoStore::displayRentedVideos()
{
	int rentID;	//track the renter's ID

	//get renter's ID from array rentedVideo, utitlize this ID to get first name and last name of customer in array customer then set these data back 
	//to array rentedVideo
	for (int i = 0; i < counter[1]; i++)
	{
		rentID = rentedVideo[i].getRenterID();
		rentedVideo[i].setRenterFirstName(customer[rentID-1].getFirstName());
		rentedVideo[i].setRenterLastName(customer[rentID-1].getLastName());
	}

	//display list of rented video
	for (int i = 0; i < counter[2] ; i++)
		cout << rentedVideo[i].toString() << endl;
}

//------------------------------
//write to file the data sets in 3 array 
//------------------------------
void VideoStore::save()
{
	ofstream outFile("Programming Assignment 4 Data.txt");		//track the stream output data

	//make sure the file is opened, if not, exit program
	if(outFile.fail()) 
	{
		cout << "fail to open file" << endl;
		exit(0);
	}

	//write number of videos to file
	cout << "Writing to file" << endl;
	outFile << noOfVid << "\n";

	//stream out videos
	for (int i = 0; i < counter[0]; i++)
		outFile << video[i].getTitle() << "\n" << video[i].getStar1() << "\n" + video[i].getStar2() << "\n" << video[i].getProducer() 
		<< "\n" << video[i].getDirector() << "\n" << video[i].getProductionCompany() << "\n" << video[i].getCopiesInStock() << endl;

	//stream out customers
	for (int i = 0; i < counter[1]; i++)
		outFile << customer[i].getFirstName() << ", " << customer[i].getLastName() << ", " << customer[i].getID() << endl;

	//stream out rented videos whose data contain renter's id, video title 1 (if any), video title 2 (if any)
	for (int i = 0; i < counter[2]; i++)
	{
		if ((rentedVideo[i].getVidTitle1()!= "none")&&(rentedVideo[i].getVidTitle2()!= "none"))
			outFile << rentedVideo[i].getRenterID() << ", " << rentedVideo[i].getVidTitle1() << ", " << rentedVideo[i].getVidTitle2() << endl;
		else if (rentedVideo[i].getVidTitle1()== "none")
			outFile << rentedVideo[i].getRenterID() << ", " << rentedVideo[i].getVidTitle2() << endl;
		else
			outFile << rentedVideo[i].getRenterID() << ", " << rentedVideo[i].getVidTitle1() << endl;
	}

	//close file
	outFile.close();
}