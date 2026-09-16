#include <stdio.h>

enum shape{
    ROCK,
    PAPER,
    SCISSORS
};

enum result{
    LOSS,
    DRAW,
    WIN
};

void print_shape(enum shape a){
    switch (a){
        case ROCK:
            printf("Rock\n");
            break;
        case PAPER:
            printf("Paper\n");
            break;
        case SCISSORS:
            printf("Scissors\n");
            break;
    }
}

void print_result(enum result a){
    switch (a){
        case WIN:
            printf("Win\n");
            break;
        case LOSS:
            printf("Loss\n");
            break;
        case DRAW:
            printf("Draw\n");
            break;
    }    
}

enum shape get_strength(enum shape a){
    return (a + 1) % 3;
}


enum result get_result(enum shape a, enum shape b){
    if (b == get_strength(a)) return LOSS;
    if (a == get_strength(b)) return WIN;
    return DRAW;    
}


int main(){
    enum shape a;
    enum shape b;
    scanf("%i %i", &a, &b);
    printf("Player 1: ");
    print_shape(a);
    printf("Player 2: ");
    print_shape(b);
    printf("Player 1: ");
    print_result(get_result(a, b));

}