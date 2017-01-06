//COSC 1320 Summer 2015
//Thanh Vo
//Programming Assignment 4
//This is my own work, I will not post

#include"View.h"
#include"Controller.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int option;                   //track the option input from user
    View view;                    //get access from class View
    Controller control;           //get access from class Controller
    bool done = false;            //keep track of the exitting application

    control.UCLoad();

    while(!done)
    {
		//show introduction
        view.showSelection();

        //input an option from user
        cin >> option;

        //match input with the right option case
        switch(option)
        {
		case 1: control.UCDisplayVideos(); break;
		case 2: control.UCSearchVideo(); break;
		case 3: control.UCRentVideo(); break;
		case 4: control.UCDisplayCustomers(); break;
		case 5: control.UCSearchCustomer(); break;
		case 6: control.UCDisplayRentedVideos(); break;
		case 7: control.UCSave(); 
			cout << "EXIT THE PROGRAM" << endl;
			done = true;
			break;
		default: cout << "Invalid Input!!!" << endl;
        }
	}

	//ask user hit any key to exit the program
	system("Pause");
	return 0;
}