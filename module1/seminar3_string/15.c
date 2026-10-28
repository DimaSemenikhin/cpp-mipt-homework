#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if (argc != 4){
        printf("Error: Wrong number of arguments!\n");
        return 0;
    }
    int start = -1;
    int end = -1;
    char a = '&';
    char b = '&';
    FILE* fp1 = fopen(argv[1], "r");
    FILE* fp2 = fopen(argv[2], "w");
    sscanf(argv[3], "%i%c%i%c", &start, &a, &end, &b);
    
    if ((a != '&' && a != ':') || (a == ':' && end == -1) || (b != '&' )) {
        printf("Error: Wrong lines format!");
    }
    char cur;
    int count = 1;
    
    while (count != start){
        cur = fgetc(fp1);
        if (cur == -1) return 0;
        if (cur == '\n') count += 1;
    }
    int count_end = count;
    if (end != -1){
        while (count_end <= end){
            cur = fgetc(fp1);
            if (cur == -1) return 0;
            fputc(cur, fp2);
            if (cur == '\n') count_end += 1;
        }
    }
    else {
        while (count_end <= count){
            cur = fgetc(fp1);
            if (cur == -1) return 0;
            fputc(cur, fp2);
            if (cur == '\n') count_end += 1; 
        }
    }
    fclose(fp1);
    fclose(fp2);

}