#pragma once
#ifndef LLISTFORSTUDENTS_H
#define LLISTFORSTUDENTS_H

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 100

using namespace std;

typedef int Status;//Define the type alias name

typedef struct
{
	char id[15];   //Student ID
	char name[20];  //Students' name
}student;

typedef student ElemType;//Define student as "Elemtype"


typedef struct
{
	ElemType *elem;   //Base address of the memory space
	int length;       //Current length
}SqList;



#endif // !LLISTFORSTUDENTS_H
