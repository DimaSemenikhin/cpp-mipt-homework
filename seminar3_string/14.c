#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char encrypt(char str, int k){
    
    if ((str >= 'A') && (str <= 'Z')){
        str = (str - 'A' + k) % 26 + 'A';
    }
    if ((str >= 'a') && (str <= 'z')){
        str = (str - 'a' + k) % 26 + 'a';
    }
    return str;
        

}

int main(int argc, char* argv[]){
    FILE* fp1 = fopen(argv[1], "r");
    FILE* fp2 = fopen(argv[2], "w");
    int k = atoi(argv[3]);
    int a;
    while (1){
        a = fgetc(fp1);
        if (a != -1){
            fprintf(fp2, "%c", encrypt((char)a, k));
        }
        else break;
    }
    fclose(fp1);
    fclose(fp2);

    
}