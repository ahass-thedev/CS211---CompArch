#include <stdio.h>
#include <stdlib.h>

int get(unsigned int x, int n);
int set(unsigned int x, int n, int v);
int comp(unsigned int x, int n);

int main(int argc, char* argv[])
{
unsigned int x;
int n,v;
char line[50] , operation[50];
FILE *file = fopen(argv[1],"r");

fgets(line,49,file);
sscanf(line,"%u",&x);

while(fgets(line,49,file)){
sscanf(line,"%s %d %d", operation, &n,&v);
switch(operation[0]){
case'g':
printf("%d\n",get(x,n));
break;
case's':
x  = set(x,n,v);
printf("%d\n",x);
break;
case'c':
x = comp(x,n);
printf("%d\n",x);
break;
}
}
fclose(file);
}
int get (unsigned int x,int n){
	return (x>>n) & 1;
}
int set(unsigned int x, int n, int v){
	return (x&(1<<n)^x | ( v<<n));
}
int comp(unsigned int x, int n){
	return  x ^ (1<<n);
}
