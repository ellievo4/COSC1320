//COSC 1320 Summer 2015
//Thanh Vo
//Programming Assignment 4
//This is my own work, I will not post

#include "View.h"
#include <iostream>
using namespace std;

void View::showSelection()
{
	cout << "Welcome to Our Video Store." << endl;
	cout << "What can I do for you?" << endl;
	cout << "1. Display videos" << endl;
	cout << "2. Search a video" << endl;
	cout << "3. Rent a video" <<endl;
	cout << "4. Display customers" << endl;
	cout << "5. Search a customer" << endl;
	cout << "6. Display rented videos" << endl;
	cout << "7. Exit" << endl;
	cout << "Please enter a number (1-7): " << endl;
	cout << ">>>>";
}