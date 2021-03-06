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
    date brthdy;
    uint32 rst_ph;
    uint16 cc_ph;
    uint16 id;
    uint16 csScr;
    char stdnt_Nm[20];
    char addrss[20];
    char stdnt_grd[3];
    char stdnt_gndr[2];
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


/*----------------------------------------Global Variables-----------------------------------------*/

static List inpt, *inptPtr=&inpt;

/*--------------------------------------InLine Functions--------------------------------------------*/

static inline void Dsply_Stdnt_Inf(List *lPtr) /*To Display Students Info After Sorting Alphabetically*/
{/*Beginning Of static inline void Dsply_Stdnt_Inf(List *lPtr)*/
    StudentNode *tmPtr2=lPtr->top;
    uint16 i;

    printf("%-21s","Name");
    printf("%-10s","Gender");
    printf("%-15s","Birthday");
    printf("%-20s","Phone Number");
    printf("%-30s","Address");
    printf("%-10s","Grade");
    printf("%-10s\n","ID");
    printf("--------------------------------------------------------------------------------------------------------------\n");

    for(i=0;i<lPtr->size;i++)
    { /*Beginning Of for(i=0;i<lPtr->size;i++)*/

        printf("%-21s",tmPtr2->entry->stdnt_Nm);
        printf("%-10s",tmPtr2->entry->stdnt_gndr);
        printf("%02hu/%02hu/%04hu     ",tmPtr2->entry->brthdy.dy,tmPtr2->entry->brthdy.mnth,tmPtr2->entry->brthdy.yr);
        printf("%03hu-%-16lu",tmPtr2->entry->cc_ph,tmPtr2->entry->rst_ph);
        printf("%-30s",tmPtr2->entry->addrss);
        printf("%-10s",tmPtr2->entry->stdnt_grd);
        printf("%-10hu\n\n",tmPtr2->entry->id);

        tmPtr2 = tmPtr2->next;

    } /*End of 	for(i=0;i<lPtr->size;i++)*/
} /*End Of static inline void Dsply_Stdnt_Inf(List *lPtr)*/


static inline void Dsply_Stdnt_Rnk(List *lPtr)
{
    printf("%-21s","Name");
    printf("%-10s","Gender");
    printf("%-20s","Phone Number");
    printf("%-10s","Grade");
    printf("%-10s","ID");
    printf("%-10s\n","CS Score");
    printf("--------------------------------------------------------------------------------\n");

    /*Displaying Sorted Elements According To Their Rank*/
    StudentNode *tmPtr2=lPtr->top;
    uint16 i;

    for(i=0;tmPtr2!=NULL;i++)
    { /*Beginning Of for(i=0;tmPtr2!=NULL;i++)*/

        printf("%-21s",tmPtr2->entry->stdnt_Nm);
        printf("%-10s",tmPtr2->entry->stdnt_gndr);
        printf("%03hu-%-16lu",tmPtr2->entry->cc_ph,tmPtr2->entry->rst_ph);
        printf("%-10s",tmPtr2->entry->stdnt_grd);
        printf("%-10hu",tmPtr2->entry->id);
        printf("%-10hu\n\n",tmPtr2->entry->csScr);

        tmPtr2 = tmPtr2->next;

    } /*End Of for(i=0;tmPtr2!=NULL;i++)*/

}


/*------------------------------------Function_Declaration-----------------------------------------*/
void CreateList(List *lPtr);
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
void MinuDisp(void (*fun)());







#endif /* SMS_HEADER_H_ */
