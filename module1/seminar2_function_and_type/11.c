#include <stdio.h>
#define MAX 100

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

int main(){
    int n;
    float A[MAX][MAX];
    float B[MAX][MAX];
    float C[MAX][MAX];
    int cur;
    scanf("%i", &n);

    for (int i = 0; i < n; i++ ){
        for (int j = 0; j < n; j++ ){
            scanf("%i", &cur);
            A[i][j] = cur;
        }
    }
    
    scanf("%i", &n);
    for (int i = 0; i < n; i++ ){
        for (int j = 0; j < n; j++ ){
            scanf("%i", &cur);
            B[i][j] = cur;
        }
    }

    multiply(A, B, C, n);


    for (int i = 0; i < n; i++ ){
        for (int j = 0; j < n; j++ ){
            printf("%i ", (int)C[i][j]);
        }
        printf("\n");
    }

}
