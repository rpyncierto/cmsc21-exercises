/*
Reymond P. Yncierto
ST-1L

Create a program that asks for an integer n and lists all prime numbers from 1 to n.

Start by a creating recursive function that determines wether an integer is prime or not. Next ask for an
integer n, then loop through all the integers from 1 to n. Check each integer if it is prime by using the function
earlier then print the integer if it is prime.

This is a c program that determines the prime numbers from 1 to n using a recursive function.
*/
#include <stdio.h>

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
    int n; // variable declaration
    printf("Enter a positive number: "); 
    scanf("%d", &n); // put user input to address of variable n
    printf("The prime numbers from 1 to %d are: ", n);
    for (int i=1; i<=n; i++) { // iterate integers from 1 to n
        if (isPrime(i, 2)) { // check if integer i is a prime by performing the recursive function isPrime; 2 since all integers are divisible by 1
            printf("%d ", i); // if 1 (true) is returned then print the current integer i
        }
    } printf("\n");
}