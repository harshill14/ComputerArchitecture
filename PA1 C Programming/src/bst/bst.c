#include <stdio.h>
#include <stdlib.h>
//Harshil Patel
struct Node {
  int pointer;
  struct Node *left;
  struct Node *right;
};

struct Node* new(int pointer) {

	struct Node *latestNode = (struct Node *)malloc(sizeof(struct Node));
	latestNode->pointer = pointer;
	latestNode->left = NULL;
	latestNode->right = NULL;
	return latestNode;
}
void insert(struct Node *initial, int pointer) {
  if ((*initial).pointer < pointer) {
    if ((*initial).right == 0) {
      (*initial).right = new(pointer);
      return;
    }
    insert((*initial).right, pointer);
  }
  if ((*initial).pointer > pointer) {
    if ((*initial).left == 0) {
      (*initial).left = new(pointer);
      return;
    }
    insert((*initial).left, pointer);
  }
  
}

struct Node* minimum(struct Node* head){
	struct Node* treefree = head;
	while(treefree->left != NULL)
		treefree = treefree->left;
	return treefree;
	}

struct Node* delete(struct Node* head, int point){
	if(head == NULL){
		printf("absent\n"); 
		return NULL;
	} 
	if((*head).pointer > point){
		head->left= delete((*head).left,point);
	} else if((*head).pointer < point) {
		head->right = delete((*head).right,point);
	} else {
		if(head->left == NULL){
			struct Node *newNode = (*head).right;
			free(head);
			return newNode;
		}
		else if((*head).right == NULL){
			struct Node *newNode = head->left;
			free(head);
			return newNode;
		}
		struct Node *newNode = minimum((*head).right);
		(*head).pointer = newNode->pointer;
		(*head).right = delete((*head).right, newNode->pointer);
	}
	return head;
}
int search(struct Node* head, int pointer) {

	if(head == NULL) {
		return 0;
	}

	else {
		if ((*head).pointer == pointer){
			return 1;
		}
		if((*head).pointer < pointer){
			return search((*head).right,pointer);
		}
		else{
			return search((*head).left,pointer);
		}
	}
}

void orderprint(struct Node *head) {
  	if (head == NULL) {
    	return;
  	}
  	printf("(");
  	orderprint((*head).left);
  	printf("%d", (*head).pointer);
  	orderprint((*head).right);
  	printf(")");
}

int main() {
  struct Node *head = NULL;
  char this = '\0';
  int h;
  int counter = 1;


  while (counter >= 0) {
	this = '\0';
    counter = scanf(" %c", &this);
if (this == 'd') {
	counter = counter + scanf("%d", &h);
      if (search(head, h)) {
        if ((*head).left == 0 && (*head).right == 0 && (*head).pointer == h ) {
          head = NULL;
        }
        else {
         head = delete(head, h);
        }
		 printf("deleted\n");
      }
      else {
        printf("absent\n");
	  }
    }

    if (this == 'i') {
		counter = counter + scanf("%d", &h);
      		if (search(head, h)==0) {
       			if (head == NULL) {
          			head = new(h);
        		}
        	else {
        		insert(head, h);
        	}
        	printf("inserted\n");
      	}
      else {
        printf("not inserted\n");
      }
    }
	if (this == 's') {
		counter = counter + scanf("%d", &h);
      		if(search(head, h)) {
        		printf("present\n");
      		}
      		else {
       			printf("absent\n");
      		}
    	}
    if (this == 'p') {
      orderprint(head);
      printf("\n");
    }
  }
  free(head);
  return 0;
}
