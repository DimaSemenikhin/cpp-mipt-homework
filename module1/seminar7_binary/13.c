#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// To compile:
// gcc -std=c99 -o brightness brightness.c

// To run:
// ./brightness images/emir.ppm -70

struct color
{
    unsigned char r, g, b;
};
typedef struct color Color;


int main(int argc, char** argv)
{
    // Смотрим аргументы командной строки
    if (argc != 2)
    {
        printf("Error!\n");
        printf("To use this program: ./brightness <ppm image> <brightness change>\n");
        exit(1);
    }

    

    // Считываем
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


    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            int red = data[i + width * j].r;
            int green = data[i + width * j].g;
            int blue = data[i + width * j].b;
            int r_new = round(0.393 * red + 0.769 * green + 0.189 * blue);
            int g_new = round(0.349 * red + 0.686 * green + 0.168 * blue);
            int b_new = round(0.272 * red + 0.534 * green + 0.131 * blue);
            data[i + width * j].r = r_new <= 255 ? r_new : 255;
            data[i + width * j].g = g_new <= 255 ? g_new : 255;
            data[i + width * j].b = b_new <= 255 ? b_new : 255; 
            
        }
    }


    // Записываем
    FILE* outputfile = fopen("13.ppm", "wb");
    fprintf(outputfile, "P6\n%d %d\n255\n", width, height);
    fwrite(data, sizeof(Color), height * width, outputfile);
    fclose(outputfile);
    
    
    free(data);
}