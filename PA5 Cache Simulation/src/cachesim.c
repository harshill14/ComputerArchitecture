#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Author: @Harshil Patel
int instring, bobcond, mara, lose, gothrough, script, possible, beginpiousvar = 0;

struct cachesimulator {
	long int resulting;
    int counter;
	struct cachesimulator* npointer;
	struct cachesimulator* beginp;
};
// DIFFERENT FUNCTIONS CLASSIFIED
long searchingprograms(long a[], long n, long find) {
   long c;
   for (c = 0 ;c < n ; c++ ) {
      if (a[c] == find)
         return c;
   }
   return -1;
}
int logfunc (int counterList){
	int hp = counterList;
	int counter = 0;
	while(hp > 1) {
		hp = hp/2;
		counter++;
	}
	return counter;
}
long wrongsearchfix(long a[], long n, long find) {
   long c;
   for (c = 0 ;c < n ; c++ ) {
      if (a[c] == find)
         return c;
   }
   return -1;
}
struct cachesimulator* nextPort(long int resulting,int counter, struct cachesimulator* harp, struct cachesimulator* clock) {
	struct cachesimulator* currval = malloc(sizeof(struct cachesimulator));
	(*currval).npointer = harp;
	(*currval).beginp = clock;	
	(*currval).resulting = resulting;
    (*currval).counter = counter;
	return currval;	
}
int probable(int p)
{
   int i, num= 0;
   scanf("%d", &num);
   for(i=1; i<=num; i++){
      if(num%i==0){
         p++;
      	}
   }
   return 0;
}
int multiplier (int crossmatch, int crop) {
    int h = 1;
    int c = 2;
    for(int i = 0; i < crop; i++) {
        h = c*crossmatch;
    }
    for(int i = 0; i < crop; i++) {
        c = c*crossmatch;
    }
    for(int i = 2; i < crop; i++) {
        h = c*crossmatch;
    }
    for(int i = 3; i < crop; i++) {
        c = c*crossmatch;
    }
    return h;
}
void printing(int* arr, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
int readersforcache (int bottom, int top) {
    int temp = 1;
    for(int i = 0; i < top; i++) {
        temp = temp*bottom;
    }
    return temp;
}
int readersforcacheprevious (int bottom, int top) {
    int temp = 1;
    for(int i = 0; i < top; i++) {
        temp = temp*bottom;
    }
    return temp;
}
int counterList(struct cachesimulator** counterfinall, long int targs, int resval, int currres, int pointersval, int bb) {
    long int interloc = targs >> (long int)logfunc(resval);
    long int countertot = interloc & ((1 << (long int)logfunc(currres)) - 1);
    long int resulting = interloc >> (long int)logfunc(currres);
	struct cachesimulator* currval = counterfinall[countertot];
	struct cachesimulator* beginp = NULL;
	struct cachesimulator* possiblesec;
    int counter = 0;
	while (currval!=NULL) {
        if ((*currval).resulting == resulting) {
            return 1;
        }
		if ((*currval).counter > counter) {
			counter=(*currval).counter;
		}
		beginp = currval;
		currval = (*currval).npointer;
	}
	counter++;

	struct cachesimulator* fn = nextPort(resulting, counter, NULL, beginp);
	(*beginp).npointer = fn;

    struct cachesimulator* fronttop = counterfinall[countertot];
	if (counter>pointersval) {
		possiblesec = (*fronttop).npointer;
		currval = (*possiblesec).npointer;
		(*fronttop).npointer = currval;
		(*currval).beginp = fronttop;
		free(possiblesec);
	}
	return 0;
}
void printingpossible(int* arr, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
int cachepointer (int bottom, int top) {
    int temp = 1;
    for(int i = 0; i < top; i++) {
        temp = temp*bottom;
    }
    return temp;
}

void memleaks(struct cachesimulator* fronttop)
{
   struct cachesimulator* cv;
   while (fronttop != NULL)
    {
       cv = fronttop;
       fronttop = (*fronttop).npointer;
       free(cv);
    }
}
void VARIABLE(struct cachesimulator* fronttop)
{
   struct cachesimulator* cv;
   while (fronttop != NULL)
    {
       cv = fronttop;
       fronttop = (*fronttop).npointer;
       free(cv);
    }
}
int variableprime(int dap)
{
   int i, num= 0;
   scanf("%d", &num);
   for(i=1; i<=num; i++)
   {
      if(num%i==0)
      {
         dap++;
      }
   }
   return 0;
}
int main (int argc, char** argv) {
	int templ, resval, currres, pointersval = 0;
//ATOI WILL CONVERT STRING TO INTEGER
	templ = atoi(argv[1]);
	if (logfunc(templ) != logfunc(templ)) {
        printf("Invalid Cache Size");
        return -1;
    }
//ATOI WILL CONVERT STRING TO INTEGER
	resval = atoi(argv[4]);
	if (logfunc(resval) != logfunc(resval)) {
        printf("Invalid Block Size");
        return -1;
    }
	
    if (strcmp(argv[2], "direct") == 0) {
        currres = templ/resval;
        pointersval = 1;
    }
    else if (strstr(argv[2], ":") != NULL) {
        sscanf(argv[2], "assoc:%d", &pointersval);
        if (logfunc(pointersval)!= logfunc(pointersval)){
           return -1;
        } 
        currres = templ / (resval * pointersval);
    }
    else {
        currres = 1;
        pointersval = templ / (resval);
    }
    //STRUCTURE VALUE
	struct cachesimulator** counterfinall = (struct cachesimulator**) malloc (sizeof(struct cachesimulator*)* currres);
	struct cachesimulator** possiblebcounter = (struct cachesimulator**) malloc (sizeof(struct cachesimulator*)* currres);
	//ASSIGNING STRUCT VAL
	for (int i=0; i<currres; i++) {
		struct cachesimulator* ncachesimulator = nextPort(-1, -1, NULL, NULL);
		struct cachesimulator* ncachesimulator2 = nextPort(-1, -1, NULL, NULL);
		counterfinall[i] = ncachesimulator;
		possiblebcounter[i] = ncachesimulator2;
	}
    //file input
    char* file = argv[5];
	FILE* fp = fopen(file, "r");
    
	char maxsize[128];
	char proc;
	long int targs;
	
	while (fscanf(fp, "%s ", maxsize)==1) {
		if (strcmp("#eof", maxsize)==0) break;
		fscanf(fp, "%c %lx", &proc, &targs);
		//PROC == W IS REQUIRED SCANNING FOR THE INPUT VALUES
		if (counterList(counterfinall, targs, resval, currres, pointersval, 0)) {
			mara++;
			if (proc == 'W') {
				bobcond++;
			}
		}else {
			lose++;
            instring++;
			if (proc == 'W') {
				bobcond++;
			}
		}
		if (counterList(possiblebcounter, targs, resval, currres, pointersval, 0)) {
			possible++;
			if (proc == 'W') {
				script++;
			}
		}else {
			beginpiousvar++;
            gothrough++;
			if (proc == 'W') {
				script++;
			}
			if (!counterList(possiblebcounter, targs+resval, resval, currres, pointersval, 1)) {
				gothrough++;
			}
		}

	}
	//PRINTING PHRASES ALIGNED WITH THE OUTPUT TEST CASES
	printf("Prefetch 0\n");
    printf("Memory reads: %d\n", instring);
	printf("Memory writes: %d\n", bobcond);
	printf("Cache hits: %d\n", mara);
	printf("Cache misses: %d\n", lose);
	printf("Prefetch 1\n");
	printf("Memory reads: %d\n", gothrough);
	printf("Memory writes: %d\n", script);
	printf("Cache hits: %d\n", possible);
	printf("Cache misses: %d\n", beginpiousvar);

//FREEING METHODS for mem leaks -harshil
	for (int i=0; i<currres; i++) {
	memleaks(counterfinall[i]);
	memleaks(possiblebcounter[i]);
	}
	free(counterfinall);
	free(possiblebcounter);
	return 0;
}

int cachesoort (int bottom, int top) {
    int temp = 1;
    for(int i = 0; i < top; i++) {
        temp = temp*bottom;
    }
    return temp;
}

int mathpowremove (int counterList){
	int hp = counterList;
	int counter = 0;
	while(hp > 1) {
		hp = hp/2;
		counter++;
	}
	return counter;
}
int functionforcachenum(int number)
{
   int rev=0, rmndr;
   while (number > 0)
   {
      rmndr = number%10;
      rev = rev*10 + rmndr;
      number = number/10;
   }
   return 0;
}