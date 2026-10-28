#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct movie
{
    char title[50];
    float rating;
};
typedef struct movie Movie;

int compare(const void* a, const void* b){
    Movie* A = (Movie*)a;
    Movie* B = (Movie*)b;
    if ((*A).rating >= (*B).rating) return -1;
    if ((*A).rating < (*B).rating) return 1;
}

int main(){
    int n;
    scanf("%i", &n);
    Movie array[100];
    getchar();
    char temp;
    float rate = 0;
    int k;
    
    
    for (int i = 0; i < n; i++){
            scanf("%[^:]", array[i].title);   
            scanf("%c", &temp);      
            scanf("%i", &k);
            for (int j = 0; j < k; j++){
                scanf("%i", &temp);
                rate += temp;
            }
            rate /= k;
            scanf("%c", &temp);
            array[i].rating = rate;
            rate = 0;   
    }
    qsort(array, n, sizeof(Movie), compare);
    for (int i = 0; i < n; i++) {
        printf("%s, %f\n", array[i].title, array[i].rating);
    }

}