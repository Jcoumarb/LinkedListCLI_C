#include <stdio.h>
#include "node.h"
#include <stdlib.h>
#include <string.h>

node* clear(node* n){

	node* current = n;

	while(current != NULL){
		node* next = current -> next;

		free(current);

		current = next;
	}

	return NULL;
}
node* deleteNode(node* n, int value){

	node* head = n;

	node* current = n;

	while(current != NULL){
		if(current -> data == value){
			break;
		}
		current = current -> next;
	}

	if(current == NULL){
		return NULL;
	}else{
		if(head == current){
			head = head -> next;
		}

		node* nnext = current -> next;
		node* nprev = current -> prev;

		if(current -> prev != NULL){
			current -> prev -> next = nnext;
		}

		if(current -> next != NULL){
			current -> next -> prev = nprev;
		}

		free(current);

		return head;
	}
}

node* add(node* n, int value){

	if(n == NULL){

		n = malloc(sizeof(node));

		n -> data = value;

		n -> prev = NULL;
		n -> next = NULL;

		return n;

	}else{

		node* create = malloc(sizeof(node));

		create -> data = value;

		node* current = n;
		node* head = n;

		while(current ->next != NULL){

			if(current -> data >= value){
				break;
			}

			current = current -> next;
		}

		if(current -> data < value){
			current -> next = create;
			create -> prev = current;
			create -> next = NULL;

			return n;
		}else{
			if(head == current){

				create -> prev = NULL;
				create -> next = current;
				current -> prev = create;

				return create;
			}else{

				create -> next = current;
				create -> prev = current -> prev;

				create -> prev -> next = create;
				current -> prev = create;

				return head;
			}
		}
	}
}

void print_list(node* n){

	if(n == NULL){
		printf("[Empty List]\n\n");
	}else{

		node* current = n;
		char word[255];
		int index = 0;

		char temp[5];

		while(current != NULL){

			int size = 0;
			sprintf(temp, "%d", current -> data);

			for(int i = 0; i < 5; i++){

				size = i;

				if(temp[i] == 0){
					break;
				}
			}

			for(int i = 0; i < size; i++){
				word[index++] = temp[i];
			}

			if(current -> next != NULL){
				word[index++] = ',';
				word[index++] = ' ';
			}

			current = current -> next;
		}

		word[index] = 0;
		printf("%s\n\n", word);
	}
}

int main(){

	printf("This is a linked list structure designed to handle integers\n\n");
	printf("Commands: pwl = print working list, add = insert, rm = remove, mt = clear, cmd = commands, done = end program\n");
	printf("<be sure to add one space after rm & add commands before int parameter>\n\n");

	node* head = NULL;

	while(1){

		//This section handles properly getting information from the user
		char a = 0;
		char input[10];
		int index = 0;

		for(int i = 0; i < 10; i++){
			input[i] = 0;
		}

		while(1){
			a = getchar();
			if(a == '\n'){
				break;
			}
			input[index++] = a;
		}
		input[index] = 0;

		//These cases handle what will happen to the list based on the user input

		//done case
		if(input[0] == 'd' && input[1] == 'o' && input[2] == 'n' && input[3] == 'e' && input[4] == 0){
			break;
		}

		//pwl case
		if(input[0] == 'p' && input[1] == 'w' && input[2] == 'l' && input[3] == 0){
			print_list(head);
		}

		//add case
		else if(input[0] == 'a' && input[1] == 'd' && input[2] == 'd' && input[3] == ' '){

			char num[5];
			int numDex = 4;
			int indexNum = 0;

			while(input[numDex] != 0){
				num[indexNum++] = input[numDex++];
			}
			num[indexNum] = 0;

			int conversion = atoi(num);

			head = add(head, conversion);

			printf("%d was added to the list\n\n", conversion);

		}

		//rm case
		else if(input[0] == 'r' && input[1] == 'm' && input[2] == ' '){

			char num[5];
			int numDex = 3;
			int indexNum = 0;

			while(input[numDex] != 0){
				num[indexNum++] = input[numDex++];
			}

			num[indexNum] = 0;

			int conversion = atoi(num);

			node* check = deleteNode(head, conversion);

			if(check != NULL){
				head = check;
				printf("%d was removed from the list\n\n", conversion);
			}else{
				printf("%d was not in the list\n\n", conversion);
			}

		}

		//mt case
		else if(input[0] == 'm' && input[1] == 't' && input[2] == 0){
			head = clear(head);
			printf("The list has been cleared\n\n");

		}

		//cmd case
		else if(input[0] == 'c' && input[1] == 'm' && input[2] == 'd' && input[3] ==0){
			printf("pwl = print working list, add = insert, rm = remove, mt = clear, cmd = commands, done = end program\n\n");
		}

		//incorrect command format
		else{
			printf("Command was entered incorrectly\n\n");
		}
	}

	printf("\nUser is done with the linked list\n");
}
