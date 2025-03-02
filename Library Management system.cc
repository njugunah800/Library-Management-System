
//ALL THE LIBRARIES DEFINED FROM HERE
#include<stdio.h>         
#include<conio.h>         
#include <stdlib.h>	
#include<string.h>        
#include<ctype.h>
#include<dos.h>           
#include<time.h>
#include <windows.h>

//LIST OF MACROS DEFINED HERE
#define RETURNTIME 10 	// contains return date, etc
#define MAX_YR  9999
#define MIN_YR  1900
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  20
#define FILE_HEADER_SIZE  sizeof(sFileHeader)
#define FILE_NAME  "password"	
char catagories[][16]={"Mathematics","Psycology","Biology","PHYSICS","CHEMISTRY","English"}; 	
void greeting(void);
void login(void);
void mainmenu(void);	
void addbooks(void);		
void deletebooks(void);		
void searchbooks(void);		
void bookslist(void);
void editbooks(void);
void searchbooks(void);
void issuebooks(void);
void bookslist(void);		
void returnfunc(void);		
int  getdata();
int  checkid(int);
int t(void);
void issuerecord();			//declaration for issuing record
int s;
char findbook;
COORD coord = {0, 0}; 		//function to set coordinates to 0,0
COORD max_res,cursor_size;
void gotoxy (int x, int y)		//function that sets the cursor positiion for simply to move the cursor on your monitor screen wherever desired.
{
        coord.X = x; coord.Y = y;		//function to input X and Y coordinates 
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();		//shows the processor clock time used since the beginning of an
											//implementation defined era (normally the beginning of the program).
    while (goal > clock());
}
struct meroDate
{
    int mm,dd,yy;
};
struct books
{
    int id;
    char stname[20];
    char name[20];
    char Writer[20];
    int quantity;
    int Amount;
    int bookno;
    char cat[16];
    struct meroDate issued;
    struct meroDate duedate;
};
struct books r;
FILE *fp,*ft,*fs;	//global file pointers that can be accessed from anywhere in program
char u[30],p[30];
int main()
{
	//system("color E9");
	greeting();
    login();
    getch();
   return 0;
}
void greeting()
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Library management System Project in C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    
    printf("\n\t\t\t----------------------------------------------------------------------------");
    getch();		//it is used as a trick to hold the output screen live for a desired period of time by the user
    login();
}
void login()		//function that display login screen
{
	do{
	printf("\n\n\n\t\t\t ENTER THE LOGIN CREDENTIALSe\n\n");
	printf("\n\t\t\tUSERNAME: ");
	scanf("%s",&u);						//scanf is used to read input such as character, string, numeric data from keyboard.
	printf("\n\n\t\t\tPASSWORD: ");
	scanf("%s",&p);
	if((strcmp(u,"abhay")==0) && (strcmp(p,"1234")==0))
	{
		printf("\n\n\t\t\tLOGGED IN SUCCESSFULY");
		printf("\n\n\n\t\t\t\t PRESS ANY KEY FOR MAIN MENU.....");
		getch();
		mainmenu();
	}
	else
	{
		printf("\n\n\t\t\tHEY HEY!!!! YOU ENTERED WRONG CREDENTIALS");
	}
	
	}while("number_of_try");           //continue loop till user enter correct input  
	
}
void mainmenu()
{

    system("cls");
	int i; //local variable for switch options
	printf(" \n\n\t\t\t\tMAIN MENU ");
	printf(" \n\n\t\t\t\t1. ADD BOOKS   ");
	printf(" \n\n\t\t\t\t2. DELETE BOOKS");
	printf(" \n\n\t\t\t\t3. SEARCH BOOKS");

	printf(" \n\n\t\t\t\t4. ISSUE BOOKS");

	printf(" \n\n\t\t\t\t5. BOOK LIST");

	printf(" \n\n\t\t\t\t6. EDIT BOOKS RECORD");

	printf(" \n\n\t\t\t\t7. EXIT APPLICATION");
	t();
	printf("\n\n\t\t\tENTER YOUR CHOICE --->");
	switch(getch())
	{
		case '1':
		addbooks();
		break;
	case '2':
		deletebooks();
		break;
		case '3':
		searchbooks();
	    break;
	case '4':
		issuebooks();
	    break;
	    case '5':
		bookslist();
		break;
	    case '6':
		editbooks();
		break;
	    case '7':
	    {
		system("cls");
		delay(3000);
		exit(0);
	    }
	    default:
		{
		printf("\n\n\t\t\t\tWRONG ENTRY!!");
		if(getch())
		mainmenu();
		}

    }
}
void addbooks(void)    //function to add books
{
	system("cls");
	int i;		//local variable for switch option
	printf("\n\n\t\t\tIN WHICH DEPARTMENT YOU WANT TO PLACE BOOK");
	printf(" \n\n\t\t\t1. MATHEMATICS DEPARTMENT");
	printf(" \n\n\t\t\t2. PSYCHOLOGY DEPARTMENT");
	printf(" \n\n\t\t\t3. BIOLOGY DEPARTMENT");
	printf(" \n\n\t\t\t4. PHYSICS DEPARTMENT");
	printf(" \n\n\t\t\t5. CHEMISTRY DEPARTMENT");
	printf(" \n\n\t\t\t6. ENGLISH DEPARTMENT");
	printf(" \n\n\t\t\t5. COMPUTER SCIENCE DEPARTMENT");
	printf(" \n\n\t\t\t7. RETURN TO MAIN MENU");
	printf("\n\n\t\t\tWHAT WOULD BE YOUR CHOICE:");
	scanf("%d",&s);
	if(s==7)
	    mainmenu();
	system("cls");
	fp=fopen("Project.dat","ab+");
	if(getdata()==1)
	{
		strcpy(r.cat,catagories[s-1]);
		printf("%s",r.cat);		
		fseek(fp,0,SEEK_END);			//fseek sets the file position of the given offset
		fwrite(&r,sizeof(r),1,fp);		//size_r this is the unsigned integral type and is the result of the sizeof keyword.
		fclose(fp);
		printf("\n\n\t\t\tYOUR RECORD HAS BEEN SAVED");
		printf("\n\n\t\t\tWANNA SAVE ANY MORE.....?(Y / N):");
		if(getch()=='n')
			mainmenu();
		else
			system("cls");
			addbooks();
	}
}
int getdata()
{
	int t;
	printf("\n\t\t\tENTER THE INFORMATION BELOW");
	printf("\n\n\t\t\tDEPARTMENT --->");
	printf("%s",catagories[s-1]);
	printf("\n\n\t\t\tENTER BOOK ID --->");
	scanf("%d",&t);
	if(checkid(t) == 0)
	{
	
		printf("\n\n\t\t\tTHE BOOK IS ALREADY THERE IN %s DEPARTMENT\n",catagories[s-1]);
		getch();
		mainmenu();
		return 0;
	}
	r.id=t;
	printf("\n\n\t\t\tENTER BOOK NO");
	fflush(stdin);
	scanf("%d",&r.bookno);
	printf("\n\n\t\t\tENTER BOOK NAME --->");
	fflush(stdin);
	scanf("%s",r.name);
	printf("\n\n\t\t\tENTER BOOK WRITTER --->");
	fflush(stdin);
	scanf("%s",r.Writer);
	printf("\n\n\t\t\tENTER BOOK QUANTITY --->");
	fflush(stdin);
	scanf("%d",&r.quantity);
	printf("\n\n\t\t\tENTER PRICE OF PER BOOK --->");
	fflush(stdin);
	scanf("%d",&r.Amount);

	return 1;
}
void deletebooks()    //function that delete from file fp
{
    system("cls");
    int d;
    char another='y';
    while(another=='y')  	//cause infinite loop
    {
		system("cls");
		gotoxy(10,5);
		printf("Enter the Book ID to  delete --->");
		scanf("%d",&d);
		fp=fopen("Project.dat","rb+");
		rewind(fp);
		findbook='a';
		while(fread(&r,sizeof(r),1,fp)==1)
		{
			if(r.id==d)
			{
				gotoxy(10,7);
				printf("The book record is available");
				gotoxy(10,8);
				printf("Book name is %s",r.name);
				gotoxy(10,9);
				printf("Book No. is %d",r.bookno);
				findbook='t';
			}
		}
		if(findbook!='t')
		{
			gotoxy(10,10);
			printf("No record is found to delete the search");
			if(getch())
			mainmenu();
		}
		if(findbook=='t' )
		{
			gotoxy(10,9);
			printf("Do you want to delete it?(Y/N):");
			if(getch()=='y'||getch()=='Y')
			{
				ft=fopen("temp.dat","wb+");   //for deleting temporary files
				rewind(fp);					//sets the file position to the beginning of the file of the given stream
				while(fread(&r,sizeof(r),1,fp)==1)
				{
					if(r.id!=d)
					{
						fseek(ft,0,SEEK_CUR);			//sets current position of file
						fwrite(&r,sizeof(r),1,ft); 	  //write all items in temporary file except we want to delete
					}                              
				}
				fclose(ft);
				fclose(fp);
				remove("Project.dat");
				rename("temp.dat","Project.dat"); 		//read all items from temporary file except we want to delet
				if(findbook=='t')
				{
					gotoxy(10,10);
					printf("The record is sucessfully deleted");
					gotoxy(10,11);
					printf("Delete another record?(Y/N)");
				}
			}
			else
				mainmenu();
			fflush(stdin);		//the fflush function causes any unwritten data for that stream to be delivered to the host environment to be written to the file,
								//so the behaviour is undefined
			another=getch();
		}
	}
	gotoxy(10,15);
	mainmenu();
}
void searchbooks()	    //function that search items from file fp
{
    system("cls");
    int d;
    gotoxy(20,6);
    printf("SEARCH BOOKS ");
    gotoxy(20,10);
    printf(" 1. SEARCH BY BOOK ID");
    gotoxy(20,14);
    printf(" 2. SEARCH BY BOOK NAME");
    gotoxy( 15,20);
    printf("ENTER YOUR PREFERENCES");
    fp=fopen("Project.dat","rb+"); 		//open file in read mode
    rewind(fp);   		//sets the file position to the beginning of the file of the given stream
    switch(getch())
    {
	  case '1':
	{
	    system("cls");
	    gotoxy(25,4);
	    printf("Search Books By Id ");
	    gotoxy(20,5);
	    printf("Enter the book id:");
	    scanf("%d",&d);
	    gotoxy(20,7);
	    printf("Searching........");
	    while(fread(&r,sizeof(r),1,fp)==1)
	    {
		if(r.id==d)
		{
		    delay(2);
		    gotoxy(20,7);
		    printf("ENTERED BOOK IS AVAILABLE");
		    gotoxy(20,9);
		    printf(" BOOK ID:%d",r.id);
		    gotoxy(20,10);
		    printf(" BOOK NAME:%s",r.name);
		    gotoxy(20,11);
		    printf(" WRITER NAME:%s ",r.Writer);
		    gotoxy(20,12);
		    printf(" QUANTITY:%d ",r.quantity);
		    gotoxy(20,13);
		    printf(" AMOUNT IN :Rs.%.2f",r.Amount);
		    gotoxy(20,14);
		    printf(" BOOK NO:%d ",r.bookno);
		    
		    findbook='t';
		}

	    }
	    if(findbook!='t')  		//it checks weather the condition is entered loop or not
	    {
	    gotoxy(22,9);
		printf("\rSOORY NO RECORD FOUND");
	    }
	    gotoxy(20,17);
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
	    searchbooks();
	    else
	    mainmenu();
	    break;
	}
	case '2':
	{
	    char s[15];
	    system("cls");
	    gotoxy(25,4);
	    printf("SEARCH BOOK NAME ");
	    gotoxy(20,5);
	    printf("ENTER BOOK NAME:");
	    scanf("%s",s);
	    int d=0;
	    while(fread(&r,sizeof(r),1,fp)==1)
	    {
		if(strcmp(r.name,(s))==0) 		//it checks weather r.name is equal to s or not
		{
		    gotoxy(20,7);
		    printf("ENTERED BOOK IS AVAILABLE");
		    gotoxy(20,9);
		    printf("BOOK ID:%d",r.id);
		    gotoxy(20,10);
		    printf("BOOK NAME:%s",r.name);
		    gotoxy(20,11);
		    printf(" BOOK WRITER:%s",r.Writer);
		    gotoxy(20,12);
		    printf(" BOOK QUANTITY:%d",r.quantity);
		    gotoxy(20,13);
		    printf(" AMOUNT IN Rs.%.2f",r.Amount);
		    gotoxy(20,14);
		    printf(" BOOK NO.:%d ",r.bookno);
		   
		    d++;
		}

	    }
	    if(d==0)
	    {
	    
	    gotoxy(22,9);
		printf("\rSORRY NO RECORD FOUND");
	    }
	    gotoxy(20,17);
	    printf("WANNA TRY ANOTHER SEARCH?(Y/N)");
	    if(getch()=='y')
	    searchbooks();
	    else
	    mainmenu();
	    break;
	}
	default :
	getch();
	searchbooks();
    }
    fclose(fp);
}

void issuebooks()  	//function for issuing books
{
    int t;		//local variable for switch option

    system("cls");
    gotoxy(10,3);
    printf("  ISSUE SECTION ");
    gotoxy(10,5);
    printf(" 1--->	ISSUE A BOOK");
    gotoxy(10,7);
    printf(" 2--->  VIEW ISSUED BOOK LIST");
    gotoxy(10,9);
    printf(" 3--->  SEARCH ISSUED BOOK");
    gotoxy(10,11);
    printf(" 4--->  REMOVE ISSUED BOOK");
    gotoxy(10,14);
    printf("ENTER YOUR CHOICE--->");
    switch(getch())
    {
	case '1':  //issue book
	{
		system("cls");
		int c=0;
		char another='y';
		while(another=='y')		//infinite loop
		{
			system("cls");
			gotoxy(15,4);
			printf(" IISUE BOOK SECTION ");
			gotoxy(10,6);
			printf("ENTER THE BOOK ID ---> ");
			scanf("%d",&t);
			fp=fopen("Project.dat","rb");
			fs=fopen("Issue.dat","ab+");
			if(checkid(t)==0) 		//check weather the book is available in library or not
			{
			     gotoxy(10,8);
			     printf("THE BOOK RECORD IS AVAILABLE");
			     gotoxy(10,9);
			     printf("THERE ARE CURRENTLY %d UN ISSUED BOOKS AVAILABLE IN LIBRARY ",r.quantity);
			     gotoxy(10,10);
			     printf("THE NAME OF BOOK IS %s",r.name);
			     gotoxy(10,11);
			     printf("ENTER STUDENT NAME --->");
			     scanf("%s",r.stname);
			     gotoxy(10,12);
			     printf("ISSUED DATE=%d-%d-%d",r.issued.dd,r.issued.mm,r.issued.yy);	//for current date
			     gotoxy(10,13);
			     printf("THE BOOK OF ID %d IS ISSUED",r.id);		
			     r.duedate.dd=r.issued.dd+RETURNTIME;   		//for return date
			     r.duedate.mm=r.issued.mm;
			     r.duedate.yy=r.issued.yy;
			     if(r.duedate.dd>30) 
			     {
					r.duedate.mm+=r.duedate.dd/30;
					r.duedate.dd-=30;

			     }
			     if(r.duedate.mm>12)
			     {

					 r.duedate.yy+=r.duedate.mm/12;
					 r.duedate.mm-=12;

			     }
			     gotoxy(10,14);
			     printf("TO BE RETUrn:%d-%d-%d",r.duedate.dd,r.duedate.mm,r.duedate.yy);
			     fseek(fs,sizeof(r),SEEK_END);		//end of the file
			     fwrite(&r,sizeof(r),1,fs);
			     fclose(fs);
			     c=1;
			}
			if(c==0)
			{
			gotoxy(10,11);
			printf("NO RECORD FOUND");
			}
			gotoxy(10,15);
			printf("ISSUE ANY MORE (Y/N) --->");
			fflush(stdin);
			another=getche();
			fclose(fp);
		}

		break;
	}
	case '2':  	//case shows the issue books list
	{
		system("cls");
		int j=4;
		gotoxy(2,1);
		printf("                          Issued book list                               ");
		gotoxy(4,4);
		printf("STUDENT NAME    ID    BOOK NAME    ISSUED DATE    RETURN DATE");
	       fs=fopen("Issue.dat","rb");
		while(fread(&r,sizeof(r),1,fs)==1)
		{
			gotoxy(4,j);
			printf("%s",r.stname);
			gotoxy(18,j);
			printf("%d",r.id);
			gotoxy(24,j);
			printf("%s",r.name);
			gotoxy(37,j);
			printf("%d-%d-%d",r.issued.dd,r.issued.mm,r.issued.yy );
			gotoxy(52,j);
			printf("%d-%d-%d",r.duedate.dd,r.duedate.mm,r.duedate.yy);
			//gotoxy(50,25);
			//printf("Current date=%d-%d-%d",r.day,r.month,r.year);
			j++;
		}
		fclose(fs);
		gotoxy(1,25);
		returnfunc();
	}
	break;
	case '3':   //search issued books by id
	{
		system("cls");
		gotoxy(10,6);
		printf("Enter Book ID:");
		int p,c=0;
		char another='y';
		while(another=='y')
		{

			scanf("%d",&p);
			fs=fopen("Issue.dat","rb");
			while(fread(&r,sizeof(r),1,fs)==1)
			{
				if(r.id==p)
				{
					issuerecord();
					gotoxy(10,12);
					printf("Press any key.......");
					getch();
					issuerecord();
					c=1;
				}

			}
			fflush(stdin);
			fclose(fs);
			if(c==0)
			{
				gotoxy(10,8);
				printf("No Record Found");
			}
			gotoxy(10,13);
			printf("Try Another Search?(Y/N)");
			another=getch();
		}
	}
	break;
	case '4':  	//case remove issued books from list
	{
		system("cls");
		int b;
		FILE *fg;  	//delete for temporary file is declared
		char another='y';
		while(another=='y')
		{
			gotoxy(10,5);
			printf("ENTER BOOK ID TO REMOVE:");
			scanf("%d",&b);
			fs=fopen("Issue.dat","rb+");
			while(fread(&r,sizeof(r),1,fs)==1)
			{
				if(r.id==b)
				{
					issuerecord();
					findbook='t';
				}
				if(findbook=='t')
				{
					gotoxy(10,12);
					printf("DO YOU WANT TO REMOVE IT? (Y/N) ");
					if(getch()=='y')
					{
						fg=fopen("record.dat","wb+");
						rewind(fs);
						while(fread(&r,sizeof(r),1,fs)==1)
						{
							if(r.id!=b)
							{
							fseek(fs,0,SEEK_CUR);
							fwrite(&r,sizeof(r),1,fg);
							}
						}
						fclose(fs);
						fclose(fg);
						remove("Issue.dat");
						rename("record.dat","Issue.dat");
						gotoxy(10,14);
						printf("THE ISSUED BOOK IS REMOVED FROM LIST");

				       }

				}
				if(findbook!='t')
				{
					gotoxy(10,15);
					printf("NO RECORD FOUND");
				}
			}
			gotoxy(10,16);
			printf("DELETE ANY MORE?(Y/N)");
			another=getch();
		}
	}
	default:
	gotoxy(10,18);
	printf("\nWRONG ENTRY!!");
    getch();
	issuebooks();
	break;
      }
      gotoxy(1,30);
      returnfunc();
}
void editbooks(void)  //function edit information about book
{
	system("cls");
	int c=0;
	int d,e;
	gotoxy(20,4);
	printf(" Edit Books Section");
	char another='y';
	while(another=='y')
	{
		system("cls");
		gotoxy(15,6);
		printf("Enter Book Id to be edited:");
		scanf("%d",&d);
		fp=fopen("Project.dat","rb+");
		while(fread(&r,sizeof(r),1,fp)==1)
		{
			if(checkid(d)==0)
			{
				gotoxy(15,7);
				printf("The book is availble");
				gotoxy(15,8);
				printf("The Book ID:%d",r.id);
				gotoxy(15,9);
				printf("Enter new name:");
				fflush(stdin);
				scanf("%s",r.name);
				gotoxy(15,10);
				printf("Enter new Writer:");
				fflush(stdin);
				scanf("%s",r.Writer);
				gotoxy(15,11);
				printf("Enter new quantity:");
				fflush(stdin);
				scanf("%d",&r.quantity);
				gotoxy(15,12);
				printf("Enter new amount:");
				fflush(stdin);
				scanf("%f",&r.Amount);
				fflush(stdin);
				gotoxy(15,13);
				printf("Enter new bookno:");
				fflush(stdin);
				scanf("%d",&r.bookno);
				gotoxy(15,14);
				printf("The record is edited");
				fseek(fp,ftell(fp)-sizeof(r),0);	//ftell returns the current file position of the given stream.
				printf("%d",r.bookno);
				fwrite(&r,sizeof(r),1,fp);	
				fclose(fp);
				c=1;
			}
			if(c==0)
			{
				gotoxy(15,9);
				printf("No record found");
			}
		}
		gotoxy(15,16);
		printf("Edit another Record?(Y/N)");
		fflush(stdin);
		another=getch() ;
	}
		returnfunc();
}
void bookslist(void)  	//function for showing the list of books available in library
{
    int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("                              Book List                                   \n");
    gotoxy(2,2);
    printf(" DEPARTMENT      BOOK NAME	  BOOK ID     BOOK NO     WRITER      QTY     AMOUNT");
    j=4;
    fp=fopen("Project.dat","rb");
    while(fread(&r,sizeof(r),1,fp)==1)
    {
		gotoxy(3,j);
		printf("%s",r.cat);
		gotoxy(19,j);
		printf("%s",r.name);
		gotoxy(34,j);
		printf("%d",r.id);
		gotoxy(46,j);
		printf("%d",r.bookno);
		gotoxy(58,j);
		printf("%s",r.Writer);
		gotoxy(70,j);
		printf("%d",r.quantity);
		gotoxy(78,j);
		printf("%d",r.Amount);
		printf("\n\n");
		j++;
		i=i+r.quantity;
	}
	gotoxy(3,25);
	printf(" Total Books =%d",i);
	fclose(fp);
	gotoxy(35,25);
	returnfunc();
}
void returnfunc(void)
{
    {
	printf("\n\n\n\tPRESS ENTER TO RETURN TO MAIN MENU");
    }
    r:
    if(getch()==13) 	//allow only the use of enter
    mainmenu();
    else
    goto r;
}
int checkid(int t)  	//checks weather the book exist in library or not
{
	rewind(fp);
	while(fread(&r,sizeof(r),1,fp)==1)		//size_r this is the unsigned integral type and is the result of the sizeof keyword.
	if(r.id==t)
	return 0;  		//return 0 if book exist
      return 1; 	//return 1 if book not exist
}
int t(void) 	//for adding time
{
time_t t;
time(&t);
printf("\n\n\t\t\t\tDATE AND TIME:%s\n",ctime(&t));
return 0;
}

void issuerecord()  	//function that displayed the book's information
{
		 system("cls");
		 gotoxy(10,8);
		 printf("The Book has taken by Mr. %s",r.stname);
		 gotoxy(10,9);
		 printf("Issued Date:%d-%d-%d",r.issued.dd,r.issued.mm,r.issued.yy);
		 gotoxy(10,10);
		 printf("Returning Date:%d-%d-%d",r.duedate.dd,r.duedate.mm,r.duedate.yy);
}
