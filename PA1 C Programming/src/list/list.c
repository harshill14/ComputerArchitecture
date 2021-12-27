#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//Harshil Patel
struct Node {
  int info;
  struct Node *right;
};

struct Node* insert(struct Node *root, struct Node *list, int selection) {

  if ((*list).info == selection) {
    return list;
  }
  
  if ((*list).info > selection) {
    struct Node *check = malloc(sizeof(struct Node));
    (*check).right = root;
    (*check).info = selection;
    root = check;
    return root;
  }
  if ((*list).info < selection) {
    if (((*list).right && (*list).right -> info > selection) || (*list).right == 0) {
      struct Node *check = malloc(sizeof(struct Node));
      (*check).right = (*list).right;
      (*check).info = selection;
      (*list).right = check;
      return root;
    }
  }

  return insert(root, (*list).right, selection);
}

//recursive
struct Node* delete(struct Node *root, int selection) {
  if (root == NULL)
        return NULL;
    if(root->info == selection) {
        struct Node* temp =(*root).right;
        free(root);
        return temp;
        
    } else {

        (*root).right = delete((*root).right, selection);
        
    }
   
    return root;
}

int search(struct Node *root, int selection) {
    struct Node *temp = root;
    int count = 0;
    while(temp != NULL){
        if((*temp).info == selection){
            count = 1;
            break;
        }
        temp = (*temp).right;
    }   
    return count;
}

void print(struct Node *list) {
   struct Node *pres = list;
    if(pres != NULL){
            printf(" %d", (*pres).info);
            print(pres -> right);
        }
        else{ 
             printf("\n");
    }
}

int main(int argc, char **argv) {
  struct Node *root = NULL;
  int counter = 0;
  char input;
  int num;
 
  while (scanf("%c\t%d", &input, &num) != EOF) {
    if (input == 'i') {
      if (root == 0) {
        root = malloc(sizeof(struct Node));
        (*root).info = num;
        (*root).right = NULL;
        counter++;
      }
      else if (search(root, num) == 0){
        root = insert(root, root, num);
        counter++;
      }
    }
    if (input == 'd' && search(root, num)) {
      root = delete(root, num);
      counter--;
    }
    if (input == 'i' || input == 'd') {
      printf("%d :", counter);
      print(root);
    }  
  }
  free(root);
  return EXIT_SUCCESS;
}
