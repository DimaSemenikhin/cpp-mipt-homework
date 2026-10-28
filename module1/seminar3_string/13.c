#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if (argc != 2){
        printf("Error: Wrong Number of Arguments\n");
        return 0;
    }
    char* str = argv[1];
    char op; 
    char num1[100], num2[100];
    int i = sscanf(str, "%s %c %s", num1, &op, num2);
    if (i != 3) {
        printf("Error: Invalid format\n");
        return 0;
    }
    if ( (op != '+') && (op != '-') && (op != '*') && (op != '/') && (op != '%') ) {
        printf("Error: invalid operator\n");
        return 0;
    }

    int a = atoi(num1);
    int b = atoi(num2);
    if (op == '+') printf("%i\n", a + b);
    if (op == '-') printf("%i\n", a - b);
    if (op == '*') printf("%i\n", a * b);
    if (op == '%') printf("%i\n", a % b);
    if (op == '/') {
        if (b == 0) printf("Error: Division by zero");
        else printf("%i\n", a / b);
    }
}