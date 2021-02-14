#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

#include "node.h"

void printInorder(struct Node *node){
	
	
}

void printPreorder(struct Node *node) {


}

void printPostorder(struct Node *node) {
	

}

// Returns head node of tree.  Copies strings from main into node structure.
struct Node * buildTree(char string_storage[][31], int string_length[], int rows){

	
	struct Node *rootNode_ptr;
	struct Node node_array[rows];
	struct Node *node_arrayPtr[rows];
	

	int j;
	int k;
	printf("Below is from TREE\n\n");

	 
	// Link array of nodes and array of node pointers together.
	int i;
	for (i = 0; i < rows; i++) {
		node_arrayPtr[i] = &node_array[i];
		// Allocate space for value and duplicate member of each node
		node_array[i].value = malloc(31 * sizeof (char));
		node_array[i].dupe_str = malloc(31 * sizeof (char));
		node_array[i].has_dupe = false;
		node_array[i].is_dupe = false;
	
	}


	// Set value of each node
	for (k = 0; k < rows; k++){
			for (j = 0; j < string_length[k]; j++) {
				node_array[k].value[j] = string_storage[k][j];
				printf("%c", node_array[k].value[j]);
			}
		printf("\n");
		 
		node_array[k].value[j + 1] = '\0';
	}
	

	// Set score of each node. Not actually used for anything.
	// Thought it could be used for finding matches but was wrong.
	int temp_score = 0;
	for (k = 0; k < rows; k++) {
		for (j = 0; j < 2; j++) {
			temp_score += (int)(node_array[k].value[j]);
			
		}
	node_array[k].score = temp_score;
	printf("This is score: %d\n", node_array[k].score);
	temp_score = 0;

	}

	// Find duplicates based on first 2 chars using linear search
	// Also mark everything that has a duplicate or is a duplicate
	for (k = 0; k < (rows - 1) ; k++) {
		for (i = k + 1; i < rows; i++) {
			if (node_array[k].value[0] == node_array[i].value[0] && 
			    node_array[k].value[1] == node_array[i].value[1]) {
 				if (node_array[k].has_dupe == false &&
				    node_array[i].is_dupe == false) {
					//printf("match= %s\n", node_array[k].value);
					//printf("match= %s\n", node_array[i].value);
					node_array[k].has_dupe = true;
					node_array[i].is_dupe = true;
					strcpy(node_array[k].dupe_str, node_array[i].value);
					printf("node_array[k].duplicate: %s\n", node_array[k].dupe_str);
				}
				else {
					node_array[i].is_dupe = true;
					printf("node_array[i].is_dupe is true\n");
				}
			}
		}
		
	}


	// Set all nodes pointers to NULL	
	for (i = 0; i < rows; i++) {
		node_array[i].head = NULL;
		node_array[i].tail = NULL;
		node_array[i].left = NULL;
		node_array[i].right = NULL;
	}



	for (i = 0; i < rows; i++) {	
		// Skip if duplicate, head is cut off
		if (node_array[i].is_dupe == false) {
			// If next node is greater than current node
			if (node_array[i + 1].score > node_array[i].score) {
				// Set right pointer
				node_array[i].right = node_arrayPtr[i + 1];
			}
			// If next node is less than current node
			else if (node_array[i + 1].score < node_array[i].score) {
				// Set left pointer
				node_array[i].left = node_arrayPtr[i + 1];
			}
			else {
				// Duplicate got through somehow
				printf("Bad news, duplicate got through!\n");
			}
		}
		
		node_array[i].head = node_arrayPtr[i];
		// Only set tail if it is not root
		if (i > 0) {
			// Set tail.
			node_array[i].tail = node_arrayPtr[i - 1];
		}
		
	}


	

	


	
	rootNode_ptr = node_array[0].head;	
	

	return rootNode_ptr;

}
