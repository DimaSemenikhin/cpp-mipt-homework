#include <stdio.h>
#include <math.h>

struct point
{
    double x;
    double y;
};
typedef struct point Point;

struct triangle
{
    Point a;
    Point b;
    Point c;
};
typedef struct triangle Triangle;

void print_point(struct point a){
    printf("(%lf, %lf)", a.x, a.y);
}

void print_triangle(struct triangle* t){
    printf("{");
    print_point((*t).a);
    printf(", ");
    print_point((*t).b);
    printf(", ");
    print_point((*t).c);
    printf(", ");
    printf("}\n");
}

double distance(struct point a, struct point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double get_triangle_perimeter(struct triangle* const t){
    return distance((*t).a, (*t).b) + distance((*t).c, (*t).b) + distance((*t).a, (*t).c); 
}

struct triangle moved_triangle(struct triangle* const t, struct point a){
    struct triangle t1;
    t1.a.x = (*t).a.x + a.x;
    t1.b.x = (*t).b.x + a.x;
    t1.c.x = (*t).c.x + a.x;
    t1.a.y = (*t).a.y + a.y;
    t1.b.y = (*t).b.y + a.y;
    t1.c.y = (*t).c.y + a.y;
    return t1;
}

void move_triangle(struct triangle* const t, struct point a){
    (*t).a.x = (*t).a.x + a.x;
    (*t).b.x = (*t).b.x + a.x;
    (*t).c.x = (*t).c.x + a.x;
    (*t).a.y = (*t).a.y + a.y;
    (*t).b.y = (*t).b.y + a.y;
    (*t).c.y = (*t).c.y + a.y;
}


int main()
{
    Triangle t = {{1.00, 0.00}, {0.50, 2.00}, {0.00, 1.50}};
    printf("Perimeter = %.2f\n", get_triangle_perimeter(&t));

    Point d = {1.0, 1.0};
    print_triangle(&t);
    move_triangle(&t, d);
    print_triangle(&t);
}