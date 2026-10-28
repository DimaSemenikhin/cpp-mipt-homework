#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

void print_book(const Book* b) {
    printf("Title: %s, Pages: %d, Price: %.1f\n", b->title, b->pages, b->price);
}

int main() {
    Book* p = (Book*)malloc(sizeof(Book));
    
    strcpy(p->title, "Don Quixote");
    p->pages = 1000;
    p->price = 750.0f;
    
    print_book(p);
    
    free(p);
}