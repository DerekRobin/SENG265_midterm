#include <stdlib.h>
#include <stdio.h>

int add(int *number1, int *number2){
	return *number1 + *number2;
}

int max(int *num1, int *num2) {
	
	if(*num1 > *num2) {
		return *num1;
	}
	return *num2;
}

int sum_array(); 

void array_dump(){

	int num_elements;
	printf("%s", "Please enter a number from 1 to 10:\n");
	scanf("%d", &num_elements);

	int elements[num_elements]; 
	int *ptr = elements;
        int i;	
	for(i = 0; i < num_elements; i++){
		printf("element - %d: ", i);
		scanf("%d", elements+i);
	}
	
	printf("Your array is:\n[ ");
	for(i = 0; i < num_elements-1; i++){
		printf("%d, ", *(ptr++));
	}
	printf("%d ]\n", *(ptr++));

	printf("The sum of your array is: %d\n", sum_array(ptr = elements, num_elements));

}

int sum_array(int *arr_start, int num_elements) {
	
	int i;
	int sum = 0; 
	for(i = 0; i < num_elements; i++) {
		sum += *(arr_start++);
	}
	return sum; 
}

int str_len(char *word){


	int length;  
	for(length = 0; *word != '\0'; word++, length++);
	return length;
}

void pad_with_spaces(char *word) {

	int length = str_len(word);
	char padded_word[length*3];
	char *ptr;
	for(ptr = padded_word; *word != '\0'; word++){
		*ptr = *word;
		ptr++;
		*ptr = ' ';
	       ptr++;	
	}
	*ptr = '\0';
	printf("Your word, padded with spaces looks like: %s\n", padded_word); 
	
}

void print_reverse_string(char *word) {
	
	char *ptr = word;
	int strlen = str_len(word);
	ptr += strlen;

	int i;
	for(i = 0; i <= strlen; i++,ptr--){
		printf("%c", *ptr);
	}
	printf("\n");
}
	
int main(int argc, char *argv[]) {

	if(argc == 2){
		int len = str_len(argv[1]);
		printf("The length of your string is: %d\n", len);
	        pad_with_spaces(argv[1]);
		print_reverse_string(argv[1]);	
		return 0;
	}

	int number1;
	int number2;
	
	printf("%s", "Please enter a number from 1 to 1000:\n");
	scanf("%d", &number1);
       	
	printf("%s", "Please enter a number from 1 to 1000:\n");
	scanf("%d", &number2);
	
	int sum = add(&number1, &number2);
	printf("The sum of %d and %d is: %d\n", number1, number2, sum);

	int largest = max(&number1, &number2);
	printf("The max of %d and %d is: %d\n", number1, number2, largest);

	array_dump();   
	return 0; 
}
