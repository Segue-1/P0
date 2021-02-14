#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>


#include "node.h"
#include "tree.h"


void print_usage();
static char * read_stdin();
char *load_file(char const * path);

int main (int argc, char* argv[]) {

	

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
		
		//FILE *fp;
		//FILE fopen(argv[1], r);
		char *input = load_file(argv[1]);
		char *delim = " \n "; // For splitting string

		char *input_copy = NULL;
		char *input_copy2 = NULL;

	

		input_copy = strdup(input);
		input_copy2 = strdup(input);


		// Check dupe and print input		
		printf("\n\n");

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
		int string_length[rows];
		int j = 0;
		char *split_string2 = strtok(input_copy, delim);
		string_length[j] = strlen(split_string2);


		while (split_string2 != NULL) {
			if (j == (rows - 1)){
				break;
			}	
			
			string_length[j] = strlen(split_string2);
			printf("string_lengt %d\n", string_length[j]);
		
			split_string2 = strtok(NULL, delim);
			j++;	

		}	

		string_length[j] = strlen(split_string2);
		printf("string_lengt %d\n", string_length[j]);


		// Create 2d  array and store strings.
		int columns = 32;
		char string_storage[rows][columns - 1];
		int length_index = 0;
		char *split_string3 = strtok(input_copy2, delim);
		
		j = 0;	
		while (split_string3 != NULL) {
			if (j == (rows - 1)) {
				break;
			}
			int i = 0;
			for (i = 0; i < string_length[length_index]; i++) {
				string_storage[j][i] = split_string3[i];	
			}
			length_index++;
			split_string3 = strtok(NULL, delim);
			j++;
			
		}
		int i = 0;
		for (i = 0; i < string_length[length_index]; i++) {
			string_storage[j][i] = split_string3[i];
		}

				
		

		free(input);
		exit(0);

			 



		exit(0);
	}
	else if (argc == 1) {
		// Test keyboard
		char *input = read_stdin(); // Read from STDIN
		char *delim = " \n "; // For splitting string

		char *input_copy = NULL;
		char *input_copy2 = NULL;

	

		input_copy = strdup(input);
		input_copy2 = strdup(input);


		// Check dupe and print input		
		printf("HERE IS DUPE: %s\n", input_copy);

		printf("Getting input from stdin...\n");
		printf("Simulate EOF by entering 0 \n");
		printf("Below is the original input\n");
		printf("---------------------------\n");
		printf("%s\n", input);
		printf("---------------------------\n");
		printf("Below is the input split up\n\n");



		// Use strtok just to count how many strings there are
		// Multiple copies due to strtok altering original string
		char *split_string = strtok(input, delim);
		int rows = 0;

		while (split_string != NULL) {
		
			printf("%s\n", split_string);
			split_string = strtok(NULL, delim);
			rows++;
		}

		//printf("ROWS: %d\n", rows);
 
		
		
		// Use strtok to get length of strings.
		int string_length[rows];
		
		int j = 0;
		char *split_string2 = strtok(input_copy, delim);
		//string_length[j] = strlen(split_string2);


		while (split_string2 != NULL) {
			if (j == (rows - 1)){
				break;
			}	
			
			string_length[j] = strlen(split_string2);
			//printf("string_lengt %d\n", string_length[j]);
		
			split_string2 = strtok(NULL, delim);
			j++;	

		}	

		string_length[j] = strlen(split_string2);
		//printf("string_lengt %d\n", string_length[j]);
		


		// Create 2d  array and store strings.
		int columns = 32;
		char string_storage[rows][columns - 1];
		int length_index = 0;
		char *split_string3 = strtok(input_copy2, delim);
		
		j = 0;	
		while (split_string3 != NULL) {
			if (j == (rows - 1)) {
				break;
			}
			int i = 0;
			for (i = 0; i < string_length[length_index]; i++) {
				string_storage[j][i] = split_string3[i];	
			}
			length_index++;
			split_string3 = strtok(NULL, delim);
			j++;
			
		}
		
		
		

		// There's a problem here I don't understand
		int i = 0;
		for (i = 0; i < string_length[length_index]; i++) {
			string_storage[j][i] = split_string3[i];
		} 


		printf("MAIN rows: %d\n", rows);
		printf("MAIN string_length[0] : %d\n", string_length[0]);
		//Node stuff
		struct Node *node_mainptr = buildTree(string_storage, string_length, rows);
	
		

	



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


char* load_file(char const* path)
{
    char* buffer = 0;
    long length;
    FILE * f = fopen (path, "rb"); //was "rb"

    if (f)
    {
      fseek (f, 0, SEEK_END);
      length = ftell (f);
      fseek (f, 0, SEEK_SET);
      buffer = (char*)malloc ((length+1)*sizeof(char));
      if (buffer)
      {
        fread (buffer, sizeof(char), length, f);
      }
      fclose (f);
    }
	buffer[length] = '\0';

    //for (int i = 0; i < length; i++) {
    //printf("buffer[%d] == %c\n", i, buffer[i]);
    //}
    //printf("buffer = %s\n", buffer);
    
	return buffer;
}
