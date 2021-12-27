#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *insertNode(struct Node* newNode, int key){

    if(head == NULL){
        head = newNode;
        return head;
    }
    else if(head ->data > newNode -> data){
        newNode ->next = head;
        head = newNode;
        return head;
    }
    else{
    struct Node *temp = head;
    while(temp->next != NULL && temp -> next -> data < newNode -> data){
        temp = temp->next;
}
    newNode -> next = temp -> next;
    temp -> next = newNode;
    }

    return head;
}

void deleteNode(int key){
    if(head == NULL){
        return;
    }

    struct Node *ptr = NULL;
    struct Node *curr;
    struct Node *prev;

    if(head ->data == key){
        ptr = head->next;
        free(head);
        head = ptr;
        return;
    }

    curr = head->next;
    prev = head;

    while(curr != NULL){
        if(curr->data == key){
            struct Node *newNode = curr;
            prev->next = curr->next;
            free(newNode);
            return;
        }
        curr = curr->next;
        prev = prev->next;
    }

    return;
}

int doesExist(int key){
int count = 0;
struct Node *temp = head;
while(temp != NULL){
if(temp -> data == key){
count = 1;
break;
}
temp = temp -> next;
}
return count;
}

void printList(){
    struct Node *curr = head;
    while(curr != NULL){
        if(curr ->next == NULL){
            printf("%d", curr ->data);
            break;
        }
        printf("%d ", curr ->data);
        curr = curr->next;
    }
    return;
}



int main(int argc, char *argv[]){
    if(argc < 1){
        printf("Insufficient arguments");
       return EXIT_SUCCESS;
    }
    if(argc == 1){
    char Char;
int num;
int len = 0;

        //int key = doesExist(num);
while(scanf("%c\t%d", &Char, &num) != EOF){
int exist = doesExist(num);
        if(Char == 'i'){
if(exist == 0){
    struct Node *new_Node = (struct Node*)malloc(sizeof(struct Node));
new_Node->data = num;
new_Node->next = NULL; 
head = insertNode(new_Node, num);
len++; 
}
if(len == 0){
printf("%d :", len);
printList();
printf("\n");
}
else{ 
printf("%d : ", len);
printList();
printf("\n");
}
        }
        if(Char == 'd'){
if(exist == 1){
            deleteNode(num);
len--;
}
if(len == 0){
printf("%d :", len);
printList();
printf("\n");
}
else{ 
printf("%d : ", len);
printList();
printf("\n");
}
        }
}
    }
    //printList();

    return EXIT_SUCCESS;
}
