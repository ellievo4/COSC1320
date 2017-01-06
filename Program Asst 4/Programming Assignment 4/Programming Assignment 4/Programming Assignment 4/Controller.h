//COSC 1320 Summer 2015
//Thanh Vo
//Programming Assignment 4
//This is my own work, I will not post

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "VideoStore.h"

class Controller
{
private:
	VideoStore store;	//get access to class VideoStore

public:
	void UCLoad();
	void UCDisplayVideos();
	void UCSearchVideo();
	void UCRentVideo();
	void UCDisplayCustomers();
	void UCSearchCustomer();
	void UCDisplayRentedVideos();
	void UCSave();
};
#endif