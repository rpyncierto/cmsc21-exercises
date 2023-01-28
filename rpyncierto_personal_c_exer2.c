/*
Reymond P. Yncierto
ST-1l

Given that 1 Jan 2022 is a Saturday, write a program that asks for a user input of the month number and prints the year 2022 calendar for the corresponding month.

*/

#include <stdio.h>

// number of days in every month
int daysOfMonth(int mm) {
  switch (mm) {
  case 1:        // january
  case 3:        // march
  case 5:        // may
  case 7:        // july
  case 8:        // august
  case 10:       // october
  case 12:       // december
    return (31); // --31 days
    break;
  case 2:        // february
    return (28); // --28 days
    break;
  case 4:        // april
  case 6:        // june
  case 9:        // september
  case 11:       // november
    return (30); // --30 days
    break;
  }
}

// 1 - sunday ... 7 - saturday
int firstDayOfMonth2022(int mm) {
  switch (mm) {
  case 1:       // january
  case 10:      // october
    return (7); // --saturday
    break;
  case 2:       // february
  case 3:       // march
  case 11:      // november
    return (3); // --tuesday
    break;
  case 4:       // april
  case 7:       // july
    return (6); // --friday
    break;
  case 5:       // may
    return (1); // --sunday
    break;
  case 6:       // june
    return (4); // --wednesday
    break;
  case 8:       // august
    return (2); // --monday
    break;
  case 9:       // september
  case 12:      // december
    return (5); // --thursday
    break;
  }
}

void nameDay(int day) {
  if (day == 1) {
    printf("Sunday\n");
  } else if (day == 2) {
    printf("Monday\n");
  } else if (day == 3) {
    printf("Tuesday\n");
  } else if (day == 4) {
    printf("Wednesday\n");
  } else if (day == 5) {
    printf("Thursday\n");
  } else if (day == 6) {
    printf("Friday\n");
  } else {
    printf("Saturday\n");
  }
}

void nameMonth(int mm) {
  if (mm == 1) {
    printf("January");
  } else if (mm == 2) {
    printf("February");
  } else if (mm == 3) {
    printf("March");
  } else if (mm == 4) {
    printf("April");
  } else if (mm == 5) {
    printf("May");
  } else if (mm == 6) {
    printf("June");
  } else if (mm == 7) {
    printf("July");
  } else if (mm == 8) {
    printf("August");
  } else if (mm == 9) {
    printf("September");
  } else if (mm == 10) {
    printf("October");
  } else if (mm == 11) {
    printf("November");
  } else {
    printf("December");
  }
}

void displayDayMonth(int mm, int day) {
  if (mm == 1) {
    printf("1 January is a ");
    nameDay(day);
  } else if (mm == 2) {
    printf("1 February is a ");
    nameDay(day);
  } else if (mm == 3) {
    printf("1 March is a ");
    nameDay(day);
  } else if (mm == 4) {
    printf("1 April is a ");
    nameDay(day);
  } else if (mm == 5) {
    printf("1 May is a ");
    nameDay(day);
  } else if (mm == 6) {
    printf("1 June is a ");
    nameDay(day);
  } else if (mm == 7) {
    printf("1 July is a ");
    nameDay(day);
  } else if (mm == 8) {
    printf("1 August is a ");
    nameDay(day);
  } else if (mm == 9) {
    printf("1 September is a ");
    nameDay(day);
  } else if (mm == 10) {
    printf("1 October is a ");
    nameDay(day);
  } else if (mm == 11) {
    printf("1 November is a ");
    nameDay(day);
  } else {
    printf("1 December is a ");
    nameDay(day);
  }
}

void displayCalendar(int mm) {
  int day = firstDayOfMonth2022(mm), days = daysOfMonth(mm), i;
  printf("\n");
  nameMonth(mm);
  printf(" 2022 Calendar\n");
  printf("SUN MON TUE WED THU FRI SAT\n"); // header
  for (int i = 1; i < day;
       i++) { // determines the space before the first day of the month
    printf("    ");
  }
  for (int i = 1; i <= days; i++) {
    printf("%3d ", i); // print the days on their respective rows
    if ((day + i - 1) % 7 == 0) {
      printf("\n"); // columns of the calendar
    }
  }
  printf("\n");
}

int main() {
  int mm;
  printf("Enter a month number (1-12): "); // asking the user what month he/she
                                           // want to print
  scanf("%d", &mm);
  if (mm > 12 || mm < 1) { // checking if the month is valid
    printf("Invalid month number\n");
  } else {
    displayDayMonth(
        mm, firstDayOfMonth2022(
                mm)); // function call for displaying the day of the first day
                      // of the month as well as the header of the calendar
    displayCalendar(mm); // function call for displaying the calendar
  }
}
