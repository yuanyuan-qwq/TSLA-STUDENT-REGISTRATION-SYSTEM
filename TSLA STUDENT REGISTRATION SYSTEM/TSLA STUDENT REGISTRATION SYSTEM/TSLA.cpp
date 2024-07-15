#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
#include <cstdlib>  
#include "TSLA.h"

TSLA::TSLA()
{
	front = NULL;
	rear = NULL;
	count = 0;
}


//check the list is empty or not
bool TSLA::Empty()
{
	return (count == 0);
}


//insert & enqueue student info
void TSLA::Enqueue(string name, string matric, int age, string course)
{
	Node* T = new Node;
	T->NAME = name;
	T->MATRIC_NUM = matric;
	T->AGE = age;
	T->COURSE = course;
	T->next = NULL;
	if (!Empty())
		rear->next = T;
	else
		front = T;
	count++;
	rear = T;

}


//delete the first student info
void TSLA::Dequeue()
{
	if (count == 0)// test for empty queue
		cout << "###### Underflow ######\n";
	else
	{	//dequeue
		Node* temp = front;
		cout << "Dequeue:\n";
		cout << "NAME:\t\t" << front->NAME << endl
			<< "MATRIC NUMBER:\t" << front->MATRIC_NUM << endl
			<< "AGE :\t\t" << front->AGE << endl
			<< "COURSE :\t" << front->COURSE << endl << endl;

		if (count == 1)
			front = rear = NULL;
		else
			front = front->next;
		count--;
		delete temp;

	}
} //end Dequeue


//show the front(phead) info
void TSLA::queueFront()
{
	// Checking for empty list
	if (Empty()) 
	{
		system("cls");
		cout << "##### EMPTY !!! ##### \n\n";
		system("pause");
		system("cls");
		return;
	}
	else
	{	//print Front(phead) info
		system("cls");
		cout << "QUEUE FRONT\n\n";
		cout << "NAME:\t\t" << front->NAME << endl
			<< "MATRIC NUMBER:\t" << front->MATRIC_NUM << endl
			<< "AGE :\t\t" << front->AGE << endl
			<< "COURSE :\t" << front->COURSE << endl << endl;
		system("pause");
		system("cls");
	}


}


//show the rear(ptail) info
void TSLA::queueRear() {

	// Checking for empty list
	if (Empty()) 
	{
		system("cls");
		cout << "##### EMPTY !!! ##### \n\n";
		system("pause");
		system("cls");
		return;
	}
	else
	{	//print rear(ptail) info
		system("cls");
		cout << "QUEUE REAR\n\n";
		cout << "NAME:\t\t" << rear->NAME << endl
			<< "MATRIC NUMBER:\t" << rear->MATRIC_NUM << endl
			<< "AGE :\t\t" << rear->AGE << endl
			<< "COURSE :\t" << rear->COURSE << endl << endl;
		system("pause");
		system("cls");
	}

}


//display the current list of student info
void TSLA::display()
{
	// Checking for empty list
	if (Empty())
	{
		cout << "##### EMPTY !!! ##### \n\n";
		system("pause");
		return;
	}

	pTraverse = front;
	cout << "Number of student in the list : " << count << endl << endl;

	while (pTraverse != NULL)
	{
		cout << "NAME:\t\t" << pTraverse->NAME << endl
			<< "MATRIC NUMBER:\t" << pTraverse->MATRIC_NUM << endl
			<< "AGE :\t\t" << pTraverse->AGE << endl
			<< "COURSE :\t" << pTraverse->COURSE << endl << endl;

		pTraverse = pTraverse->next;
	}
	system("pause");
}


//delete student info by using matric number
void TSLA::DELETE(string matric)
{
	Node* pBefore = NULL;
	pTraverse = front;

	while (pTraverse != NULL && pTraverse->MATRIC_NUM != matric)
	{	//search using matric number
		pBefore = pTraverse;
		pTraverse = pTraverse->next;
	}

	if (pTraverse != NULL && pTraverse->MATRIC_NUM == matric)
	{
		if (pTraverse == front) //delete front(phead) info
		{
			Node* temp = front;
			if (count == 1)
				front = rear = NULL;
			else
				front = front->next;
			count--;
			delete temp;
		}
		else //delete middle & rear(ptail) info
		{
			pBefore->next = pTraverse->next;
			delete pTraverse;
			count--;
		}
		cout << "\ndelete successful\n";
	}
	else //matric number not found
	{
		cout << "\nTarget not found\n";
	}

}


//update student info by using matric number
void TSLA::UPDATE(string matric) {
	string name, Matric, course;
	int age;
	pTraverse = front;

	while (pTraverse != NULL && pTraverse->MATRIC_NUM != matric)//search using matric number
	{
		pTraverse = pTraverse->next;
	}

	if (pTraverse != NULL && pTraverse->MATRIC_NUM == matric) 
	{
		//get student info
		
		cout << "\nNAME:";
		getline(cin >> ws, name);

		cout << "MATRIC NUMBER:";
		cin >> Matric;

		cout << "AGE:";
		cin >> age;
		while (cin.fail())//avoid user enter invalid input
		{
			cout << "INVALID INPUT!!!! PLEASE ENTER INTEGER VALUE!!!\n";
			cin.clear();
			cin.ignore(256, '\n');
			cout << "AGE:";
			cin >> age;
		}

		cout << "COURSE:";
		getline(cin >> ws, course);

		//update student info
		pTraverse->NAME = name;
		pTraverse->MATRIC_NUM = Matric;
		pTraverse->AGE = age;
		pTraverse->COURSE = course;

	}
	else 
	{	// not found
		cout << "\nTarget not found\n";
	}

}


//sequential search, using matric number
void TSLA::search(string matric)
{
	pTraverse = front;
	while (pTraverse != NULL && pTraverse->MATRIC_NUM != matric)//search using matric number
	{
		pTraverse = pTraverse->next;
	}

	if (pTraverse != NULL && pTraverse->MATRIC_NUM == matric) //print out search's result
	{
		cout << "\nNAME:\t\t" << pTraverse->NAME << endl
			<< "MATRIC NUMBER:\t" << pTraverse->MATRIC_NUM << endl
			<< "AGE :\t\t" << pTraverse->AGE << endl
			<< "COURSE :\t" << pTraverse->COURSE << endl << endl;
	}
	else //not found
	{
		cout << "\nTarget not found\n";
	}


}


//bubble sort, ascending depend on matric no
void TSLA::sorting() 
{

	int swap;

	do
	{
		swap = 0;
		pTraverse = front;

		while (pTraverse->next != NULL)
		{
			//ascending depend on matric no
			if (pTraverse->MATRIC_NUM > pTraverse->next->MATRIC_NUM)
			{
				//swap info
				string temp = pTraverse->NAME;
				pTraverse->NAME = pTraverse->next->NAME;
				pTraverse->next->NAME = temp;

				string temp1 = pTraverse->MATRIC_NUM;
				pTraverse->MATRIC_NUM = pTraverse->next->MATRIC_NUM;
				pTraverse->next->MATRIC_NUM = temp1;

				int temp2 = pTraverse->AGE;
				pTraverse->AGE = pTraverse->next->AGE;
				pTraverse->next->AGE = temp2;

				string temp3 = pTraverse->COURSE;
				pTraverse->COURSE = pTraverse->next->COURSE;
				pTraverse->next->COURSE = temp3;

				swap = 1;
			}
			pTraverse = pTraverse->next;
		}

	} while (swap);


	// print sorted item
	display();

}