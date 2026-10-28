#include "list.h"
#include <stdio.h>

void print_func_int(int a){
    printf("%i ", a);
}
void print_func_char(char a){
    printf("%c ", a);
}


int main(){
    DEFINE_LIST(char, char);
    DEFINE_LIST(int, int);

    List_int a = init_int(0);

    for (int i = 0; i < 5; ++i)
        push_back_int(&a, 10 * (i + 1));
    for (int i = 0; i < 5; ++i)
        push_front_int(&a, 100 * (i + 1));

    print_int(&a, print_func_int);



    List_char b = init_char(0);

    for (int i = 0; i < 5; ++i)
        push_back_char(&b, 'b');
    for (int i = 0; i < 5; ++i)
        push_front_char(&b, 'a');

    print_char(&b, print_func_char);
    
}