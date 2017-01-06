//COSC 1320 Summer 2015
//Thanh Vo
//Programming Assignment 4
//This is my own work, I will not post

#ifndef VIDEOSTORE_H
#define VIDEOSTORE_H
#include <string>
#include <iostream>
#include <fstream>
#include "Video.h"
#include "Customer.h"
#include "RentedVideo.h"
using namespace std;

class VideoStore
{
private:
	int noOfVid;						//track number of all videos
	Video video[10];					//get access to class Video
	Customer customer[10];				//get access to class Customer
	RentedVideo rentedVideo[10];		//get access to class RentedVideo
	int counter[3];						//track numbers of video, customer and rented video

public:
	VideoStore();
	void load();
	void displayVideos();
	void searchVideo();
	void rentVideo();
	void displayCustomers();
	void searchCustomer();
	void displayRentedVideos();
	void save();
};
#endif
	

