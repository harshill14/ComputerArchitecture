#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 1000
// Harshil Patel

double** trapsone(double** arrayin, int r, int c);
double** multiply(double** A, int Asize, int ACol, double** B, int BCol);
double** inverse(int dim, double** arrayin);

double** multiply(double** A, int Asize, int ACol, double** B, int BCol){
    double** multiply = calloc(Asize, sizeof(double*));
    //malloc in triple forloop
    for(int i = 0; i < Asize; i++) {
        multiply[i]= (double*)calloc(BCol, sizeof(double));
        for (int j = 0; j < BCol; j++) {
            //row of test1 matrix and column of test2 will be final dimensions
            multiply[i][j] = 0;
            for (int k = 0; k < ACol; k++) {
                multiply[i][j] = (B[k][j]*A[i][k]) + multiply[i][j] ;
            }
        }
    }
    return multiply;
}
double** trapsone(double** arrayin, int r, int c){
    //used calloc for memory allocation
    double **trapsone = (double **)calloc(sizeof(double *), c);
    for(int a=0; a < c; a++){
        trapsone[a] = (double *)calloc(sizeof(double), r);
        for(int b=0; b < r; b++){
            trapsone[a][b] = arrayin[b][a];
        }
    }
    return trapsone;
}
double** inverse(int dim, double** arrayin) {
    //FOLLOWED FORMAT OF PDF INVERSE STEPS
	double** inverted = (double**) calloc(dim, sizeof(double*));
	for (int i = 0; i < dim; i++) {
		inverted[i] = (double*) calloc(dim, sizeof(double));
		//setting identity matrix 
        for (int j = 0; j <  dim; j++) {
			if (i != j) {
				inverted[i][j] = 0;
			} else {
				inverted[i][j] = 1;
			}
		}
	}
    //identity matrix completed
    //dim is going to be the test1input test2input dimensions
    // line is f<-Mp,p
	for (int h = 0; h < dim; h++) { 
			double line = arrayin[h][h];
			for (int j = 0; j < dim; j++) {
               //divide arrayinay be the line or diagonal
               //line is supposed to be slant
               arrayin[h][j] = (arrayin[h][j] / line);
                //divide identity matrix by line
				inverted[h][j] = (inverted[h][j] / line);
			}
		for (int p = 0; p < dim; p++) {
			if (h != p) { 
                //f is the f<- Mi,p from pdf
				double f = arrayin[p][h];
				for (int l = 0; l < dim; l++) {
                    //subtract arrayinayi*f from arrayinayk
					arrayin[p][l] =  arrayin[p][l] - (f *  arrayin[h][l]);
                    //subtract identityarrayinayi*f from arrayinayk
					inverted[p][l] =  inverted[p][l] - (f * inverted[h][l]);
				}
            }
		}
	}
	return inverted;
}


int main(int argc, char** argv) {
    //declaration
    int a, b, c, d, x, y, dataCount, Counter, Counter2;
    //insert first
    FILE *test1input = fopen(argv[1], "r");
    //in case empty
    if (test1input == NULL) {
		printf("error\n");
		return 0;
	}
    //skip line
    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof line, test1input);
    //insert second
    FILE *test2input = fopen(argv[2], "r");
    // in case empty
     if (test2input == NULL ) {
		printf("error\n");
		return 0;
	}
    //skip line
    fgets(line, sizeof line, test2input);
    fgets(line, sizeof line, test2input);
    fscanf(test1input, "%d %d", &dataCount, &Counter);
    fscanf(test2input, "%d\n" , &Counter2);
   
    int hp = dataCount+1;
    double** coordinate2 = (double**)malloc(Counter*sizeof(double*));
    double** coordinate1 = (double**)malloc(Counter*sizeof(double*));
    for(int x=0; x<Counter; x++){
        coordinate1[x]= (double*)malloc((dataCount+1)*sizeof(double));
        coordinate2[x]= (double*)malloc(1*sizeof(double));
        coordinate1[x][0] = 1;
        for(int y=1; y< dataCount+2; y++){
            if(y!=(dataCount+1)){
                fscanf(test1input, "%lf" , &coordinate1[x][y]);
            }
            else {
                fscanf(test1input, "%lf" , &coordinate2[x][0]);
            }
        }
    }
    dataCount++;
    double** resume = trapsone(coordinate1, Counter, dataCount);
    double** start = multiply(resume, dataCount, Counter, coordinate1, dataCount);
    double** test1 = inverse(hp, start);
    double** test2 = multiply(resume, dataCount, Counter, coordinate2, 1);
    double** test3 = multiply(test1, dataCount, dataCount, test2, 1);
    double finish = test3[0][0];
    double** finalarr = (double**)malloc((dataCount-1)*sizeof(double*));
    for(x=0; x<(dataCount-1); x++){
        finalarr[x]=(double*)malloc(1*sizeof(double));
        finalarr[x][0]=test3[x+1][0];
    }
    dataCount--;
    double** test= (double**)malloc(Counter2*sizeof(double*));;
    for(x=0; x< Counter2; x++){
        test[x]= (double*)malloc(dataCount*sizeof(double));
        for(y=0; y< dataCount; y++){
                fscanf(test2input, "%lf", &test[x][y]);
                fscanf(test2input, ",");
            }
        fscanf(test2input, "\n");
    }
    double** factor =(double**)malloc(Counter2*sizeof(double*));
    for(x=0; x< Counter2; x++){
        factor[x]= (double*)malloc(1* sizeof(double));
        for(y=0;y<dataCount;y++){
                factor[x][0]+=(finalarr[y][0]*test[x][y]);
            }   
        factor[x][0]+=finish;
    }
    for(x=0; x < Counter2; x++){
        printf("%.0f\n", factor[x][0]);
    }
    a = 0;
    while (a < Counter) {
        free(coordinate1[a]);
        free(coordinate2[a]);
        a++;
    }
    b = 0;
    while (b < hp) {
        free(resume[b]);
        free(start[b]);
        free(test1[b]);
        free(test2[b]);
        free(test3[b]);
        b++;
    }
    c = 0;
    while (c < dataCount) {
        free(finalarr[c]);
        c++;
    }
    d = 0;
    while(d < Counter2){
        free(test[d]);
        free(factor[d]);
        d++;
    }
    free(coordinate1);
    free(coordinate2);
    free(resume);
    free(start);
    free(test1);
    free(test2);
    free(test3);
    free(finalarr);
    free(test);
    free(factor);
    
    return 0;
}