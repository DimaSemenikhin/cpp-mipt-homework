#include <stdio.h>
#include <stdlib.h>

float* get_geometric_progression(float a, float r, int n){
    float* p = (float*)malloc(n * sizeof(float));
    float cur = a;
    for (int i = 0; i < n; i++){
        p[i] = cur;
        cur *= r;
    }
    return p;
}

int main(){
    float* p = get_geometric_progression(3, 3, 10);
    for (int i = 0; i < 10; i++){
        printf("%f\n", p[i]);
    }

    free(p);
    p = NULL;
}