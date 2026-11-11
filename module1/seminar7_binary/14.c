#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct color
{
    unsigned char r, g, b;
};
typedef struct color Color;

void blur(Color* data, int width, int height){
    Color* new_data = (Color*)malloc(sizeof(Color) * width * height);
    if (new_data == NULL) {
        printf("Memory allocation failed in blur!\n");
        return;
    }

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            int sum_r = 0, sum_g = 0, sum_b = 0;
            int count = 0;
            for (int dj = -1; dj <= 1; dj++) {
                for (int di = -1; di <= 1; di++) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < width && nj >= 0 && nj < height) {
                        int idx = nj * width + ni;
                        sum_r += data[idx].r;
                        sum_g += data[idx].g;
                        sum_b += data[idx].b;
                        count++;
                    }
                }
            }
            int out_idx = j * width + i;
            new_data[out_idx].r = sum_r / count;
            new_data[out_idx].g = sum_g / count;
            new_data[out_idx].b = sum_b / count;
        }
    }

    memcpy(data, new_data, sizeof(Color) * width * height);
    
    free(new_data);

}

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        printf("Error!\n");
        printf("To use this program: ./brightness <ppm image> <brightness change>\n");
        exit(1);
    }

    

    FILE* inputfile = fopen(argv[1], "rb");
    if (inputfile == 0)
    {
        printf("Can't open the file: %s\n", argv[1]);
        exit(1);
    }
    int width, height;
    fscanf(inputfile, "P6\n%d %d\n255\n", &width, &height);
    Color* data = (Color*)malloc(sizeof(Color) * width * height);
    fread(data, sizeof(Color), height * width, inputfile);
    fclose(inputfile);
    int n = atoi(argv[2]);

    for (int i = 0; i < n; i++){
        blur(data, width, height);
    }


    FILE* outputfile = fopen("14.ppm", "wb");
    fprintf(outputfile, "P6\n%d %d\n255\n", width, height);
    fwrite(data, sizeof(Color), height * width, outputfile);
    fclose(outputfile);
    
    
    free(data);
}