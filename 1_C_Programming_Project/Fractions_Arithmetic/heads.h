#ifndef HEADS_H_
#define HEADS_H_

/*********LibeariesIncludes**********/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
/*********UserDefinedDataTypes*******/

typedef struct fraction
{
	long int numerator;
	long int denominator;

}frctn;


/*********GlobalVariables***********/

/*********FunctionsPrototypes**********/
unsigned short int GCD(frctn *fPtr);
void Rfrctn(frctn *fPtr,unsigned short int GCD);
void Swap(long *ptr1,long *ptr2);
void Add(frctn *f1Ptr,frctn *f2Ptr,frctn *fPtr);
void Sub(frctn *f1Ptr,frctn *f2Ptr,frctn *fPtr);
void Mul(frctn *f1Ptr,frctn *f2Ptr,frctn *fPtr);
void Div(frctn *f1Ptr,frctn *f2Ptr,frctn *fPtr);
long int Linpt(char str[100]);
void OpSelect(unsigned short int fOpSlct,frctn *f1Ptr,frctn *f2Ptr,frctn *fPtr);




#endif /* HEADS_H_ */
