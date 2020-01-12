#include <stdio.h>
#include <stdlib.h>

int isPair(int x, int bit);
int get(int x, int n);
int main(int argc, char *argv[])
{
unsigned short int target  = atoi(argv[1]);
short int numPairs = 0;
short int ones = 0;
short int sequence_tracker = 0;

while(target){
if(target & 01){
ones++;
sequence_tracker++;
}
else{
sequence_tracker = 0;
}

if( sequence_tracker == 2){
numPairs++;
sequence_tracker = 0;
}
target >>= 1;
}

if(ones % 2 == 0)
printf("Even-Parity\t%d" , numPairs);
else
printf("Odd-Parity\t%d" , numPairs);
return 0;
}
int isPair(int x , int bit){
if(get(x,bit)==1&&get(x,bit+1)){
return 1;
}
return 0;
}
int get(int x, int n){
return (x>n) & 1;
}




