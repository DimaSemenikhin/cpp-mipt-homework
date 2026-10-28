#include <stdio.h>
#include <math.h>


void Intersect(float x1, float y1, float r1, float x2, float y2, float r2){
    float dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    float dif = r1 + r2 - dist;
    float eps = 0.00001;
    if ((dif <= eps) && (dif >= -eps)) {
        printf("Touch\n");
        return;
    }
    if (dif < -eps){
        printf("Do not intersect");
        return;
    }
    printf("Intersect");
}

int main(){
    float x1;
    float y1;
    float r1;
    float x2;
    float y2;
    float r2;
    scanf("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);
    Intersect(x1, y1, r1, x2, y2, r2);
}