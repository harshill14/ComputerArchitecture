#include <stdio.h>
#include <ctype.h>
#include <string.h>
//Harshil Patel
int main(int argc, char **argv) {
    int lengthRLE=0;
    int tito = strlen(argv[1]);
    int i = 0;
    int c = 0;
    int num=0;
    char free[5];
    num++;
    num--;
    char * shor = argv[1];

    while (i < tito) {
        if (isdigit(shor[i])) {
        printf ("error");
        putchar('\n');
        return 0;
        }
        int number =1;
        while (shor[i] == shor[i+1]) {
            number++;
            i++;
        }
        sprintf (free,"%c%d",shor[i],number);
        lengthRLE = strlen(free) + lengthRLE;  
        i++;
    }
    if (lengthRLE>strlen(shor)) {
        printf ("%s",shor);
    }
    else if (lengthRLE <= (strlen(shor)) && num == 0){
        while (c < tito) {
            int number = 1;
        while (shor[c] == shor[c+1]) {
                number++;
                c++;
        }
            printf ("%c%d",shor[c],number);
            c++;
        }
        putchar('\n');
    }
    return 0;
}
