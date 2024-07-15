#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
#include <cstdlib>  
#include "TSLA.h"


using namespace std;

TSLA info;

//function decralation
void INSERT();
void DELETE();
void UPDATE();
void SEARCH();
void SORTING();
void QUEUE();


//######################### MAIN FUNCTION ##############################
void main()
{

	char choose;

	do 
	{
		cout << "********** TSLA STUDENT REGISTRATION SYSTEM **********\n\n"
			<< "             A. INSERT STUDENT INFO\n"
			<< "             B. DELETE STUDENT INFO\n"
			<< "             C. UPDATE STUDENT INFO\n"
			<< "             D. SEARCH STUDENT INFO\n"
			<< "             E. SORTING STUDENT INFO\n"
			<< "             F. QUEUE STUDENT INFO\n"
			<< "             G. DISPLAY STUDENT INFO\n"
			<< "             0. PRESS 0 TO EXIT PROGRAM\n\n"
			<< "******************************************************\n\n";

		cout << "\tChoose Your Menu: ";
		cin >> choose;

		//let user select the function and 0 to exit program
		switch (choose)
		{
		case 'a':
		case 'A':
			INSERT();

			break;

		case 'b':
		case 'B':
			DELETE();
			break;

		case 'c':
		case 'C':
			UPDATE();
			break;

		case 'd':
		case 'D':
			SEARCH();
			break;

		case 'e':
		case 'E':
			SORTING();
			break;

		case 'f':
		case 'F':
			QUEUE();
			break;

		case 'g':
		case 'G':
			system("cls");
			cout << "STUDENT INFO\n\n";
			info.display();
			system("cls");
			break;

		case '0':
			break;

		default:
			cout << "\n******************* INVALID INPUT *******************\n\n";
			system("pause");
			system("cls");
		}
	}
	while (choose != '0');

	system("cls");
	cout << "############################################";
	cout << "\n############# Thanks for using #############\n";
	cout << "############################################\n\n";
	//byebye

}


//######################### FUNCTION DEFINITION ########################

//ask user to insert/enqueue student info and 0 to exit
void INSERT()
{
	string name, matric, course;
	int age;
	char Again;

	do
	{
		system("cls");
		cout << "INSERT STUDENT INFO\n\n";

		cout << "NAME:";
		getline(cin >> ws, name);

		cout << "MATRIC NUMBER:";
		cin >> matric;

		cout << "AGE:";
		cin >> age;

		while (cin.fail())//avoid user invalid input 
		{
			cout << "INVALID INPUT!!!! PLEASE ENTER INTEGER VALUE!!!\n";

			cin.clear();
			cin.ignore(256, '\n');

			cout << "AGE:";
			cin >> age;
		}

		cout << "COURSE:";
		getline(cin >> ws, course);

		info.Enqueue(name, matric, age, course);

		cout << "\ndo u want to insert again(0 to exit): ";
		cin >> Again;

		system("cls");

	} while (Again != '0');

}

//delete info using matric number and 0 to exit
void DELETE()
{
	string target;
	char Again;

	// Checking for empty list
	if (info.Empty())
	{
		system("cls");
		cout << "##### EMPTY !!! ##### \n\n";
		system("pause");
		system("cls");
		return;
	}

	do
	{
		system("cls");
		cout << "DELETE STUDENT INFO\n\n";

		cout << "please enter matric number: ";
		cin >> target;

		info.DELETE(target);

		cout << "\ndo u want to delete again(0 to exit): ";
		cin >> Again;
	} while (Again != '0');

	system("cls");
}

//update info using matric number and 0 to exit
void UPDATE()
{
	string name, matric, age, course;
	char Again;

	// Checking for empty list
	if (info.Empty())
	{
		system("cls");
		cout << "##### EMPTY !!! ##### \n\n";
		system("pause");
		system("cls");

		return;
	}

	do
	{
		system("cls");
		cout << "UPDATE STUDENT INFO\n\n";

		cout << "Enter matric nomber to update student information: ";
		cin >> matric;

		info.UPDATE(matric);

		cout << "\ndo u want to update again(0 to exit): ";
		cin >> Again;

		system("cls");

	} while (Again != '0');
}

//search info using matric number and 0 to exit
void SEARCH()
{
	string target;
	char Again;

	// Checking for empty list
	if (info.Empty())
	{
		system("cls");
		cout << "##### EMPTY !!! ##### \n\n";
		system("pause");
		system("cls");

		return;
	}

	do
	{
		system("cls");
		cout << "SEARCH STUDENT INFO\n\n";

		cout << "please enter matric number: ";
		cin >> target;

		info.search(target);

		cout << "\ndo u want to search again(0 to exit): ";
		cin >> Again;

	} while (Again != '0');

	system("cls");
}

//sorting current student info list
void SORTING()
{

	// Checking for empty list
	if (info.Empty())
	{
		system("cls");
		cout << "##### EMPTY !!! ##### \n\n";
		system("pause");
		system("cls");
		return;
	}

	system("cls");
	cout << "SORTING STUDENT INFO\n\n";

	info.sorting();
	system("cls");
}

//queue function for enqueu,dequeue,queue front,quer rear
void QUEUE()
{
	system("cls");
	char choose;

	do
	{
		cout << "************ QUEUE REGISTRATION SYSTEM ************\n\n"
			<< "             A. ENQUEUE STUDENT INFO\n"
			<< "             B. DEQUEUE STUDENT INFO\n"
			<< "             C. QUEUE FRONT STUDENT INFO\n"
			<< "             D. QUEUE REAR STUDENT INFO\n"
			<< "             0. BACK TO MENU\n\n"
			<< "*****************************************************\n\n";

		cout << "\tChoose Your Menu: ";
		cin >> choose;

		switch (choose)
		{
		case 'a':
		case 'A':
			INSERT();
			break;

		case 'b':
		case 'B':
			system("cls");

			info.Dequeue();

			system("pause");
			system("cls");
			break;

		case 'c':
		case 'C':
			info.queueFront();
			break;

		case 'd':
		case 'D':
			info.queueRear();
			break;

		case '0':
			break;

		default:
			cout << "\n******************* INVALID INPUT *******************\n\n";
			system("pause");
			system("cls");
		}
	} while (choose != '0');

	system("cls");
}
