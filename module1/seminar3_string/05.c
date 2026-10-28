#include <stdio.h>

int main(){
    char a[100];
    scanf("%s", a);
    int i = 0;
    int res = 0;
    while (a[i] != '\0'){
        res += (int)a[i] - 48;
        i += 1;
    }
    printf("%i", res);
}