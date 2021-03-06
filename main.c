#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>


#include "node.h"
#include "tree.h"


void print_usage();
static char * read_stdin();
static char *load_file(char const * path);

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
		char *delim = " \n ";		// For splitting string
		char *input_copy = strdup(input); 
		char *input_copy2 = strdup(input);


		printf("Getting input from file...\n");


		// Use strtok just to count how many strings there are
		// Multiple copies due to strtok altering original string
		char *split_string = strtok(input, delim);
		int rows = 0;


		while (split_string != NULL) {

			printf("%s\n", split_string);
			split_string = strtok(NULL, delim);
			rows++;
		}

		
		// Use strtok to get length of strings.
		int string_length[rows];		
		int j = 0;
		char *split_string2 = strtok(input_copy, delim);


		while (split_string2 != NULL) {
			if (j == (rows - 1)){
				break;
			}	
			
			string_length[j] = strlen(split_string2);
			split_string2 = strtok(NULL, delim);
			j++;	
		}	

		
		// One string leftover from previous loop
		string_length[j] = strlen(split_string2);


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
		
		
		// One string leftover from previous loop
		int i = 0;
		for (i = 0; i < string_length[length_index]; i++) {
			string_storage[j][i] = split_string3[i];
		} 


		//Build tree and print traversals
		buildTree(string_storage, string_length, rows);

		
		free(input);
		exit(0);
	}
	else if (argc == 1) {


		printf("Getting input from stdin...\n");
		printf("Simulate EOF by entering 0 \n");


		char *input = read_stdin(); 	 // Read from STDIN
		char *delim = " \n ";		// For splitting string
		char *input_copy = strdup(input); 
		char *input_copy2 = strdup(input);





		// Use strtok just to count how many strings there are
		// Multiple copies due to strtok altering original string
		char *split_string = strtok(input, delim);
		int rows = 0;


		while (split_string != NULL) {

			printf("%s\n", split_string);
			split_string = strtok(NULL, delim);
			rows++;
		}

		
		// Use strtok to get length of strings.
		int string_length[rows];		
		int j = 0;
		char *split_string2 = strtok(input_copy, delim);


		while (split_string2 != NULL) {
			if (j == (rows - 1)){
				break;
			}	
			
			string_length[j] = strlen(split_string2);
			split_string2 = strtok(NULL, delim);
			j++;	
		}	

		
		// One string leftover from previous loop
		string_length[j] = strlen(split_string2);


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
		
		
		// One string leftover from previous loop
		int i = 0;
		for (i = 0; i < string_length[length_index]; i++) {
			string_storage[j][i] = split_string3[i];
		} 


		//Build tree and print traversals
		buildTree(string_storage, string_length, rows);

		
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


static char* load_file(char const* path)
{
    char* buffer = 0;
    long length;
    FILE * f = fopen (path, "rb"); //was "rb"

    if(f)
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

    
	return buffer;
}
