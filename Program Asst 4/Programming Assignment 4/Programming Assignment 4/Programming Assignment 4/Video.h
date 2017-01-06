//COSC 1320 Summer 2015
//Thanh Vo
//Programming Assignment 4
//This is my own work, I will not post

#ifndef VIDEO_H
#define VIDEO_H
#include<string>
using namespace std;

class Video
{
private:
	string title;					//track video title
	string star1;					//track movie star 1 of video
	string star2;					//track movie star 2 of video
	string producer;				//track producer of video
	string director;				//track director of video
	string productionCompany;		//track production company of video
	int copiesInStock;				//track number of copies of video that is in stock

public:
	Video();
	void setTitle(string tit);
	string getTitle();
	void setStar1(string name1);
	string getStar1();
	void setStar2(string name2);
	string getStar2();
	void setProducer(string name3);
	string getProducer();
	void setDirector(string name4);
	string getDirector();
	void setProductionCompany(string comp);
	string getProductionCompany();
	void setCopiesInStock(int num);
	int getCopiesInStock();
	string toString();
	friend ostream& operator << (ostream& outputStream, const Video& vid1);
};

#endif