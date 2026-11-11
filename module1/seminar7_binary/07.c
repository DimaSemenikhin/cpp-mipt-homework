#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *file = fopen(argv[1], "rb");

    fseek(file, 0, SEEK_END);
    int len = ftell(file);

    printf("%i\n", len);
    fclose(file);
}