/***************************************************************************************************
 * Project Name: School Management System
 * File Name:	 SMS_functions.h
 * Author:		 Ahmed M. AbdEl-kareem
 * Description:  Used Functions in The Project
 ***************************************************************************************************/

#include"SMS_Header.h"


void MainMenu() /*To Welcome The User and Provides The Activities He Can Do On Data*/
{ /*Beginning of MainMenu()*/
	printf("#---------------------------------------------------------------------------------#\n");
	printf("#---------------------------------------------------------------------------------#\n");
	printf("#---------------------***************************************---------------------#\n");
	printf("#---------------------*-Welcome To School Management System-*---------------------#\n");
	printf("#---------------------*---------[Linked List Based]---------*---------------------#\n");
	printf("#---------------------*-***********************************-*---------------------#\n");
	printf("#---------------------*----------Brought To You By----------*---------------------#\n");
	printf("#---------------------*---Eng.Ahmad Muhammad Abd-Elkareem---*---------------------#\n");
	printf("#---------------------*-------NTI Student May\'2022----------*---------------------#\n");
	printf("#---------------------*-------------------------------------*---------------------#\n");
	printf("#---------------------***************************************---------------------#\n");
	printf("#---------------------------------------------------------------------------------#\n");
	printf("#---------------------------------------------------------------------------------#\n");
	printf("#----------------Here is Your Menu For The Activities You Can Do------------------#\n");
	printf("#-Enter:--------------------------------------------------------------------------#\n");
	printf("#-------1)To Enter A New Student--------------------------------------------------#\n");
	printf("#-------2)To Delete A Student-----------------------------------------------------#\n");
	printf("#-------3)To List Your Students---------------------------------------------------#\n");
	printf("#-------4)To Edit A Student Data--------------------------------------------------#\n");
	printf("#-------5)To Display Students According To Their Rank Of Their Score--------------#\n");
	printf("#-------6)To Update Students Score------------------------------------------------#\n");
	printf("#-------7)To Get Total Number of Students-----------------------------------------#\n");
	printf("#-------8)To Exit-----------------------------------------------------------------#\n");
	printf("#---------------------------------------------------------------------------------#\n");
	printf("#---------------------------------------------------------------------------------#\n\n");
} /*End Of MainMenu()*/

/*-------------------------------------------------------------------------------------------------*/

void InMenu() /* To Remind The User of The Other Activities After Each Activity He Did*/
{ /*Beginning of InMenu() */
	printf("\n\n#-Enter:--------------------------------------------------------------------------#\n");
	printf("#-------1)To Enter A New Student--------------------------------------------------#\n");
	printf("#-------2)To Delete A Student-----------------------------------------------------#\n");
	printf("#-------3)To List Your Students---------------------------------------------------#\n");
	printf("#-------4)To Edit A Student Data--------------------------------------------------#\n");
	printf("#-------5)To Display Students According To Their Rank Of Their Score--------------#\n");
	printf("#-------6)To Update Students Score------------------------------------------------#\n");
	printf("#-------7)To Get Total Number of Students-----------------------------------------#\n");
	printf("#-------8)To Exit-----------------------------------------------------------------#\n");
	printf("#---------------------------------------------------------------------------------#\n\n");
} /*End Of InMenu()*/

/*-------------------------------------------------------------------------------------------------*/

void CreateList(List *lPtr) /*To Create A list Whom The Students Nodes Began To Exist*/
{ /*Beginning of CreateList(List *lPtr)*/

	lPtr->top=NULL;
	lPtr->size=0;

} /*End Of CreateList(List *lPtr)*/

/*-------------------------------------------------------------------------------------------------*/

void NewStudent(List *lPtr) /*To Create A New Student Node In The Linked List*/
{ /*Beginning Of NewStudent(List *lPtr)*/

	/*Creating a Pointer ePtr In Stack Which Points To An Authorized Location
	 * In Heap Which Holds The Entries */

	StudentEntry *ePtr=(StudentEntry *)malloc(sizeof(StudentEntry));

	/*Creating a Pointer nPtr In Stack Which Points To An Authorized Location
	 * In Heap Which Holds The Node of The Student */

	StudentNode *nPtr=(StudentNode *)malloc(sizeof(StudentNode));

	nPtr->entry=ePtr;

	printf("Enter Student Name:");
	fflush(stdin);fflush(stdout);
	gets(nPtr->entry->stdnt_Nm);
	printf("\n");

	printf("Enter Student Gender :");
	fflush(stdin);fflush(stdout);
	gets(nPtr->entry->stdnt_gndr);
	printf("\n");

	printf("Enter Student Birthday:");
	fflush(stdin);fflush(stdout);
	scanf("%02hu/%02hu/%04hu",&(nPtr->entry->brthdy.dy),&(nPtr->entry->brthdy.mnth),&(nPtr->entry->brthdy.yr));
	printf("\n");

	printf("Enter Student Phone Number(xxx-xxxxxxxx):");
	fflush(stdin);fflush(stdout);
    scanf("%03hu-%08lu",&(nPtr->entry->cc_ph),&(nPtr->entry->rst_ph));
	printf("\n");

	printf("Enter Student Address:");
	fflush(stdin);fflush(stdout);
	gets(nPtr->entry->addrss);
	printf("\n");

	printf("Enter Student Grade:");
	fflush(stdin);fflush(stdout);
	gets(nPtr->entry->stdnt_grd);
	printf("\n");

	printf("Enter Student ID:");
	fflush(stdin);fflush(stdout);
	scanf("%hu",&(nPtr->entry->id));
	printf("\n");

	/*	printf("Enter Student CS Score:");
	fflush(stdin);fflush(stdout);
	scanf("%hu",&(nPtr->entry->csScr));
	printf("\n");*/

	nPtr->entry->csScr=0;

	nPtr->next=lPtr->top;
	lPtr->top=nPtr;
	lPtr->size++;
} /*End Of NewStudent(List *lPtr)*/

/*-------------------------------------------------------------------------------------------------*/

void DeleteStudent(List *lPtr) /*To Delete A Student Node From The Linked List*/
{ /*Beginning Of DeleteStudent(List *lPtr)*/
	uint16 i,pos;
	uint16 s_id;

	StudentNode *tmPtr=NULL;
	StudentNode *nPtr=NULL;

	printf("Enter Student ID To Be Deleted:");
	fflush(stdin);fflush(stdout);
	scanf("%hu",&s_id);
	printf("\n\n");

	pos=SrchID(s_id,lPtr);

	if(pos>=0 && pos<lPtr->size)
	{ /*Beginning Of Outer If*/

		if(pos==0)/*Inner If To Check Whether The Needed To Be Deleted In First Position */
		{ /*Beginning Of Inner If*/
			nPtr=lPtr->top;
			lPtr->top=nPtr->next;
			free(nPtr);
		} /*End Of Inner If*/

		else /*Else Of The Inner If*/
		{ /*Beginning Of Else Of The Inner If*/
			tmPtr=lPtr->top;

			for(i=1;i<=pos-1;i++) /*To Move TmPtr Along The List Until The Needed Position */
			{ /*Beginning Of For*/
				tmPtr=tmPtr->next;
			} /*End Of For*/

			nPtr=tmPtr->next;
			tmPtr->next=nPtr->next;
			free(nPtr);
		} /*End Of Else Of The Inner If*/
		lPtr->size--;
	}/*End Of Outer If*/

	else /*Else Of The Outer If*/
	{ /*Beginning Of Else Of The Outer If*/
		printf("Not valid postion. Please enter a valid postion in the stack\n");
	} /*End Of The Else Of Outer If*/
}/*End Of DeleteStudent(List *lPtr)*/

/*-------------------------------------------------------------------------------------------------*/

void StudentList(List *lPtr) /*To Display Students Informations Sorted According To Their Names*/
{ /*Beginning Of StudentList(List *lPtr)*/
	uint16 i;
	StudentNode *tmPtr=NULL;
	StudentNode *tmPtr1=NULL;


		/*Sorting Nodes*/
		tmPtr=lPtr->top;
		tmPtr1=tmPtr->next;

		/*Checking If Size Of List Is 1 So No Sorting*/
		if(lPtr->size==1)
			{ /*Beginning Of if(lPtr->size==1)*/

				Dsply_Stdnt_Inf(lPtr);
				printf(">>--------------------------------------No Sorting For One Student------------------------------------------<<");
				return;

			} /*End Of if(lPtr->size==1)*/

			/*Sorting If There Is Only Two Students As The Second Pointer Next (tmPtr1->next) Will Be Null*/
			else if(lPtr->size==2)
			{ /*Beginning Of else if(lPtr->size==2)*/

				if(strcmp(lPtr->top->entry->stdnt_Nm,lPtr->top->next->entry->stdnt_Nm)>0)
				{/*Beginning Of if(strcmp(lPtr->top->entry->stdnt_Nm,lPtr->top->next->entry->stdnt_Nm)>0)*/

				tmPtr->next=tmPtr1->next;
				tmPtr1->next=tmPtr;
				lPtr->top=tmPtr1;

				} /*End Of if(strcmp(lPtr->top->entry->stdnt_Nm,lPtr->top->next->entry->stdnt_Nm)>0)*/

				else
				{ /*Beginning Of Else*/
					/*Nothing But MISRA*/
				} /*End Of Else*/

			} /*End Of else if(lPtr->size==2)*/

			else
			{ /*Beginning Of Outer Else*/

				for(i=0;i<lPtr->size-1;i++)
		 		{ /*Beginning Of For*/
					tmPtr=lPtr->top;
					tmPtr1=tmPtr->next;

					/*Checking For Sorting The First Two Elements(Boundary Condition)*/
					if(strcmp(lPtr->top->entry->stdnt_Nm,lPtr->top->next->entry->stdnt_Nm)>0)
					{ /*Beginning Of If(strcmp(lPtr->top->entry->stdnt_Nm,lPtr->top->next->entry->stdnt_Nm)>0)*/
						lPtr->top=lPtr->top->next;
						tmPtr->next=tmPtr->next->next;
						lPtr->top->next=tmPtr;
					} /*End Of If(strcmp(lPtr->top->entry->stdnt_Nm,lPtr->top->next->entry->stdnt_Nm)>0)*/

					else
					{ /*Beginning Of Else*/
						/*Nothing But MISRA*/
					} /*End Of Else*/

					/*Reseting The tmPtr and tmPtr1 So that tmPtr Points To The Node Before The Nodes To Be Sorted
					 * and tmPtr1 Points To The First Node Of The Two Nodes To Be Sorted*/
					tmPtr=lPtr->top;
					tmPtr1=tmPtr->next;

					/*Looping With Checking To Sort The Nodes Along The List Until tmPtr1->next->next==NULL*/
					while(tmPtr1->next->next!=NULL)
					{ /*Beginning Of while(tmPtr1->next->next!=NULL)*/

						if(strcmp(tmPtr->next->entry->stdnt_Nm,tmPtr1->next->entry->stdnt_Nm)>0)
						{ /*Beginning Of if(strcmp(tmPtr->next->entry->stdnt_Nm,tmPtr1->next->entry->stdnt_Nm)>0)*/

							tmPtr->next=tmPtr1->next;
							tmPtr1->next=tmPtr->next->next;
							tmPtr->next->next=tmPtr1;

						} /*End Of if(strcmp(tmPtr->next->entry->stdnt_Nm,tmPtr1->next->entry->stdnt_Nm)>0)*/

						else
						{ /*Beginning Of Else*/
							/*Nothing But MISRA*/
						} /*End Of Else*/

					/* Moving The Pointing Pointers Along The List*/
						tmPtr = tmPtr->next;
						tmPtr1=tmPtr->next;
					} /*End Of while(tmPtr1->next->next!=NULL)*/

					/*Checking For Sorting The Last Two Elements(Boundary Condition)*/
					if(tmPtr1->next->next==NULL)
					{ /*Beginning Of if(tmPtr1->next->next==NULL)*/

						if(strcmp(tmPtr->next->entry->stdnt_Nm,tmPtr1->next->entry->stdnt_Nm)>0)
						{ /*Beginning Of if(strcmp(tmPtr->next->entry->stdnt_Nm,tmPtr1->next->entry->stdnt_Nm)>0)*/

							tmPtr->next=tmPtr1->next;
							tmPtr1->next=NULL;
							tmPtr->next->next=tmPtr1;

						} /*End Of if(strcmp(tmPtr->next->entry->stdnt_Nm,tmPtr1->next->entry->stdnt_Nm)>0)*/

						else
						{ /*Beginning Of Else*/
							/*Nothing But MISRA*/
						} /*End Of Else*/

					} /*End Of if(tmPtr1->next->next==NULL)*/

					else
					{ /*Beginning Of Else*/
						/*Nothing But MISRA*/
					} /*End Of Else*/

				} /*End Of For*/

			} /*End Of Outer Else*/

			/*Displaying Sorted Elements According To Their Names*/
			Dsply_Stdnt_Inf(lPtr);

}/*End Of StudentList(List *lPtr)*/

/*-------------------------------------------------------------------------------------------------*/

void StudentEdit(List *lPtr) /*Edit A Student Info According To Its ID*/
{ /*Beginning Of StudentEdit(List *lPtr)*/
	StudentNode *tmPtr=lPtr->top;
	uint16 i,pos;
	uint16 s_id;

	printf("Enter Student ID To Be Edited:");
	fflush(stdin);fflush(stdout);
	scanf("%hu",&s_id);
	printf("\n");

	pos=SrchID(s_id,lPtr);

	if(pos>=0 && pos<lPtr->size)
	{ /*Beginning Of Outer If*/

			tmPtr=lPtr->top;

			for(i=0;i<=pos-1;i++) /*To Move TmPtr Along The List Until The Needed Position */
			{ /*Beginning Of For*/
				tmPtr=tmPtr->next;
			} /*End Of For*/

			printf("Enter Student Name:");
			fflush(stdin);fflush(stdout);
			gets(tmPtr->entry->stdnt_Nm);
			printf("\n");

			printf("Enter Student Gender :");
			fflush(stdin);fflush(stdout);
			gets(tmPtr->entry->stdnt_gndr);
			printf("\n");

			printf("Enter Student Birthday:");
			fflush(stdin);fflush(stdout);
			scanf("%02hu/%02hu/%04hu",&(tmPtr->entry->brthdy.dy),&(tmPtr->entry->brthdy.mnth),&(tmPtr->entry->brthdy.yr));
			printf("\n");

            printf("Enter Student Phone Number(xxx-xxxxxxxx):");
            fflush(stdin);fflush(stdout);
            scanf("%03hu-%08lu",&(tmPtr->entry->cc_ph),&(tmPtr->entry->rst_ph));
            printf("\n");

			printf("Enter Student Address:");
			fflush(stdin);fflush(stdout);
			gets(tmPtr->entry->addrss);
			printf("\n");

			printf("Enter Student Grade:");
			fflush(stdin);fflush(stdout);
			gets(tmPtr->entry->stdnt_grd);
			printf("\n");


	}/*End Of Outer If*/

	else /*Else Of The Outer If*/
	{ /*Beginning Of Else Of The Outer If*/
		printf("Not valid postion. Please enter a valid postion in the stack\n");
	} /*End Of The Else Of Outer If*/

} /*End Of StudentEdit(List *lPtr)*/

/*-------------------------------------------------------------------------------------------------*/

void RankStudent(List *lPtr) /*To Display Students Informations Sorted According To Their CS Score*/
{ /*Beginning of RankStudent(List *lPtr)*/
	uint16 i;
	StudentNode *tmPtr=NULL;
	StudentNode *tmPtr1=NULL;

	/*Sorting Nodes*/

	tmPtr=lPtr->top;
	tmPtr1=tmPtr->next;

	/*Checking If Size Of List Is 0 So No Data*/
	if(lPtr->size==0)
	{ /*Beginning Of if(lPtr->size==0)*/

		Dsply_Stdnt_Inf(lPtr);
		printf(">>------------------------------------------There is No Data------------------------------------------------<<");
		return;

	} /*End Of if(lPtr->size==0)*/

	/*Checking If Size Of List Is 1 So No Sorting*/
	if(lPtr->size==1)
	{ /*Beginning Of if(lPtr->size==1)*/

		Dsply_Stdnt_Rnk(lPtr);
		printf(">>------------------------No Sorting For One Student----------------------------<<");
		return;

	} /*End Of if(lPtr->size==1)*/

	/*Sorting If There Is Only Two Students As The Second Pointer Next (tmPtr1->next) Will Be Null*/
	else if(lPtr->size==2)
	{ /*Beginning Of else if(lPtr->size==2)*/

		if(lPtr->top->entry->csScr<lPtr->top->next->entry->csScr)
		{/*Beginning Of if(lPtr->top->entry->csScr<lPtr->top->next->entry->csScr)*/

		tmPtr->next=tmPtr1->next;
		tmPtr1->next=tmPtr;
		lPtr->top=tmPtr1;

		} /*End Of if(lPtr->top->entry->csScr<lPtr->top->next->entry->csScr)*/

		else
		{ /*Beginning Of Else*/
			/*Nothing But MISRA*/
		} /*End Of Else*/

	} /*End Of else if(lPtr->size==2)*/

	else
	{ /*Beginning Of Outer Else*/

		for(i=0;i<lPtr->size-1;i++)
		{ /*Beginning Of for(i=0;i<lPtr->size-1;i++)*/
			tmPtr=lPtr->top;
			tmPtr1=tmPtr->next;

			/*Checking For Sorting The First Two Elements(Boundary Condition)*/
			if(lPtr->top->entry->csScr<lPtr->top->next->entry->csScr)
			{ /*Beginning Of if(lPtr->top->entry->csScr<lPtr->top->next->entry->csScr)*/

				lPtr->top=lPtr->top->next;
				tmPtr->next=tmPtr->next->next;
				lPtr->top->next=tmPtr;

			} /*End Of if(lPtr->top->entry->csScr<lPtr->top->next->entry->csScr)*/

			else
			{ /*Beginning Of Else*/
				/*Nothing But MISRA*/
			} /*End Of Else*/

			/*Reseting The tmPtr and tmPtr1 So that tmPtr Points To The Node Before The Nodes To Be Sorted
			 * and tmPtr1 Points To The First Node Of The Two Nodes To Be Sorted*/
			tmPtr=lPtr->top;
			tmPtr1=tmPtr->next;

			/*Looping With Checking To Sort The Nodes Along The List Until tmPtr1->next->next==NULL*/
			while(tmPtr1->next->next!=NULL)
			{ /*Beginning Of while(tmPtr1->next->next!=NULL)*/

				if(tmPtr->next->entry->csScr<tmPtr1->next->entry->csScr)
				{
					tmPtr->next=tmPtr1->next;
					tmPtr1->next=tmPtr->next->next;
					tmPtr->next->next=tmPtr1;
				}

				else
				{ /*Beginning Of Else*/
					/*Nothing But MISRA*/
				} /*End Of Else*/

				/* Moving The Pointing Pointers Along The List*/
				tmPtr = tmPtr->next;
				tmPtr1=tmPtr->next;

			} /*End Of while(tmPtr1->next->next!=NULL)*/

			/*Checking For Sorting The Last Two Elements(Boundary Condition)*/
			if(tmPtr1->next->next==NULL)
			{ /*Beginning Of if(tmPtr1->next->next==NULL)*/

				if(tmPtr->next->entry->csScr<tmPtr1->next->entry->csScr)
				{ /*Beginning Of if(tmPtr->next->entry->csScr<tmPtr1->next->entry->csScr)*/

					tmPtr->next=tmPtr1->next;
					tmPtr1->next=NULL;
					tmPtr->next->next=tmPtr1;

				} /*End Of if(tmPtr->next->entry->csScr<tmPtr1->next->entry->csScr)*/


				else
				{ /*Beginning Of Else*/
					/*Nothing But MISRA*/
				} /*End Of Else*/

			} /*End Of if(tmPtr1->next->next==NULL)*/

			else
			{ /*Beginning Of Else*/
				/*Nothing But MISRA*/
			} /*End Of Else*/

		} /*End Of for(i=0;i<lPtr->size-1;i++)*/

	} /*End Of Outer Else*/

	/*Displaying Sorted Elements According To Their Rank*/
	Dsply_Stdnt_Rnk(lPtr);

}/*End Of RankStudent(List *lPtr)*/

/*-------------------------------------------------------------------------------------------------*/

void ScoreStudent(List *lPtr) /*To Edit Students CS Scores*/
{ /*Beginning Of ScoreStudent(List *lPtr)*/
	StudentNode *tmPtr=lPtr->top;
	uint16 i=0;

	for(i=1;(i<=lPtr->size);i++)
	{ /*Beginning Of For*/
		printf("Student:%-20s\tID:%-10hu\tLastScore:%-10hu\tNewScore:",tmPtr->entry->stdnt_Nm
				,tmPtr->entry->id
				,tmPtr->entry->csScr);
		fflush(stdin);fflush(stdout);
		scanf("%hu",&(tmPtr->entry->csScr));
		printf("\n");

		tmPtr = tmPtr->next;
	} /*End Of For*/

} /*End Of ScoreStudent(List *lPtr)*/

/*-------------------------------------------------------------------------------------------------*/

uint16 SrchID(uint16 id,List *lPtr) /*To Search A Student According To His ID
									And Return The Postion Of The Node In The List*/
{/*Beginnning Of SrchID(uint16 id,List *lPtr)*/
	StudentNode *tmPtr=lPtr->top;
	uint16 i;

	for(i=0;tmPtr!=NULL;i++)
		{/*Beginning Of For*/
			if(tmPtr->entry->id==id)
			{/*Beginning Of If*/
				return i;
			}/*End Of If*/

			else
			{ /*Beginning Of Else*/
				tmPtr = tmPtr->next;
			} /*End Of Else*/
		}/*End Of For*/

	return -1;

}/*End Of SrchID(uint16 id,List *lPtr)*/

/*-------------------------------------------------------------------------------------------------*/

void StudentsTotal(List *lPtr) /*To Display Total Number Of Students Are Existed*/
{ /*Beginning Of StudentsTotal(List *lPtr)*/
	printf("Total Number Of Students:%lu\n\n",lPtr->size);
} /*End Of StudentsTotal(List *lPtr)*/

/*-------------------------------------------------------------------------------------------------*/

void SlctActvty() /*To Select Between Activities On Data Of Students*/
{ /*Beginning Of SlctActvty*/
	uint16 slct;

	void(*fun[])(List *lPtr)={NewStudent,DeleteStudent,StudentList,
							  StudentEdit,RankStudent,ScoreStudent,
							  StudentsTotal};

	/*Main Menu To Welcome And Show Options Using CallBack Method*/
	MinuDisp(MainMenu);

	while(1)
	{/*While Beginning*/
		printf("\nEnter The Activity Number You Want to Do:");
		fflush(stdin);fflush(stdout);
		scanf("%hu",&slct);
		printf("\n\n");

		switch(slct)
		{ /*Switch Beginning*/

			/*-------------------------------------Entering a Student Data--------------------------------------*/

			case 1:
			{/*case 1 Start*/
				printf("You Are Entering a Student Data\n");
				printf("-------------------------------\n\n");
				fun[slct-1](inptPtr);  /*Using slct-1 as index as array index begins from 0*/
				MinuDisp(InMenu);
				break;
			}/*case 1 End*/

			/*-------------------------------------Delete a Student Data-----------------------------------------*/

			case 2:
			{/*case 2 Start*/
				printf("You Are Deleting a Student Data\n");
				printf("-------------------------------\n\n");

				/*Checking If Size Of List Is 0 So No Data*/
				if(inptPtr->size==0)
				{ /*Beginning Of if(lPtr->size==0)*/

					printf(">>------------------------------------------There is No Data------------------------------------------------<<");

				} /*End Of if(lPtr->size==0)*/

				else
				{ /*Beginning Of Else Of if(lPtr->size==0)*/

					fun[slct-1](inptPtr);  /*Using slct-1 as index as array index begins from 0*/

				}/*End Of Else Of if(lPtr->size==0)*/

				MinuDisp(InMenu);
				break;
			}/*case 2 End*/

			/*------------------------Displaying Alphabetically Sorted Students List-------------------------------*/

			case 3:
			{/*case 3 Start*/
				printf("You Are Displaying Students Sorted By Their Names\n");
				printf("-------------------------------------------------\n\n");

				/*Checking If Size Of List Is 0 So No Data*/
				if(inptPtr->size==0)
				{ /*Beginning Of if(lPtr->size==0)*/

					printf(">>------------------------------------------There is No Data------------------------------------------------<<");

				} /*End Of if(lPtr->size==0)*/

				else
				{ /*Beginning Of Else Of if(lPtr->size==0)*/

					fun[slct-1](inptPtr);  /*Using slct-1 as index as array index begins from 0*/

				}/*End Of Else Of if(lPtr->size==0)*/

				MinuDisp(InMenu);
				break;

			}/*case 3 End*/

			/*--------------------------------------Editing A Student Data-----------------------------------------*/

			case 4: /*Editing A Student Data*/
			{/*case 4 Start*/
				printf("You Are Editing a Student\n");
				printf("-------------------------\n");

				/*Checking If Size Of List Is 0 So No Data*/
				if(inptPtr->size==0)
				{ /*Beginning Of if(lPtr->size==0)*/

					printf(">>------------------------------------------There is No Data------------------------------------------------<<");

				} /*End Of if(lPtr->size==0)*/

				else
				{ /*Beginning Of Else Of if(lPtr->size==0)*/

					fun[slct-1](inptPtr);  /*Using slct-1 as index as array index begins from 0*/

				}/*End Of Else Of if(lPtr->size==0)*/

				MinuDisp(InMenu);
				break;
			}/*case 4 End*/

			/*-----------------------------Displaying Sorted Scores Of Students List---------------------------------*/

			case 5:
			{/*case 5 Start*/
				printf("You Are Displaying Students Sorted By Their Scores\n");
				printf("--------------------------------------------------\n\n");

				/*Checking If Size Of List Is 0 So No Data*/
				if(inptPtr->size==0)
				{ /*Beginning Of if(lPtr->size==0)*/

					printf(">>------------------------------------------There is No Data------------------------------------------------<<");

				} /*End Of if(lPtr->size==0)*/

				else
				{ /*Beginning Of Else Of if(lPtr->size==0)*/

					fun[slct-1](inptPtr);  /*Using slct-1 as index as array index begins from 0*/

				}/*End Of Else Of if(lPtr->size==0)*/

				MinuDisp(InMenu);
				break;
			}/*case 5 End*/

			/*--------------------------------------Updating Students Scores---------------------------------------*/

			case 6:
			{/*case 6 Start*/
				printf("You Are Updating Students' Score\n");
				printf("--------------------------------\n\n");

				/*Checking If Size Of List Is 0 So No Data*/
				if(inptPtr->size==0)
				{ /*Beginning Of if(lPtr->size==0)*/

					printf(">>------------------------------------------There is No Data------------------------------------------------<<");

				} /*End Of if(lPtr->size==0)*/

				else
				{ /*Beginning Of Else Of if(lPtr->size==0)*/

					fun[slct-1](inptPtr);  /*Using slct-1 as index as array index begins from 0*/

				}/*End Of Else Of if(lPtr->size==0)*/

				MinuDisp(InMenu);
				break;
			}/*case 6 End*/

			/*---------------------------Displaying Total Number Of Students In The List----------------------------*/

			case 7:
			{/*case 7 Start*/
				printf("You Are Getting Total Number Of Students\n");
				printf("----------------------------------------\n\n");
				fun[slct-1](inptPtr);
				MinuDisp(InMenu);
				break;
			}/*case 7 End*/

			case 8: /*To Exit The Program*/
			{/*case 8 Start*/
				exit(0);
			}/*case 8 End*/

			 /*-----------------------------------If Misselect The Activity-----------------------------------------*/

			default:
			{/*default Start*/
				printf(">--------------------------------Invalid Activity--------------------------------<\n\n");
				MinuDisp(InMenu);
				break;
			}/*default end*/

		}/*Switch End*/

	}/*While End*/

}/*SlctActvty End*/

/*-------------------------------------------------------------------------------------------------*/

void MinuDisp(void (*fun)())
{
	fun();
}
