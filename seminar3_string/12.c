#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
    char* a = argv[1];
    int k = atoi(argv[2]);
    for (int i = 0; i < k; i++){
        printf("%s ", a);
    }
    printf("\n");


}