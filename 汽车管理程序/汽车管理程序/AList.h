/**********************************
Experience 2 2018/10/18
Header for the implementation of ArrayList
By ÖÜÑþ  201730685202
***********************************/
#pragma once
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include<iostream>
#include<algorithm>
#include<fstream>
#include<string.h>

#define defaultSize 100

using namespace std;

typedef struct
{
	char brand[20];
	char type[20];
	char color[20];
	char car_number[20];
	int year;
	int month;
	int day;
}Car;

class Alist
{
private:
	int maxSize;         //Maximum size of list
	int listSize;        //Number of list items now
	int curr;            //Position of current element
	Car* listArray;        //Array holding list elements

public:
	//Car* listArray;        //Array holding list elements
	Alist(int size = defaultSize) {//Constructor
		maxSize = size;
		listSize = curr = 0;
		listArray = new Car[maxSize];
	}

	~Alist() { delete[] listArray; }//Destructor

	void clear() {                   //Reinitaialize the list
		delete[] listArray;          //Remove the array
		listSize = curr = 0;         //Reset the size
		listArray = new Car[maxSize];  //Recreate the array
	}

	bool sortfun(Car &A,Car &B)           //the principle to sort
	{
		if (A.year < B.year)
			return true;
		else if (A.year > B.year)
			return false;
		else
		{
			if (A.month < B.month)
				return true;
			else if (A.month > B.month)
				return false;
			else
			{
				if (A.day < B.day)
					return true;
				else
					return false;
			}
		}
	}

	void insert(Car &it) {             //Insert "it" at current position and sort
		if (listSize >= maxSize)
			cout << "                  List capacity exceeded" << endl;    
		listArray[listSize++] = it;
		Car temp;
		for (int i = 0; i < listSize; i++)
		{
			for (int j = i; j < listSize; j++)
			{
				if (sortfun(listArray[j], listArray[i])) {    //Exchange the two element to sort
					temp = listArray[i];
					listArray[i] = listArray[j];
					listArray[j] = temp;
				}
			}
		}
	}

	void inputNew()             //Add a new car
	{
		Car c;
		cout << endl << endl << endl << "                  Please input the information for the new car." << endl;
		cout << endl << "                  Brand: ";
		cin >> c.brand;
		cout << "                  Type: ";
		cin >> c.type;
		cout << "                  Color: ";
		cin >> c.color;
		cout << "                  Car number: ";
		cin >> c.car_number;
		cout << "                  Date(y-m-d): ";
		cin >> c.year >> c.month >> c.day;
		insert(c);
		cout << endl << "                  Add succeeded. Press any button to continue..." << endl;
	}

	void modify(int pos)             //Modify the information of the car
	{
		cout << "                  Are you sure that you want to modify the car?" << endl;
		cout << "                  1.Yes  2.No                  " << endl;
		int n;
		cin >> n;
		if (n == 1)         //Sure to modify
		{
			int modi;
			cout << "                  1.Brand  2.Type  3.Color  4.Car number  5.Manufacture date" << endl;
			cout << "                  Please choose what do you want to modify:" << endl;
			cin >> modi;

			Car c;
			switch (modi)
			{
			case 1:
				cin >> c.brand;
				memcpy(listArray[pos].brand, c.brand, 20);  //Modify the brand of the car
				break;
			case 2:
				cin >> c.type;
				memcpy(listArray[pos].type, c.type, 20);    //Modify the type of the car
				break;
			case 3:
				cin >> c.color;
				memcpy(listArray[pos].color, c.color, 20);   //Modify the color of the car
				break;
			case 4:
				cin >> c.car_number;
				memcpy(listArray[pos].car_number, c.car_number, 20);   //Modify the car number of the car
				break;
			case 5:
				cin >> c.year >> c.month >> c.day;
				if (c.year > 2018 || c.month <= 0 || c.month > 12 || c.day <= 0 || c.day > 31)    //Make sure the information is valid
					cout << "                  Wrong date!!!" << endl;
				//Modify the manufacture date of the car
				listArray[pos].year = c.year;
				listArray[pos].month = c.month;
				listArray[pos].day = c.day;
				break;
			}
		}
	}

	void remove(int pos) {              //Remove and return the current element
		cout << "                  Are you sure that you want to delete the car?" << endl;
		cout << "                  1.Yes  2.No                  " << endl;
		int n;
		cin >> n;
		if (n == 1)                 //Sure to remove
		{
			if ((pos < 0) || (pos >= listSize))
				cout << "                  No element" << endl;
			for (int i = pos; i < listSize - 1; i++) {   //Shift the elements down
				listArray[i] = listArray[i + 1];
			}
			listSize--;
			cout << "                  The car hae been deleted!" << endl;
		}
	}

	void getCar(int pos) {            //Get the car at the special position
		if (pos < 0 || pos >= listSize)
			cout << "                  Pos out of range" << endl;
		else
		{    //Print the information of the car
			cout << "                  Num: " << pos + 1 << endl;
			cout << "                  Brand: " << listArray[pos].brand << endl;
			cout << "                  Type: " << listArray[pos].type << endl;
			cout << "                  Color: " << listArray[pos].color << endl;
			cout << "                  Car number: " << listArray[pos].car_number << endl;
			cout << "                  Manufacture date: " << listArray[pos].year << "-" <<
				listArray[pos].month << "-" << listArray[pos].day << endl;
		}
	}

	void display() const {        //Print all the car
		for (int i = 0; i <= listSize - 1; i++) {
			cout << "                  *************************************" << endl;
			cout << "                  Num: "<< i + 1 << endl;
			cout << "                  Brand: " << listArray[i].brand << endl;
			cout << "                  Type: " << listArray[i].type << endl;
			cout << "                  Color: " << listArray[i].color << endl;
			cout << "                  Car number: " << listArray[i].car_number << endl;
			cout << "                  Manufacture date: " << listArray[i].year << "-"
				<< listArray[i].month << "-" << listArray[i].day << endl;
		}
	}

	void findPos()                       //Find the position of the car
	{
		int n;
		cin >> n;
		if (n == 6) {
			int num;
			cout << "                  Please enter the number of the car you want to find: ";
			cin >> num;
			getCar(num - 1);
		}
		else if (n == 5) {
			int y;
			cout << "                  Please enter the year of the car you want to find: ";
			cin >> y;
			getPos(y);
		}
		else {
			char a[20];
			cout << "                  Please enter the parament of the car you want to find: ";
			cin >> a;
			getPos(a, n);
		}
	}

	void getPos(char a[],int n)     //Get the position of the car
	{
		switch (n)
		{
		case 1:
			for (int i = 0; i < listSize; i++)
			{
				if (judge(a, listArray[i].brand))   //Compare a and brand of every car in list
					getCar(i);
			}
			break;
		case 2:
			for (int i = 0; i < listSize; i++)
			{
				if (judge(a, listArray[i].type))     //Compare a and type of every car in list
					getCar(i);
			}
			break;
		case 3:
			for (int i = 0; i < listSize; i++)
			{
				if (judge(a, listArray[i].color))    //Compare a and type of every car in list
					getCar(i);
			}
			break;
		case 4:
			for (int i = 0; i < listSize; i++)
			{
				if (judge(a, listArray[i].car_number))   //Compare a and type of every car in list
					getCar(i);
			}
			break;
		}
	}

	void getPos(int y)      //Get the position of the car
	{
		for (int i = 0; i < listSize; i++)
		{
			if (y == listArray[i].year)
				getCar(i);
		}
	}

	bool judge(char a[], char b[])     //Judge whether the two is the same
	{
		int n = 0;
		if (strlen(a) != strlen(b))
			return 0;
		else
		{
			while (a[n] != '\0'&&b[n] != '\0')
			{
				if (a[n] == b[n])
					n++;
				else
					return 0;
			}
		}
		return 1;
	}

#pragma warning(disable:4996)
	void read()                    //Read the information of the car into listArray
	{
		ifstream fin("Car.txt");   //Create an object of ifstream
		string str;         //Store the string read just now
		char sstr[20];      //Used to transfer string to an array of char
		int flag = 0;       //Help to judge how many string has been read
		Car c;            //Temporarily store the information of the car
		if (fin)         //Judge whether the file exist
		{
			while (fin >> str)  //Do the instructions when reading the string
			{
				flag++;
				switch (flag)
				{
				case 1:
					strcpy(c.brand, str.c_str());    //Get the brand of the car
					break;
				case 2:
					strcpy(c.type, str.c_str());      //Get the type of the car
					break;
				case 3:
					strcpy(c.color, str.c_str());      //Get the color of the car
					break;
				case 4:
					strcpy(c.car_number, str.c_str());     //Get the car number of the car
					break;
				case 5:
					strcpy(sstr, str.c_str());     //Transfer the string to an array of char
					c.year = atoi(sstr);       //Transfer an array of char to int and get year of manufacture of the car
					break;
				case 6:
					strcpy(sstr, str.c_str());     //Transfer the string to an array of char
					c.month = atoi(sstr);       //Transfer an array of char to int and get month of manufacture of the car
					break;
				case 7:
					strcpy(sstr, str.c_str());     //Transfer the string to an array of char
					c.day = atoi(sstr);       //Transfer an array of char to int and get day of manufacture of the car
					insert(c);          //Insert the car after geting all the information
					flag = 0;        //Reset the flag to 0 and collect the information of the car again
					break;
				}
			}
			fin.close();            //Close the file
		}
		else
			cout << "                  Not found!" << endl;
	}

	void save()           //Save the information
	{
		ofstream fout("Car.txt");  //Create an object of ofstream
		if (fout)         //Judge whether the file exist
		{
			for (int i = 0; i < listSize; i++)          //Store the information of the car into the file
			{
				fout << listArray[i].brand << " ";
				fout << listArray[i].type << " ";
				fout << listArray[i].color << " ";
				fout << listArray[i].car_number << " ";
				fout << listArray[i].year << " " << listArray[i].month << " " << listArray[i].day << endl;
			}
		}
		else
			cout << "                  Not found!" << endl;
		fout.close();
	}
};

#endif
