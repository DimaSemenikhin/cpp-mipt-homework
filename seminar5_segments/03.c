#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* concat(const char* a, const char* b){
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);

    char* p = (char*)malloc((len_a + len_b + 1) * sizeof(char));
    strcpy(p, a);
    strcat(p, b);

    return p;
}

int main(){
    char a[6] = "aaaaa";
    char b[5] = "bbbb";
    char* pa = a;
    char* pb = b;
    char* p = concat(pa,pb);
    printf("%s\n", p);

    free(p);
    p = NULL;
}