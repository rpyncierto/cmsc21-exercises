/*
Reymond P. Yncierto
ST-1L

Implement a palindrome checker using various string functions in C.
Your application should be able to:
    1. Scan for the word to be checked
    2. Pass the word to a function called isPalindrome which returns an int to be interpreted in the main() whether the given word is a palindrome or not.
    3. The program should loop indefinitely until the word ”EXIT” is used as input.
    
    Bonus: Store each palindrome in an array, then print all palindromes before exiting the program.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *str) {
    for (int i=0; i<=strlen(str)-1; i++) { // iterate through the array
        if (str[i] != str[(strlen(str)-1-i)]) { // check if the current character is not equal to its character equivalent when the array is reversed
            return 0; // if not equal then return 0(false)
        }   
    }
    return 1; // if equal then return 1(true) meaning it is a palindrome
}

int main() {
    char word[100], upper[100], display[2][100];
    int i=0;
    printf("\tPalindrome Checker\n");
    while(1) {
        printf("Enter a word: "); // get a word from the user
        scanf("%s", word);
        // to be not case sensitive
        strcpy(upper, word); // copy the word to a new variable called upper since it is still need in printing all the palindromes inputted by the user
        for(int i=0; i<=strlen(word)-1; i++) { // convert all characters to uppercase
            upper[i] = toupper(word[i]);
        }
        if (strcmp(upper, "EXIT")==0) { // if the word is "EXIT" then exit the program (not case sensitive)
            printf("\nThank you for using the program.\n");
            if (display[i][0] != '\0') { // if there is a palindrome inputted by the user
                printf("The palindromes among the words entered are:\n");
                for(int j=0; j<i; j++) { // iterate through the array of palindromes
                    printf("\t%d - %s\n",j+1, display[j]); // print the palindromes
                }
            } else {
                printf("No palindromes were entered.\n"); // if there is no palindrome inputted by the user
            }
            return 0;
        } else if(isPalindrome(upper)) { // pass the word to isPalindrome function; if the word is a palindrome then print it
            strcpy(display[i], word); // copy the word to the display array for printing
            i++; // increment the counter
            printf("The word %s is a Palindrome.\n", word);
        } else { // if not, prompt that the word is not a palindrome
            printf("The word %s is not a Palindrome.\n", word);
        }
        printf("\n");
    }
}
