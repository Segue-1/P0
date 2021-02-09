#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


#include "node.h"
#include "tree.h"


void print_usage();
static char * read_stdin();
char *my_strcpy(char *destination, char *source);

int main (int argc, char* argv[]) {

	// Node stuff
	struct Node node_m;
	printInorder(&node_m);
	//printf("%c\n", node_m.test);

	

	// Check number of arguments
	if (argc > 2) {
		printf("Too many arguments\n");
		print_usage();
		exit(0);
	}	
	else if (argc == 2) {
		// File was passed, check if it exists
		if (access(argv[1], F_OK) == 0) {
			printf("File exists, continuing...\n");
		}
		else {
			printf("File doesn't exist, exiting...\n");
			exit(0);
		}
		
		exit(0);
	}
	else if (argc == 1) {
		// Test keyboard
		char *input = read_stdin(); // Read from STDIN
		char *delim = " \n "; // For splitting string

		char *input_copy = NULL;
		char *input_copy2 = NULL;

		input_copy = strdup(input);
	
		// Check dupe and print input		
		printf("HERE IS DUPE: %s\n", input_copy);

		printf("Getting input from stdin...\n");
		printf("Simulate EOF by entering 0 \n");
		printf("---------------------------\n");
		printf("%s\n", input);
		printf("---------------------------\n");



		// Use strtok just to count how many strings there are
		// Multiple copies due to strtok altering original string
		char *split_string = strtok(input, delim);
		int rows = 0;

		while (split_string != NULL) {
		
			printf("%s\n", split_string);
			split_string = strtok(NULL, delim);
			rows++;
		}

		printf("ROWS: %d\n", rows);
 
		
		
		// Use strtok to get length of strings.
		int string_length[rows - 1];
		int j = 0;
		char *split_string2 = strtok(input_copy, delim);
		string_length[j] = strlen(split_string2);


		while (split_string2 != NULL) {
			if (j == (rows - 1)){
				break;
			}	
			
			string_length[j] = strlen(split_string2);
			printf("string_lengt %d\n", string_length[j]);
			printf("j: %d\n", j);
			split_string2 = strtok(NULL, delim);
			j++;	

		}	

		string_length[j] = strlen(split_string2);
		printf("string_lengt: %d\n", string_length[j]);
		printf("j: %d\n", j);




		free(input);
		exit(0);
	}
	else {
		// Shouldn't be possible... 0 args
		printf("How did you do that?\n");
		print_usage();
		exit(0);
	}
	return 0;

}


void print_usage(){

	printf("---Usage---\n");
	printf("Enter './main' to test keyboard\n");
	printf("Enter './main < FILENAME' to test keyboard input from some file\n");
	printf("Enter './main FILENAME' to read from a file\n");

}

static char * read_stdin(){


	size_t capacity = 4096, offset = 0;  // Set size of buffer and offset.
	char *buffer = malloc(capacity * sizeof (char));
	int c; 

	// Read until EOF
	while ((c = fgetc(stdin)) != '0' && !feof(stdin)) {
				
		
		buffer[offset] = c;	
		if (++offset == capacity) {
			buffer = realloc(buffer, (capacity *= 2) * sizeof (char));
		}
			

	}

	// Trim and pad
	buffer = realloc(buffer, (offset + 1) * sizeof (char));
	buffer[offset] = '\0';

	return buffer;
}


char *my_strcpy(char *destination, char *source) {
	char *start = destination;

	while(*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return start;
}
