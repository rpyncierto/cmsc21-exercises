//CMSC 21 
// C-Exercise Module 2
//Collaborators: Joseph Tuazon, Reymond Yncierto, Chrissa Torres

#include <stdio.h>

int daysOfMonth(int mm){
    switch(mm){
        case 9: 
        case 4:
        case 6:
        case 11:
            return(30);
        case 2:
            return(28);
        default:
            return(31);
    }
}

int FirstDay(int mm){           //this funtion is important for the printing of calender
    switch(mm){                 
        case 1: 
        case 10:
            return(7);          //7 for saturday
        case 4:
        case 7:
            return(6);          //6 for friday
        case 5:
            return(1);          //1 for sunday
        case 6:
            return(4);          //4 for wednesday
        case 8:
            return(2);          //2 for monday
        case 9:
        case 12:
            return(5);          //5 for thursday
        default:
            return(3);          //3 for tuesday
    }
}

char NameDay(int mm){   //function for printing the name of the day
    if ( mm==6 ){
        printf(" Wednesday ");
    } else if ( mm==9 | mm==12 ){
        printf(" Thursday ");
    } else if ( mm==4 | mm==7 ){
        printf(" Friday ");
    } else if ( mm==1 | mm==10 ){
        printf(" Saturday ");
    } else if ( mm==5 ){
        printf(" Sunday ");
    } else if ( mm==2 | mm==3 | mm==11 ){
        printf(" Tuesday ");
    } else {
        printf(" Monday ");
    }
}

char NameMonth(int mm){     //this function display the day(e.g.mon,tue,etc.) of the first day of month
    if ( mm==1){
            printf(" 1 January is a ");        
            printf("%c \n", NameDay(mm));
            printf("\n");
            printf(" January 2022 Calendar \n");
    } else if ( mm==2){
            printf(" 1 February is a ");
            printf("%c \n", NameDay(mm));
            printf("\n");
            printf(" February 2022 Calendar \n");
    } else if ( mm==3){
            printf(" 1 March is a ");
            printf("%c \n", NameDay(mm));
            printf("\n");
            printf(" March 2022 Calendar \n");
    } else if ( mm==4 ){
            printf(" 1 April is a ");
            printf("%c \n", NameDay(mm));
            printf("\n");
            printf(" April 2022 Calendar \n");
    } else if ( mm==5 ){
            printf(" 1 May is a ");
            printf("%c \n", NameDay(mm));
            printf("\n");
            printf(" May 2022 Calendar \n");
    } else if ( mm==6 ){
            printf(" 1 June is a ");
            printf("%c \n", NameDay(mm));
            printf("\n");
            printf(" June 2022 Calendar \n");
    } else if ( mm==7){
            printf(" 1 July is a ");
            printf("%c \n", NameDay(mm));
            printf("\n");
            printf(" July 2022 Calendar \n");
    } else if ( mm==8 ){
            printf(" 1 August is a ");
            printf("%c \n", NameDay(mm));
            printf("\n");
            printf(" August 2022 Calendar \n");
    } else if ( mm==9){
            printf(" 1 September is a ");
            printf("%c \n", NameDay(mm));
            printf("\n");
            printf(" September 2022 Calendar \n");
    } else if ( mm==10){
            printf(" 1 October is a ");
            printf("%c \n", NameDay(mm));
            printf("\n");
            printf(" October 2022 Calendar \n");
    } else if ( mm==11){
            printf(" 1 November is a ");
            printf("%c \n", NameDay(mm));
            printf("\n");
            printf(" November 2022 Calendar \n");
    } else if ( mm==12){
            printf(" 1 December is a ");
            printf("%c \n", NameDay(mm));
            printf("\n");
            printf(" December 2022 Calendar \n");
    }

}

void printcalendarMonth(int mm){        //this funtion prints the calendar
    int fd;
    int numdays;
    numdays= daysOfMonth(mm);
    fd = FirstDay(mm);
    int i;
    printf("SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n"); //header of the calendar
    for(i=1;i<fd;i++)           //blank space for days(sun,mon,etc) < the value of firstday
      printf("  \t");
    for(i=1;i<=numdays;i++){
      printf("%3d\t",i);        //print the days on their respective rows
      if((fd+i-1)%7==0)        
         printf("\n");         //columns of the calendar
   } 
}

int main(){
    int month;
    printf("Enter month (1-12) : ");    //asking the user what month he/she want to print
    scanf("%d", &month);
    NameMonth(month);               //function call for displaying the day of the firstday of month
    printcalendarMonth(month);      //function call for  displaying the calendar of the month
    printf("\n");
}
