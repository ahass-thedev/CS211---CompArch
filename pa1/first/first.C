#include<stdio.h>
#include<stdlib.h>
#include<cstring>

//fix warning in sort odd or change to descending ordering`
int*  sortEven(int* evenarry, int evencounter){
int z,j,key;
for(z = 1; z < evencounter; z++){
key = evenarry[z];
j = z - 1;
while (j>= 0 && evenarry[j] > key){
evenarry[j+1] = evenarry[j];
j=j-1;
}
evenarry[j+1] = key;
}
int g = 0;
return evenarry;
//for(g=0; g<evencounter; g++)
//printf("Even Sorted:%d\n",evenarry[g]);
}

int* sortOdd(int* oddarry, int oddcounter){
int a;
for(int i = 0; i < oddcounter; ++i){
for(int j = i + 1; j < oddcounter; ++j){
if(oddarry[i] < oddarry[j]){
a = oddarry[i];
oddarry[i] = oddarry[j];
oddarry[j] = a;
}
}
}
return oddarry;
}


int main(int argc, char**argv){

FILE* file = fopen(argv[1],"r");
int numnums;
fscanf(file, "%d\n",&numnums);

int f = 0;
char z;
int arry[numnums];

for(f =0; f < numnums; f++){
fscanf(file, "%d\t", &arry[f]);}
for (f = 0; f < numnums; f++){
//printf("From File: %d\n", arry[f]);
}
//int arry[] ={2,8,1,4,5,6,9,10,14,11,13,17};
int evenarry[20];
int oddarry[20];

int i = 0;
int evencounter = 0;
int oddcounter = 0;

for(i=0; i<(sizeof(arry)/sizeof(arry[0])); i++){
//printf("%d\n",arry[i]);
if(arry[i] % 2 == 0){
evenarry[evencounter]=arry[i];
evencounter++;
//printf("Even:%d\n",evenarry[i]);
}else{
oddarry[oddcounter]=arry[i];
oddcounter++;
}}
fclose(file);
int* sorted_evenarry = sortEven(evenarry,evencounter);
int* sorted_oddarry = sortOdd(oddarry,oddcounter);
int sorted_arry[evencounter+oddcounter]; 
//memcpy(sorted_evenarry + evencounter, sorted_oddarry,sizeof(sorted_oddarry));
for(int a = 0; a < evencounter; a++)
sorted_arry[a] = sorted_evenarry[a];

for(int z = 0; z < oddcounter; z++)
sorted_arry[evencounter+z] = sorted_oddarry[z];

//for(int q = 0; q<(oddcounter); q++ )
//printf("From the odd arry: %d\n",sorted_oddarry[q]);

for(int j = 0; j<(evencounter+oddcounter); j++ )
printf("%d\t",sorted_arry[j]); 
}
