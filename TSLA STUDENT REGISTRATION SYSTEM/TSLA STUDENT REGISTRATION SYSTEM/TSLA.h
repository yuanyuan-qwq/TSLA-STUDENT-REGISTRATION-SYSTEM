#pragma once
#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
#include <cstdlib>  


using namespace std;

#ifndef TSLA_H
#define TSLA_H


struct Node
{
	//student info
	string NAME;
	string MATRIC_NUM;
	int AGE;
	string COURSE;

	//for linking to other(next) node
	Node* next;
};


class TSLA
{

private:
	Node* front;		// phead
	Node* rear;			// ptail
	int count;			//count how many item now
	Node* pTraverse;	//pCurrent or ptemp


public:
	TSLA();					//Constructor

	void Enqueue(string, string, int, string);	//insert & enqueue student info

	void Dequeue();			//delete the first student info

	void queueFront();		//show the front(phead) info

	void queueRear();		//show the rear(ptail) info

	bool Empty();			//check the list is empty or not

	void DELETE(string);	//delete student info by using matric number

	void UPDATE(string);	//update student info by using matric number

	void display();			//display the current list of student info

	void search(string);	//sequential search, using matric number

	void sorting();			//bubble sort, ascending depend on matric no
};
#endif // !TSLA_H
