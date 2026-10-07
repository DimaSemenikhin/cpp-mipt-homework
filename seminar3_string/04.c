#include <stdio.h>

int main(){
    char a[100];
    char b[100];
    scanf("%s %s", a, b);
    int i = 0;
    int j = 0;
    while ((a[i] != '\0') || (b[j] != '\0')){
        if (a[i] != '\0'){
            printf("%c", a[i]);
            i += 1;
        }
        if (b[j] != '\0'){
            printf("%c", b[j]);
            j += 1;
        }
    }
}