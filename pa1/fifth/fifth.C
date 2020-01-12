#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){

char **argv_ptr;
char *ptr;

for(argv_ptr = argv+1; *argv_ptr != argv[argc]; argv_ptr++){

for(ptr = *argv_ptr; *ptr != '\0'; ptr++){
if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u' || *ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U'){
printf("%c",*ptr);
}
}
}
}

