#include <stdio.h>
#include <ctype.h>
//Harshil Patel
int main(int argc, char *argv[]) {
    char* c = argv[1];
    int init = argv[1][0];
    int i = 0;
    char input = '\0';
    if (argc == 2) {
        char *key = c;
        if (init != input) {
            while(key[i] != input) {
                printf("%c", toupper(key[i]));
                i++;
            }
            printf("%s%c", "!!", '\n');
            }
    }
    return 0;
}




