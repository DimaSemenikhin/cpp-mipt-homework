#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    char** p = (char**)malloc(sizeof(char*));
    *p = (char*)malloc(sizeof(char) * 14);
    
    strcpy(*p, "Cats and Dogs");

    printf("%s\n", *p);

    free(*p);
    free(p);
}