/*

A Company has decided to celebrate their Loyal Employees by recognizing their hardwork and giving them a Loyalty Award. You are tasked to create a program to help go through the 
companies list of employees and give the management a list of Employees who are eligible to earn this award, which is 5 consecutive years in the Company. You decide to create a program 
to go through all the employee records and move all Employees who are eligible to a different record altogether.

 

Create a Program that will display a list of all Loyal Employees(5 years in the company). Make sure that the amount of memory you allocate for this new List of Employees will be the 
exact amount to hold the number of Loyal Employees.


*/




#include <stdio.h>
#include <stdlib.h>
#define STRING_MAX 50
#define LIST_MAX 10

typedef struct {
    int month;
    int year;
} currentDate;

typedef struct {
    int hireMonth;
    int hireYear;
} hiringDetails;

typedef struct {
    char fName[STRING_MAX];
} empDetails;

typedef struct {
    hiringDetails dateOfHire;
    empDetails employeeInfo;
} employee;

typedef struct {
    employee employeeList[LIST_MAX];
    int count;
} employeeRecords;

employee* getLoyalList(employeeRecords record, int *loyalListCount, currentDate currDate);
void display(employee *loyalList, int loyalListCount);

int main() {
    employeeRecords record;
    int employeeCount;
    int loyalListCount = 0;
    record.count = 0;
    employee *loyalList;
    currentDate date = {7, 2023}; 
    
    printf("Input Number of Employees:");
    scanf("%d", &employeeCount);
    
    printf("\nInput Details for Employees: \n");
    for (int i = 0; i < employeeCount; i++) {
        printf("\n\n===Employee %d===\n", i + 1);
        printf("Input First Name: ");
        scanf("%s", record.employeeList[i].employeeInfo.fName);
        printf("Input Month of Hire: ");
        scanf("%d", &record.employeeList[i].dateOfHire.hireMonth);  
        printf("Input Year of Hire: ");
        scanf("%d", &record.employeeList[i].dateOfHire.hireYear);   
        record.count++;
    }
    
    loyalList = getLoyalList(record, &loyalListCount, date);
    
    display(loyalList, loyalListCount);
    
    
    return 0;
}

employee* getLoyalList(employeeRecords record, int *loyalListCount, currentDate currDate) {
    int loyalYearThreshold = 5; 
    employee* loyalList = (employee*)malloc(record.count * sizeof(employee));
    
    for (int i = 0; i < record.count; i++) {
        int yearsWorked = currDate.year - record.employeeList[i].dateOfHire.hireYear;
        if (yearsWorked > loyalYearThreshold || 
            (yearsWorked == loyalYearThreshold && currDate.month >= record.employeeList[i].dateOfHire.hireMonth)) {
            loyalList[*loyalListCount] = record.employeeList[i];
            (*loyalListCount)++;
        }
        
    }
    
    return loyalList;
}

void display(employee *loyalList, int loyalListCount) {
    
    if(loyalListCount == 0){
        printf("There are currently no Employees who are eligible for the reward.");
    }
    else {
        printf("Loyal List:\n\n");
        for (int i = 0; i < loyalListCount; i++) {
        printf("Name: %s -- Hire Date:%d-%d\n", loyalList[i].employeeInfo.fName, loyalList[i].dateOfHire.hireMonth, loyalList[i].dateOfHire.hireYear);
        
    }
    }
}