/*
Reymond P. Yncierto
ST-1L

BMI Calculator

Create a C program that will compute for the body-mass index of a given height and weight. After calculating the BMI, the program will also tell under which category(underweight, normal weight, overweight,or obese) it belongs to. The user will be given two (2) choices before entering the height and weight. The menu must loop repeatedly until the exit option is entered. Make sure to have proper error prompts.

a. Enter in kilogram and centimeters
    This will ask for the weight in kilograms and height in centimeters.
b. Enter in pounds and feet
    This will ask for the weight in pounds and height in feet.
c. Exit
    Once chosen, the program must terminate.



This is a C program that calculates the BMI of a user depending on the measurement units used. This is applicable for weight in kilograms with height in centimeters, as well as weight in pounds with height in feet.
*/

#include <stdio.h>

int main() {
    float weight, height, bmi;
    int choice;

    // used a do-while loop to ensure that the body will execute at least once.
    do {
        // Prompts the Menu
        printf("\t BMI Calculator\n");
        printf("[1] Enter in kilogram and centimeters\n");
        printf("[2] Enter in pounds and feet\n");
        printf("[3] Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n"); // for readability in the terminal

        // switch statement that performs the appropriate action depending on the choice of the user
        switch(choice) {
            case 1: // weight in kilograms and height in centimeters
                printf("Enter your weight in kilograms: ");
                scanf("%f", &weight);
                printf("Enter your height in centimeters: ");
                scanf("%f", &height);
                bmi=(weight/height/height)*10000; // according to Centers for Disease Control and Prevention (link below)
                printf("\n"); // for readability in the terminal
                break;
            case 2: // weight in pounds and height in feet
                printf("Enter your weight in pounds: ");
                scanf("%f", &weight);
                printf("Enter your height in feet: ");
                scanf("%f", &height);
                height *= 12; // performs feet to inches conversion; according to Cuemath (link below)
                bmi=(weight/height/height)*703; // according to Centers for Disease Control and Prevention (link below)
                printf("\n"); // for readability in the terminal
                break;
            case 3: // exit option
                printf("Thank you for using the program!\n");
                return 0;
            default: // default when the choice is an integer other than 1, 2 or 3
                printf("Invalid choice!\n");
                printf("\n"); // for readability in the terminal
                continue; // // ignore the next lines of codes and continue on the next iteration
        }
        // // determines the category of the user based on his/her bmi
        if (bmi<18.5) {
            printf("Your BMI is %f, and this is considered underweight.\n", bmi);
        } else if (bmi>= 18.5 && bmi<25) {
            printf("Your BMI is %f, and this is considered a normal weight.\n", bmi);
        } else if (bmi>= 25 && bmi<30) {
            printf("Your BMI is %f, and this is considered overweight.\n", bmi);
        } else {
            printf("Your BMI is %f, and this is considered obese.\n", bmi);
        }
        printf("\n"); // for readability in the terminal
    } while (choice!=3); // loop until the user chooses to exit
}

/*
References Used:
    BMI using Metric System formula: https://tinyurl.com/mr2v3x99
    BMI using English System formula:  https://tinyurl.com/3cskyvy8
    Feet to inches formula:  https://tinyurl.com/2p99ufhw
    BMI category ranges: https://tinyurl.com/5av2mpzv
*/
