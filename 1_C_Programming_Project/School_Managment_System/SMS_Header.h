/***************************************************************************************************
 * Project Name: School Management System
 * File Name:	 SMS_header.h
 * Author:		 Ahmed M. AbdEl-kareem
 * Description:  Preprocessors Records
 ***************************************************************************************************/

#ifndef SMS_HEADER_H_
#define SMS_HEADER_H_

/*--------------------------------------------Includes---------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

/*----------------------------------Defentions_and_Configurations----------------------------------*/
typedef unsigned char         	 uint8;          /*           0 .. 255             */
typedef signed char           	 sint8;          /*        -128 .. +127            */
typedef unsigned short int       uint16;         /*           0 .. 65535           */
typedef signed short int         sint16;         /*      -32768 .. +32767          */
typedef unsigned long int        uint32;         /*           0 .. 4294967295      */
typedef signed long int          sint32;         /* -2147483648 .. +2147483647     */
typedef unsigned long long int   uint64;         /*       0..18446744073709551615  */
typedef signed long long int     sint64;
typedef float                	 float32;
typedef double                	 float64;

/*------------------------------------------Structures---------------------------------------------*/
typedef struct date{
	uint16 dy;
	uint16 mnth;
	uint16 yr;
}date;


typedef struct student{
	char stdnt_Nm[20];
	uint16 id;
	uint16 csScr;
	char stdnt_grd[3];
	char stdnt_gndr[2];
	char phNumbr[12];
	char addrss[20];
	date brthdy;
}StudentEntry;


typedef struct studentnode{
	StudentEntry *entry;
	struct studentnode *next;
}StudentNode;


typedef struct list
{
	StudentNode *top;
	uint32 size;
}List;

/*------------------------------------Function_Declaration-----------------------------------------*/
void MainMenu();
void InMenu();
void NewStudent(List *lPtr);
void DeleteStudent(List *lPtr);
void StudentList(List *lPtr);
void StudentEdit(List *lPtr);
void RankStudent(List *lPtr);
void ScoreStudent(List *lPtr);
uint16 SrchID(uint16 id,List *lPtr);
void SlctActvty();
void StudentsTotal(List *lPtr);



#endif /* SMS_HEADER_H_ */
