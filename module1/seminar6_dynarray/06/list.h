#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

#define DEFINE_LIST(T, TYPE_NAME) \
\
    struct Node_##TYPE_NAME { \
        T value; \
        struct Node_##TYPE_NAME* next; \
        struct Node_##TYPE_NAME* prev; \
    }; \
    typedef struct Node_##TYPE_NAME Node_##TYPE_NAME; \
\
    struct List_##TYPE_NAME { \
        Node_##TYPE_NAME* head; \
        Node_##TYPE_NAME* tail; \
        size_t size; \
    }; \
    typedef struct List_##TYPE_NAME List_##TYPE_NAME; \
\
    void push_back_##TYPE_NAME(List_##TYPE_NAME* pl, T value) { \
        Node_##TYPE_NAME* new_node = (Node_##TYPE_NAME*)malloc(sizeof(Node_##TYPE_NAME)); \
        assert(new_node != NULL); \
        new_node->value = value; \
        new_node->next = NULL; \
        new_node->prev = pl->tail; \
        if (pl->tail != NULL) { \
            pl->tail->next = new_node; \
        } else { \
            pl->head = new_node; \
        } \
        pl->tail = new_node; \
        pl->size++; \
    } \
    List_##TYPE_NAME init_##TYPE_NAME(size_t n) { \
        List_##TYPE_NAME new_list = {NULL, NULL, 0}; \
        for (size_t i = 0; i < n; ++i) { \
            T zero; \
            memset(&zero, 0, sizeof(T)); \
            push_back_##TYPE_NAME(&new_list, zero); \
        } \
        return new_list; \
    } \
\
    void print_##TYPE_NAME(const List_##TYPE_NAME* pl, void (*print_func)(T)) { \
        Node_##TYPE_NAME* current = pl->head; \
        while (current != NULL) { \
            print_func(current->value); \
            current = current->next; \
        } \
        printf("\n"); \
    } \
\
\
    T pop_back_##TYPE_NAME(List_##TYPE_NAME* pl) { \
        assert(pl->tail != NULL); \
        Node_##TYPE_NAME* old_tail = pl->tail; \
        T val = old_tail->value; \
        pl->tail = old_tail->prev; \
        if (pl->tail != NULL) { \
            pl->tail->next = NULL; \
        } else { \
            pl->head = NULL; \
        } \
        free(old_tail); \
        pl->size--; \
        return val; \
    } \
\
    void push_front_##TYPE_NAME(List_##TYPE_NAME* pl, T value) { \
        Node_##TYPE_NAME* new_node = (Node_##TYPE_NAME*)malloc(sizeof(Node_##TYPE_NAME)); \
        assert(new_node != NULL); \
        new_node->value = value; \
        new_node->prev = NULL; \
        new_node->next = pl->head; \
        if (pl->head != NULL) { \
            pl->head->prev = new_node; \
        } else { \
            pl->tail = new_node; \
        } \
        pl->head = new_node; \
        pl->size++; \
    } \
\
    T pop_front_##TYPE_NAME(List_##TYPE_NAME* pl) { \
        assert(pl->head != NULL); \
        Node_##TYPE_NAME* old_head = pl->head; \
        T val = old_head->value; \
        pl->head = old_head->next; \
        if (pl->head != NULL) { \
            pl->head->prev = NULL; \
        } else { \
            pl->tail = NULL; \
        } \
        free(old_head); \
        pl->size--; \
        return val; \
    } \
\
    Node_##TYPE_NAME* erase_##TYPE_NAME(List_##TYPE_NAME* pl, Node_##TYPE_NAME* p) { \
        if (p == NULL) return NULL; \
        Node_##TYPE_NAME* next_node = p->next; \
        if (p->prev != NULL) { \
            p->prev->next = p->next; \
        } else { \
            pl->head = p->next; \
        } \
        if (p->next != NULL) { \
            p->next->prev = p->prev; \
        } else { \
            pl->tail = p->prev; \
        } \
        free(p); \
        pl->size--; \
        return next_node; \
    } \
\
    void splice_##TYPE_NAME(List_##TYPE_NAME* plist, Node_##TYPE_NAME* p, List_##TYPE_NAME* pother) { \
        if (pother->head == NULL) return; \
        if (p == NULL) { \
            if (plist->tail != NULL) { \
                plist->tail->next = pother->head; \
                pother->head->prev = plist->tail; \
            } else { \
                plist->head = pother->head; \
            } \
            plist->tail = pother->tail; \
        } else { \
            Node_##TYPE_NAME* prev_p = p->prev; \
            pother->head->prev = prev_p; \
            if (prev_p != NULL) { \
                prev_p->next = pother->head; \
            } else { \
                plist->head = pother->head; \
            } \
            pother->tail->next = p; \
            p->prev = pother->tail; \
        } \
        plist->size += pother->size; \
        pother->head = NULL; \
        pother->tail = NULL; \
        pother->size = 0; \
    } \
\
    void destroy_##TYPE_NAME(List_##TYPE_NAME* pl) { \
        Node_##TYPE_NAME* current = pl->head; \
        while (current != NULL) { \
            Node_##TYPE_NAME* next = current->next; \
            free(current); \
            current = next; \
        } \
        pl->head = NULL; \
        pl->tail = NULL; \
        pl->size = 0; \
    } \
\
    void advance_##TYPE_NAME(Node_##TYPE_NAME** pp, size_t n) { \
        Node_##TYPE_NAME* current = *pp; \
        size_t i = 0; \
        while (current != NULL && i < n) { \
            current = current->next; \
            i++; \
        } \
        *pp = current; \
    }
