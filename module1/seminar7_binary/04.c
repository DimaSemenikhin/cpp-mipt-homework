#include <stdio.h>


int main() {
    unsigned int x = 1;
    unsigned char *c = (unsigned char *)&x;
    
    if (*c == 1) {
        printf("1");
    } else {
        printf("0");
    }
}