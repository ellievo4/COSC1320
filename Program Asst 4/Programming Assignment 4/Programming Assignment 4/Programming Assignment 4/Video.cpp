//COSC 1320 Summer 2015
//Thanh Vo
//Programming Assignment 4
//This is my own work, I will not post

#include<string>
#include"Video.h"
using namespace std;

//----------------------------------
//initialize all member variables in this class
//----------------------------------
Video::Video()
	: title("none"), star1("none"), star2("none"), producer("none"), director("none"), productionCompany("none"), copiesInStock(0) {}

//----------------------------------
//set the video title
//----------------------------------
void Video::setTitle(string tit)
{
	title = tit;
}

//----------------------------------
//get the video title
//----------------------------------
string Video::getTitle()
{
	return title;
}

//----------------------------------
//set movie star 1 
//----------------------------------
void Video::setStar1(string name1)
{
	star1 = name1;
}

//----------------------------------
//get movie star 1 
//----------------------------------
string Video::getStar1()
{ 
	return star1;
}

//----------------------------------
//set movie star 2
//----------------------------------
void Video::setStar2(string name2)
{
	star2 = name2;
}

//----------------------------------
//get movie star 2
//----------------------------------
string Video::getStar2()
{
	return star2;
}

//----------------------------------
//set video producer 
//----------------------------------
void Video::setProducer(string name3)
{
	producer = name3;
}

//----------------------------------
//get video producer
//----------------------------------
string Video::getProducer()
{
	return producer;
}

//----------------------------------
//set video director
//----------------------------------
void Video::setDirector(string name4)
{
	director = name4;
}

//----------------------------------
//get video director
//----------------------------------
string Video::getDirector()
{
	return director;
}

//----------------------------------
//set the video's production company
//----------------------------------
void Video::setProductionCompany(string comp)
{
	productionCompany = comp;
}

//----------------------------------
//get the video's production company
//----------------------------------
string Video::getProductionCompany()
{
	return productionCompany;
}

//----------------------------------
//set the number of copies of video that is in stock
//----------------------------------
void Video::setCopiesInStock(int num)
{
	copiesInStock = num;
}

//----------------------------------
//get the number of copies of video that is in stock
//----------------------------------
int Video::getCopiesInStock()
{
	return copiesInStock;
}

//----------------------------------
//return a string of all information for one video except number of copies in stock
//----------------------------------
string Video::toString()
{
	return (title + "\n" + star1 + "\n" + star2 + "\n" + producer + "\n" + director + "\n" + productionCompany + "\n");
}

//----------------------------------
//operator to print to screen number of video copies that is in stock
//----------------------------------
ostream& operator << (ostream& outStream, const Video& vid1)
{
	outStream << vid1.copiesInStock;
	return outStream;
}