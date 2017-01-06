//COSC 1320 Summer 2015
//Thanh Vo
//Programming Assignment 4
//This is my own work, I will not post

#include"Controller.h"
#include"VideoStore.h"

//-----------------------
//connect between user option and system operation for loading data from text file to program
//-----------------------
void Controller::UCLoad()
{
	store.load();
}

//-----------------------
//connect between user option and system operation for displaying video list
//-----------------------
void Controller::UCDisplayVideos()
{
	store.displayVideos();
}

//-----------------------
//connect between user option and system operation for searching a video
//-----------------------
void Controller::UCSearchVideo()
{
	store.searchVideo();
}

//-----------------------
//connect between user option and system operation for renting a video
//-----------------------
void Controller::UCRentVideo()
{
	store.rentVideo();
}

//-----------------------
//connect between user option and system operation for displaying customer list
//-----------------------
void Controller::UCDisplayCustomers()
{
	store.displayCustomers();
}

//-----------------------
//connect between user option and system operation for searching customer
//-----------------------
void Controller::UCSearchCustomer()
{
	store.searchCustomer();
}

//-----------------------
//connect between user option and system operation for displaying rented video list
//-----------------------
void Controller::UCDisplayRentedVideos()
{
	store.displayRentedVideos();
}

//-----------------------
//connect between user option and system operation for saving data from program to text file
//-----------------------
void Controller::UCSave()
{
	store.save();
}