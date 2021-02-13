#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#include "node.h"

void printInorder(struct Node *node){
	
	node->test = 'a';
	
}

void printPreorder(struct Node *node) {

	node->test = 'b';
}

void printPostorder(struct Node *node) {
	
	node->test = 'c';

}

struct Node * buildTree(char string_storage[][31], int string_length[], int rows){

	// Create root and initialize structure objects
	struct Node *rootNode_ptr;
	struct Node node_array[rows];
	struct Node *node_arrayPtr[rows];
	

	int j;
	int k;
	printf("Below is from TREE\n\n");

	// 

	int i;
	for (i = 0; i < rows; i++) {
		node_arrayPtr[i] = &node_array[i];
		node_array[i].test = 'L'; 
		// initialize value pointer
	
	}



	printf("TREE ROWS: %d\n: ", rows);
	for (j = 0; j < rows; j++) {
		printf("TREE STRING LENGTH: %d\n", string_length[j]);
	}



	// Try to set each member of root node and print it
	node_array[0].score = 12;
	printf("node_array[0] score: %d\n", node_array[0].score);
 

	node_array[0].value = malloc(31 * sizeof (char));
	node_array[0].value = "Dasdf";
	printf("%s\n", node_array[0].value);
	printf("%c\n", node_array[0].value[0]);


	// Set value of each node
	for (k = 0; k < rows; k++){
			for (j = 0; j < string_length[k]; j++) {
				//node_array[k].value[j] = string_storage[k][j];
				//printf("%c", node_array[k].value[j]);
			}
		printf("\n");
		printf("That was string storage\n"); 
		//node_array[k].value[j] = '\0';
	}
		//printf("node_array value: %s", node_array[0].value);

	
	
	rootNode_ptr = &node_array[0];	
	

	return rootNode_ptr;

}
