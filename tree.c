#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
	int free;
}*root;

struct Node *createNode(int);
void displayTree();
int attach(struct Node *);
void search(int);

int main()
 {
 	int val, ch;
 	A:
 		system("cls");
 		printf("MENU : \n\n 1. Insert element\n 2. Search element\n  choice : ");
 		scanf("%d", &ch);
 		switch(ch){
 			case 1 : {
 				system("cls");
 				printf("Enter the element to be inserted : ");
 				scanf("%d", &val);
 				attach(createNode(val));
 				printf("\nElement attached..");
 				getch();
				goto A;
			 }
			 case 2: {
			 	system("cls");
			 	printf("Enter the element to be searched : ");
			 	scanf("%d", &val);
			 	search(val);
			 	getch();
				goto A;
			 }
			 default : printf("\nEnter a valid choice! "); getch(); goto A;
		 }
 	
 	return 0;
 }
 
 struct Node *createNode(int data){
 	struct Node *child = (struct Node *) malloc(sizeof(struct Node));
 	child->data = data;
 	child->left = NULL;
 	child->right = NULL;
 	return child;
 }
 
int attach(struct Node *child){
 	if(root == NULL){
 			root = child;
 			return;
		 }
 	struct Node *parent = root;
 	while(1){
// 		printf("Entering while..\n");
		if(child->data <= parent->data){
			if(parent->left == NULL){
				parent->left = child;
				return;
			}
			parent = parent->left;
		}
		else{
			if(parent->right == NULL){
				parent->right = child;
				return;
			}
			parent = parent->right;
		}
	 }
 }
 
 
void search(int data){
	printf("\nInitiating search..\n");
	struct Node *current = root;
 	while(1){
 		if(current == NULL){
 			printf("Not found..\n");
 			break;
		 }
 		else if(current->data == data){
 			printf("Found!\n");
 			break;
		 }
		else if(data < current->data){
			printf("Checking left of %d..\n", current->data);
		 	current = current->left;
		 }
		else{
			printf("Checking right of %d..\n", current->data);
			current = current->right;
		}
		
	 }
 }
 
void displayTree(){
	if(root == NULL){
		printf("Tree empty!");
	}
	else{
		struct Node *parent = root;
		while(1){
			if(parent==NULL){
				printf("***\n");
				break;
			}
			else{
				printf("%d\t", parent->data);
				parent = parent->right;
			}
		}
	}
}
