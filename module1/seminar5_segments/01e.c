#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
    Book a;
    strcpy(a.title, "Don Quixote");
    a.pages = 1000;
    a.price = 750.0f;
    
    
    Book* p = (Book*)malloc(sizeof(Book));
    p = &a;
    Book** q = &p;
    
    print_book(*q);
    free(p);
}