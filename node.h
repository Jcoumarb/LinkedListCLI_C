#ifndef NODE_H
#define NODE_H

	struct node{

		int data;

		struct node* prev;
		struct node* next;
	};

	typedef struct node node;

#endif

