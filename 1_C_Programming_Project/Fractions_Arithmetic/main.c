/*****************************************************************************************************
 * Assume that the fraction structure contains two members: numerator and denominator(both of type int).
 *
 * Write functions that perform the following operations on fractions:
 *
 * 		(a) Reduce the fraction f to lowest terms. Hint: To reduce a fraction to lowest terms,
 *     		first compute the greatest common divisor (GCD) of the numerator and denominator.
 *     		Then divide both the numerator and denominator by the GCD.
 * 		(b) Add the fractions f1 and f2.
 * 		(c) Subtract the fraction f2 from the fraction f1.
 * 		(d) Multiply the fractions f1 and f2.
 * 		(e) Divide the fraction f1. by the fraction f2.
 * 		(f) The fractions f , f1, and f2 will be arguments of type struct fraction: each function
 *    		will return a value of type struct f ract ion. The fractions returned by the functions in
 *     		parts (b)-(e) should be reduced to lowest terms. Hint: You may use the function from
 *     		part (a) to help write the functions in parts (b)-(e).
 *****************************************************************************************************/

#include"heads.h"

int main()
{
	frctn f1,f2,f;
	frctn *f1Ptr=NULL,*f2Ptr=NULL,*fPtr=NULL;
	unsigned short int opSlct;


	f1Ptr=&f1;
	f2Ptr=&f2;
	fPtr=&f;

	while(1)
	{
		opSlct=(unsigned short int)Linpt("#######################################"
										"\n# Choose 1:To Get GCD                 #\n"
								 	 	"#        2:To Reduce Fraction         #\n"
								 	 	"#        3:To Add Two Fraction        #\n"
								 	 	"#        4:To Subtract Two Fraction   #\n"
								 	 	"#        5:To Multiply Two Fraction   #\n"
								 	 	"#        6:To Divide Two Fraction     #\n"
		 	 							"#        7:To Exit                    #\n"
										"#######################################\n"
										"Enter Your Choice:");

		OpSelect(opSlct,f1Ptr,f2Ptr,fPtr);
	}


	return 0;
}
