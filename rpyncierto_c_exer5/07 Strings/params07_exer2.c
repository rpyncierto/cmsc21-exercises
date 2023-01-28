//params07_exer2.c
//Exercise: Fill-in the blanks to make this program work
#include<stdio.h>
#include<string.h>	
#include<ctype.h>

void input(char *s) { 
	printf("What is your name? ");
	scanf("%s",s);
	
}

void toupperStr(char *s){
	for (int i=0; i<strlen(s); i++){
		s[i] = toupper(s[i]);
	}
	
}

void output(char *s){
	printf("Your name is %s.\n",s);
}
	

int main(){
	char name[20]; 
	
	input(name); 
	output(name);
	
	toupperStr(name); 
	
	output(name);
	
	return 0;
}


