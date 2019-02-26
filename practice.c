#include <stdio.h>
#include <stdlib.h>

void is_palindrome(char *start, char *end, char *word) {

	while(*end != '\0') {
		end++;
	}	        
        end--; //subtract one for null term

	while(start <= end && *start == *end){
      		start++;
		end--;
	}
					                

	if(start > end){
		printf("%s %s\n", word, "is a palindrome");
	} else {
		printf("%s %s\n", word, "is not a palindrome");
	}
}

int main(int argc, char *argv[]) {

	if(argc < 2) {
		fprintf(stderr, "Please enter a word\n");
		exit(1);
	}

	char *start = argv[1];
	char *end = argv[1];

	is_palindrome(start, end, argv[1]);
}
