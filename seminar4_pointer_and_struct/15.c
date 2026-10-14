#include <stdio.h>

struct node
{
    int value;
    struct node* ptr;
};
typedef struct node Node;

void print_and_move(struct node* a){
    printf("%i\n", (*a).value);
    print_and_move((*a).ptr);
}

int main(){
    Node Node1;
    Node Node2;
    Node Node3;
    Node1.value = 100;
    Node2.value = 200;
    Node3.value = 300;
    Node1.ptr = &Node2;
    Node2.ptr = &Node3;
    Node3.ptr = &Node1;

    print_and_move(&Node1);
}