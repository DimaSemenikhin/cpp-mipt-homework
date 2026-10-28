#include <stdio.h>
#include <string.h>

void is_palindrom(char a[100]){
    char b[100];
    int len = strlen(a);
    strcpy(b, a);
    for (int i = 0; i < len / 2; i++){
        b[i] = a[len - i - 1];
        b[len - i - 1] = a[i];
    }
    if (strcmp(a, b)) printf("No\n");
    else printf("Yes\n");

}

int main(){
    char a[100];
    
    scanf("%99s", a);
    is_palindrom(a);    
} 