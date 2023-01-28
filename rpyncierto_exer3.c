/*
Reymond P. Yncierto

Create a program that gets thee (3) largest prime numbers from x, to y, x and y are given by the user.

If x is greater than y, swap x and y.

If there are no prime numbers in the given range, the program must print zero (0). If there is only one prime
number, the program must print that number. If there are two prime numbers in the given range, then both
prime numbers are printed.
*/
#include <stdio.h>

void inputXY(int *x, int *y) { // function that gets the range of the numbers from which we will get the largest prime numbers
    printf("Enter value of x: "); 
    scanf("%d", x); // only x, since x is already an integer pointer and pertains to an address
    printf("Enter value of y: ");
    scanf("%d", y); // only y, since y is already an integer pointer and pertains to an address
}

void swap(int *x, int *y) {
    int temp;
    temp = *x; // assign the value of x to temp; *x since we need the value not the address
    *x = *y; // assign the value of y to x; *y since we need the value not the address and *x since we will store the actual value not the address
    *y = temp; // assign the value of temp to y; *y since we will store the actual value not the address
}

int isPrime(int n, int i) {
    if (n==i) { // base case
        return 1; // all numbers are divisible by themselves 
    } else if (n==1 || n%i==0) { // base case
        return 0; // 1 only has itself as its factor and if a number is divisible by other number other than 1 and itself, then it is not a prime number
    } else { // recursive case
        return isPrime(n, i+1); // increment the integer i and perform the function again
    }
}

int main() {
    int x, y, a=0, b=0, c=0;
    inputXY(&x, &y); // function call for user input; pass by reference
    if (x > y) {
        swap(&x, &y); // function call for swapping; pass by reference
    }
    for (int i=y; i>=x; i--) { // iterate integers from y to x
        if (isPrime(i, 2)) { // function call for checking if an integer is a prime; pass by value
            if (a==0) {
                a = i; // assign the largest prime number to variable a
            } else if (b==0) {
                b = i; // assign the second largest prime number to variable b
            } else {
                c = i; // assign the third largest prime number to variable c
                break; // break the execution of the loop since we only need the 3 largest prime numbers
            }
        }
    } 
    printf("The three (3) largest prime numbers from %d to %d are: ", x, y);
    if (a==0 && b==0 && c==0) { // if all variables are 0 then there are no prime numbers in the range
        printf("0 (there are no prime numbers from %d to %d)\n", x, y);
    } else if (a!= 0 && b==0) { // if there is only 1 prime number in the range
        printf("%d (there is only one prime number from %d to %d)\n", a, x, y);
    } else if (a!=0 && b!=0 && c==0) { // if there are only 2 prime number in the range
        printf("%d %d (there are only two prime numbers from %d to %d)\n", b, a, x, y);
    } else { // if there are at least 3 prime number in the range
        printf("%d %d %d\n", c, b, a);
    }
    return 0;
}
