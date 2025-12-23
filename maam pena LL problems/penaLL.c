/*******************************************************************************
 * This program will illustrate operations in an ADT List of student records    *
 * represented in memory using Linked List Implementation.                           *
 *                                                                             *
 *  Instruction: Complete the tasks provided in the main() function by         *
 *               writing the code of the functions and making function calls.  *
 *******************************************************************************/
 
//A] Macro definitions and inclusion of header file
 
#define ARR_LENGTH  0XA
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
 
//B] Data Structure Definition
 
typedef struct {
    char FN[24], MI, LN[16];
}nametype;
 
typedef struct {
	char ID[9];
    nametype name;
    char course[8];
    int yrlevel;
}studtype;
 
typedef struct cell{
   studtype stud;
	struct cell *link;  
}*LinkList;
 
//C] Function Prototypes
 
void displayHeader();
void displayStudent(studtype S);              //Displays info of a student record in 1 horizontal line
void displayList(LinkList A);                //Displays the list and the number of elements in the list. Calls displayStudent()
 
//For Task 1: To write the code
void initList(LinkList *A);                  //Initializes the list to be empty
void insertLast(LinkList *A, studtype S);    //Inserts an element at the end of the list 
 
//For Task 2: To write the code
void deleteElem(LinkList *A, char ID[]);     //Deletes the element bearing the given ID if the element is found; otherwise
                                              //    Display "Element with ID ___ is not found"
//For Task 3: To write the code
void insertFirstUnique(LinkList *A, studtype S);  //Inserts an element at the first position of the list if the element does not yet exist;
                                                  //   otherwise Display "Element with ID ___ already exists". 
                                                  //   Note: Elements are uniquely identified thru ID
//For Task 4: To write the code
void selectionSort(LinkList A);            //Sorts the given list in ascending order according to ID.
 
 
//D] The main function
int main()
{
  LinkList L;
  studtype data[] = {  {"STUD1001", {"John", 'R', "Doe"}, "BSCS", 1},
           				  {"STUD1005", {"Jane", 'L', "Smith"}, "BSIT", 1},
           				  {"STUD1002", {"Mark", 'S', "Johnson"}, "BSIS", 1},
                       {"STUD1009", {"Joey", 'K', "Lee"}, "BSIS", 2},
            		     {"STUD1015", {"Michael", 'T', "Garcia"}, "BSIT", 2},
           				  {"STUD1006", {"Emlio", 'P', "Martinez"}, "BSIT", 3},
           				  {"STUD1011", {"David", 'A', "Rodriguez"}, "BSCS", 4},
            		     {"STUD1012", {"Olivia", 'B', "Hernandez"}, "BSCS", 3},
            			  {"STUD1008", {"James", 'C', "Kim"}, "BSIS", 3},
           			     {"STUD1010", {"Mia", 'D', "Nguyen"}, "BSCS", 1}
           	  			};
 
 
   int length = sizeof(data) / sizeof(data[0]);
   data[length].yrlevel = -1;
  /*-----------------------------------------------------------------------------------
   Task 1: 
     a) Populate the list with 10 elements by calling insertLast() 10 times. Use array data
     b) Display the List by calling displayList()
   -------------------------------------------------------------------------------------*/
    
  printf("\n\nTask 1: Populating the list");
  //initList(&L);    //UNcomment this if initList() function is created
 
  /*----- Write your code below to accomplish Task 1 -----*/ 
 
 
 
  /*-----------------------------------------------------------------------------------
   Task 2: 
     a) Call deleteElem() passing the ID number STUD1009, then call displayList()
     b) Call deleteElem() passing the ID number STUD1001, then call displayList()
     c) Call deleteElem() passing the ID number STUD1013, then call displayList()
   -------------------------------------------------------------------------------------*/
  printf("\n\nTask 2: Deleting Elements in the list");
 
   /*----- Write your code below to accomplish Task 2 -----*/ 
 
 /*-----------------------------------------------------------------------------------
   Task 3: 
     Call insertFirstUnique() 3 times passing the data records below, then call displayList()
 
   -------------------------------------------------------------------------------------*/
  printf("\n\nTask 3: Inserting at the first position in the list");
  studtype xData[] = { {"STUD1011", {"Ethan", 'E', "Perez"}, "BSIS", 2},
                       {"STUD1015", {"Chung", 'F', "Tan"}, "BSCS", 2},
           	  	        {"STUD1013", {"Alexander", 'G', "Reyes"}, "BSIS", 4}
           	  			     };	
 
   /*----- Write your code below to accomplish Task 3 -----*/ 
 
 
/*-----------------------------------------------------------------------------------//
   Task 4: 
     Call selectionSort(), then call displayList()
 
   -------------------------------------------------------------------------------------*/
   printf("\n\nTask 4: Sorting the list according to ID");
 

   void displayHeader();
  /*----- Write your code below to accomplish Task 4 -----*/ 
 
	return 0;
 
}
 
/*****************************************************************
 * Function Definitions                                          *
 *****************************************************************/
 
//----- Display Functions ------
void displayHeader()
{
	printf("\n\n");
	printf("%-10s", "Id Number");
   printf("%-13s", "FirstName");
   printf("%-3s", "MI");
   printf("%-13s", "LastName");
   printf("%-10s", "Program");
   printf("%-10s", "Year");		
}
 
void displayStudent(studtype S)
{
	printf("\n");
	printf("%-10s", S.ID);
   printf("%-13s", S.name.FN);
   printf("%-3c",  S.name.MI);
   printf("%-13s", S.name.LN);
   printf("%-10s", S.course);
   printf("%-10d", S.yrlevel);	
}  
 
//Complete the code for displayList()      
void displayList(LinkList A)
{
	int count = 0;
 
   //Write your code below
 
 
 
 
	printf("\nList has %d elements:", count);
  //printf("\n\n"); system("Pause");   //UNcomment this if a pause is desired
}  
 
 
/*****************************************************************************
 * Task 1: Write the code of functions initList() and insertLast()           *
 *****************************************************************************/
 
 
/*****************************************************************************
 * Task 2: Write the code of function deleteElem()                           *
 *****************************************************************************/
 
 
/*****************************************************************************
 * Task 3: Write the code of function insertFirstUnique()                     *
 *****************************************************************************/	
 
 
/*****************************************************************************
 * Task 4: Write the code of function selectionSort()                           *
 *****************************************************************************/	