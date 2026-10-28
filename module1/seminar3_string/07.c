#include <stdio.h>
#include <string.h>

void encrypt(char* str, int k){
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        if ((str[i] >= 'A') && (str[i] <= 'Z')){
            str[i] = (str[i] - 'A' + k) % 26 + 'A';
        }
        if ((str[i] >= 'a') && (str[i] <= 'z')){
            str[i] = (str[i] - 'a' + k) % 26 + 'a';
        }    
    }

}


int main(){
    int k;
    char str[100];
    scanf("%i ", &k);
    scanf("%[^\n]", str);
    encrypt(str, k);
    printf("%s\n", str);
}