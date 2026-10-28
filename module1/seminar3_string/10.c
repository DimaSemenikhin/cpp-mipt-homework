#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%i", &n);
    int x = 0;
    int y = 0;
    char dir[10];
    int dist;
    for (int i = 0; i < n; i++){
        scanf("%s %i", dir, &dist);
        if (strcmp(dir, "North") == 0) y += dist;
        if (strcmp(dir, "South") == 0) y -= dist;
        if (strcmp(dir, "East") == 0) x += dist;
        if (strcmp(dir, "West") == 0) x -= dist;
    }
    printf("x = %i; y = %i", x, y);
}