#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Harshil Patel
char peek(char *s);

void push(char input, char *s);

char pop(char *s);

int great = 0;
int i = 0;
int count = 0;



int main(int argc, char** argv){
    char *s;
    s = calloc(strlen(argv[1]), sizeof(char));

    while(i < strlen(argv[1])) {
       if(argv[1][i] == '(' || argv[1][i] == '{' || argv[1][i] == '[' ){
          push(argv[1][i], s);
      }
      if(argv[1][i] == ')' ){
          if(peek(s) == '(') { 
                    pop(s);
      }
        else{
            printf("%d: )", i);
                    return(1);
                    free(s); 
        }
      }
      if(argv[1][i] == ']' ){
          if(peek(s) == '[') {
                    pop(s);
                
                }
                else {
                    printf("%d: ]", i);
                    return(1);
                    free(s);
                }
      }
      if(argv[1][i] == '}' ){
          if(peek(s) == '{') {
                    pop(s);
      }
      else{
          printf("%d: }", i);
                    return(1);
                    free(s);
      }
      }
        i++;
    }
  int hp = strlen(argv[1]);
    if((peek(s)=='(') || (peek(s)=='{') || (peek(s)=='[')){
            printf("open: ");
                while(count < hp){
                     switch(pop(s)){
                     case '(':printf("%c",')');break;
                     case '{':printf("%c",'}');break;
                     case '[':printf("%c",']');break; 
                     }
                    count++;
                    } 
            free(s);
            return(1);
        }
        if((peek(s)=='{')){
            printf("open: ");
                while(count < hp){
                     switch(pop(s)){
                     case '(':printf("%c",')');break;
                     case '{':printf("%c",'}');break;
                     case '[':printf("%c",']');break; 
                     }
                    count++;
                    } 
            free(s);
            return(1);
        }
        if((peek(s)=='[')){
            printf("open: ");
                while(count < hp){
                     switch(pop(s)){
                     case '(':printf("%c",')');break;
                     case '{':printf("%c",'}');break;
                     case '[':printf("%c",']');break; 
                     }
                    count++;
                    } 
            free(s);
            return(1);
        }

    return (0);
}
// function 1
char peek(char *s) {
    
    if(great > 0) {
        char decrease = s[great-1];
        return decrease;
    } 
    else {
        char limit = '\0';
        return limit;
    }
}
// function 2
void push(char input, char *s) {
    s[great] = input;
    great++;
}

// function 3
char pop(char *s) {
    if(great > 0) {
    char decrease = s[great-1];
    great--;
    return decrease;
    }
    else {
        char limit = '\0';
        return limit;
    }
}







