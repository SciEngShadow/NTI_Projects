#include"heads.h"


/****************GreatestCommonDivisor*****************/
unsigned short int GCD(frctn *fPtr)
{
	unsigned short int i,varGCD;

	if((fPtr->numerator<0))
		{
			fPtr->numerator=fPtr->numerator*(-1);

			for(i=1;(i<=(fPtr->numerator))&&(i<=(fPtr->denominator));i++)
			{
				if(((fPtr->numerator%i)==0)&&((fPtr->denominator%i)==0))
				{
					varGCD=i;
				} /*end inner if*/
			} /*end for*/

			fPtr->numerator=fPtr->numerator*(-1);

		} /*end outer if*/

	else if((fPtr->denominator<0))
		{
			fPtr->denominator=fPtr->denominator*(-1);

			for(i=1;(i<=(fPtr->numerator))&&(i<=(fPtr->denominator));i++)
			{
				if(((fPtr->numerator%i)==0)&&((fPtr->denominator%i)==0))
				{
					varGCD=i;
				} /*end inner if*/
			} /*end for*/

			fPtr->denominator=fPtr->denominator*(-1);

		} /*end outer if*/

	else
	{
		for(i=1;(i<=(fPtr->numerator))&&(i<=(fPtr->denominator));i++)
		{
			if(((fPtr->numerator%i)==0)&&((fPtr->denominator%i)==0))
			{
				varGCD=i;
			} /*end inner if*/
		} /*end for*/

	}

	return varGCD;
}	/* EndOfGCD */

/*********************************************************************************************/


/****************FractionReduction*****************/
void Rfrctn(frctn *fPtr,unsigned short int fGCD)
{
	fGCD=GCD(fPtr);

	printf("\nTotal Fraction Before Reduction:  %ld / %ld\n",fPtr->numerator,fPtr->denominator);

	if((fPtr->numerator<0))
	{
		fPtr->numerator=fPtr->numerator*(-1);
		fPtr->numerator=(fPtr->numerator/fGCD)*(-1);
		fPtr->denominator=fPtr->denominator/fGCD;

	}

	else
	{
		fPtr->numerator=fPtr->numerator/fGCD;
		fPtr->denominator=fPtr->denominator/fGCD;
	}

	printf("\nTotal Fraction After Reduction:  %ld / %ld\n",fPtr->numerator,fPtr->denominator);

}	/* EndOfRfrctn */

/*********************************************************************************************/


/****************Swapping*****************/
void Swap(long int *ptr1,long int *ptr2)
{
	long int temp;

	temp=*ptr1;
	*ptr1=*ptr2;
	*ptr2=temp;
}	/* EndOfSwap */

/*********************************************************************************************/



/****************FractionsAddition*****************/
void Add(frctn *f1Ptr,frctn *f2Ptr,frctn *fPtr)
{
	long int comDe,lNu,rNu;

	comDe=(f1Ptr->denominator)*(f2Ptr->denominator);
	lNu=(f1Ptr->numerator)*(f2Ptr->denominator);
	rNu=(f2Ptr->numerator)*(f1Ptr->denominator);
	fPtr->numerator=lNu+rNu;
	fPtr->denominator=comDe;
	Rfrctn(fPtr,GCD(fPtr));

}	/* EndOfAdd */
/*********************************************************************************************/


/****************FractionsSubtraction*****************/
void Sub(frctn *f1Ptr,frctn *f2Ptr,frctn *fPtr)
{
	long int comDe,lNu,rNu;

	comDe=(f1Ptr->denominator)*(f2Ptr->denominator);
	lNu=(f1Ptr->numerator)*(f2Ptr->denominator);
	rNu=(f2Ptr->numerator)*(f1Ptr->denominator);
	(fPtr->numerator)=lNu-rNu;
	(fPtr->denominator)=comDe;
	Rfrctn(fPtr,GCD(fPtr));
}	/* EndOfSub */
/*********************************************************************************************/


/****************FractionsMultiplication*****************/
void Mul(frctn *f1Ptr,frctn *f2Ptr,frctn *fPtr)
{
	fPtr->numerator=(f1Ptr->numerator)*(f2Ptr->numerator);
	fPtr->denominator=(f1Ptr->denominator)*(f2Ptr->denominator);
	Rfrctn(fPtr,GCD(fPtr));
}	/* EndOfMul */
/*********************************************************************************************/


/****************FractionsDivision*****************/
void Div(frctn *f1Ptr,frctn *f2Ptr,frctn *fPtr)
{
	Swap(&(f2Ptr->numerator),&(f2Ptr->denominator));
	if((f2Ptr->denominator)<0)
	{
		f2Ptr->denominator=f2Ptr->denominator*(-1);
		f2Ptr->numerator=f2Ptr->numerator*(-1);
		fPtr->numerator=(f1Ptr->numerator)*(f2Ptr->numerator);
		fPtr->denominator=(f1Ptr->denominator)*(f2Ptr->denominator);
	}
	else
	{
		fPtr->numerator=(f1Ptr->numerator)*(f2Ptr->numerator);
		fPtr->denominator=(f1Ptr->denominator)*(f2Ptr->denominator);
	}

	Rfrctn(fPtr,GCD(fPtr));
}	/* EndOfDiv */
/*********************************************************************************************/


/****************LongIntInput*****************/
long int Linpt(char str[100])
{
	long int finpt;
	printf("%s",str);
	fflush(stdin);fflush(stdout);
	scanf("%ld",&finpt);

	return finpt;
}
/*********************************************************************************************/


/****************Operation Selection*****************/

void OpSelect(unsigned short int fOpSlct,frctn *f1Ptr,frctn *f2Ptr,frctn *fPtr)
{
	void (*fnPtr[])(frctn *f1Ptr,frctn *f2Ptr,frctn *fPtr)={Add,Sub,Mul,Div};

	switch(fOpSlct)
		{
			case 1:
			{
				printf("--->Get GCD<---\n\n");

				f1Ptr->numerator=Linpt("Enter Fraction Numerator:");
				f1Ptr->denominator=Linpt("Enter Fraction Denominator:");
				printf("GCD=%hu",GCD(f1Ptr));
				break;
			}
			case 2:
			{
				printf("--->Reduce Fraction<---\n\n");

				f1Ptr->numerator=Linpt("Enter Fraction Numerator:");
				f1Ptr->denominator=Linpt("Enter Fraction Denominator:");
				Rfrctn(f1Ptr,GCD(f1Ptr));
				printf("Fraction After Reduction: %ld/%ld",f1Ptr->numerator,f1Ptr->denominator);
				break;
			}
			default:
			{

				if(fOpSlct==3)
				{
					printf("\n\n--->Fraction Addition<---\n\n");

					f1Ptr->numerator=Linpt("Enter First Fraction Numerator:");
					f1Ptr->denominator=Linpt("Enter First Fraction Denominator:");

					f2Ptr->numerator=Linpt("Enter Second Fraction Numerator:");
					f2Ptr->denominator=Linpt("Enter Second Fraction Denominator:");

					(*fnPtr[0])(f1Ptr,f2Ptr,fPtr);
					//Add(f1Ptr,f2Ptr,fPtr);

					//printf("Result:%ld/%ld",fPtr->numerator,fPtr->denominator);

					break;
				}
				else if(fOpSlct==4)
				{
					printf("\n\n--->Fraction Subtraction<---\n\n");

					f1Ptr->numerator=Linpt("Enter First Fraction Numerator:");
					f1Ptr->denominator=Linpt("Enter First Fraction Denominator:");

					f2Ptr->numerator=Linpt("Enter Second Fraction Numerator:");
					f2Ptr->denominator=Linpt("Enter Second Fraction Denominator:");

					(*fnPtr[1])(f1Ptr,f2Ptr,fPtr);
					//Sub(f1Ptr,f2Ptr,fPtr);

					//printf("Result:%ld/%ld",fPtr->numerator,fPtr->denominator);

					break;
				}
				else if(fOpSlct==5)
				{
					printf("\n\n--->Fraction Multiplication<---\n\n");

					f1Ptr->numerator=Linpt("Enter First Fraction Numerator:");
					f1Ptr->denominator=Linpt("Enter First Fraction Denominator:");

					f2Ptr->numerator=Linpt("Enter Second Fraction Numerator:");
					f2Ptr->denominator=Linpt("Enter Second Fraction Denominator:");

					(*fnPtr[2])(f1Ptr,f2Ptr,fPtr);
					//Mul(f1Ptr,f2Ptr,fPtr);

					//printf("Result:%ld/%ld",fPtr->numerator,fPtr->denominator);

					break;
				}
				else if(fOpSlct==6)
				{
					printf("\n\n--->Fraction Division<---\n\n");

					f1Ptr->numerator=Linpt("Enter First Fraction Numerator:");
					f1Ptr->denominator=Linpt("Enter First Fraction Denominator:");

					f2Ptr->numerator=Linpt("Enter Second Fraction Numerator:");
					f2Ptr->denominator=Linpt("Enter Second Fraction Denominator:");

					(*fnPtr[3])(f1Ptr,f2Ptr,fPtr);
					//Div(f1Ptr,f2Ptr,fPtr);

					//printf("Result:%ld/%ld",fPtr->numerator,fPtr->denominator);

					break;
				}
				else
				{
					break;
				}
			case 7:
				exit(1);
			}
		}
}

