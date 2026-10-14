#include <stdio.h>
#include <string.h>

char* strmax(char** strings, size_t n){
    char* max = strings[0];

    for (size_t i = 0; i < n; i++){
        if (strcmp(strings[i], max) > 0){
            max = strings[i];
        }
    }
    return max;
}

int main(){
    char a[] = "Cat";
    char b[] = "Mouse";
    char c[] = "Wolf";
    char d[] = "Kangaroo";
    char e[] = "Elephant";
    char* animals[5] = {&a[0], &b[0], &c[0], &d[0], &e[0]};
    char* x = strmax(animals, 5);
    printf("%s\n", x);
}