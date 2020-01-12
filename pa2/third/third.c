#include <stdio.h>
#include <stdlib.h>

int get(int x, int n);
int main(int argc, char* argv[])
{
	unsigned short  x = atoi(argv[1]);
	int n = 0;
	int n2 = 15;     
    	for(n=0;n<n2;n++,n2--){
        	if(get(x,n)!=get(x,n2)){
            		printf("Not-Palindrome\n");
            		return 0;
       		}
    		
    }
    printf("Is-Palindrome\n");
    return 0;
}

int get(int x, int n){
return (x>>n) & 1;
}
