#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	// Points to other nodes
	struct Node *head;
	struct Node *tail;
	struct Node *left;
	struct Node *right;

	// Values
	char test;
	char *str;
	int value;
	char *dupllicates[];
	

};

#endif
