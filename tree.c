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

void buildTree(){

	printf("build tree\n");

}
