#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Harshil Patel
int proportion=0; 
int ** eval(int ** first, int** mod, int exp) {
	int add=0;
	int ** calc = (int **)malloc(sizeof(int *) * proportion);
	
	for (int i =0; i<proportion; i++) {
		calc[i] = (int *)malloc(sizeof(int)* proportion);
	}

	for (int h=0; h< proportion; h++) {
		for (int p=0; p< proportion; p++) {
			for (int s=0; s< proportion; s++)	{
				add = add + first [h][s] * mod[s][p];
			}
			calc[h][p] = add;
			add=0;
		}
	}
  if (exp==0) {
		for (int i = 0; i<proportion; i++){
			for (int j= 0; j<proportion; j++) {
				if (i==j) {
					mod[i][j] = 1;
				}else {
					mod[i][j] = 0;
				}
				
			}
		} 
	}
	free(mod);
	return calc;
}

void print(int** first,int proportion){
for(int h=0;h<proportion;h++){
  for(int p=0;p<proportion;p++){
    int fin =first[h][p];
    if(p==proportion-1){
      printf("%d",fin);
    }else{
      printf("%d ",fin);
    }
  }
  printf("\n");
}
}

int main (int argc, char** argv) {
	
  int h;
  int p;
  int power;
  int c = 0;
  FILE *f =fopen(argv[1],"r");

	if(f==NULL){
 printf("error\n");
 return 0;
}

	fscanf(f, "%d\n", &proportion);
	int ** first = (int ** )malloc(sizeof(int *) * proportion);
	int ** result = (int ** )malloc(sizeof(int *) * proportion);
	
	while(c<proportion) {
		first[c] = (int*)malloc(sizeof(int) * proportion);
    	result[c] = (int*)malloc(sizeof(int) * proportion);
		c++;
	}
	
	for (h=0; h<proportion; h++){
		for (p=0; p<proportion; p++) {
			fscanf(f, "%d", &first[h][p]);
			result[h][p] = first [h][p];
		}
	}
	fscanf(f, "%d", &power);
	for (h=1; h<power; h++) {
		result = eval(first, result, power);	
	}
  print(result,proportion);
  for(int i = 0; i<proportion; i++){
        free(first[i]);
    	free(result[i]);
    }
	free(first);
	fclose(f);
	return EXIT_SUCCESS;
}