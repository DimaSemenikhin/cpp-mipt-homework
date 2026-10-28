#include <stdio.h>

int main(){
    char a;
    scanf("%c", &a);
    if ((a >= 48) && (a < 58)) printf("Digit");
    else {
        if (((a >= 65) && (a < 91)) || ((a >= 97) && (a < 123))) printf("Letter");
        else printf("Other");
    }
}