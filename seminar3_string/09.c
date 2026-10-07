#include <stdio.h>
#include <string.h>


void trim_after_first_space(char str[]){
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        if (str[i] == ' '){
            str[i] = '\0';
            break;
        }
    }
}

int main(){
    char a[] = "Cats and Dogs";
    printf("%s\n", a);
    trim_after_first_space(a);
    printf("%s\n", a);
}