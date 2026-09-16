#include <stdio.h>
#define MAX 100

void assign(float A[MAX][MAX], float B[MAX][MAX], int n){
    for (int i = 0; i < n; i++ ){
        for (int j = 0; j < n; j++ ){
            A[i][j]=B[i][j];
        }
    }
}

void multiply(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int n){
    for (int i = 0; i < n; i++ ){
        for (int j = 0; j < n; j++){
            C[i][j] = 0;
            for (int k =0 ; k < n; k++ ){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void power(float A[MAX][MAX], float C[MAX][MAX], int n, int k){
    float B[MAX][MAX];
    while (k != 0){
        if (k % 2 == 1){
            assign(B, C, n);
            multiply(A, B, C, n);
        }
        assign(B, A, n);
        multiply(B, B, A, n);
        k /= 2;
    }
}

int main(){
    float C[MAX][MAX];
    float A[MAX][MAX];
    int n;
    int cur;
    int k;
    scanf("%i", &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++ ){
            scanf("%i", &cur);
            A[i][j] = cur;
            if (i == j) C[i][j] = 1;
            else C[i][j] = 0;
        }
    }
    scanf("%i", &k);

    power(A, C, n, k);
    for (int i = 0; i < n; i++ ){
        for (int j = 0; j < n; j++ ){
            printf("%i ", (int)C[i][j]);
        }
        printf("\n");
    }


}