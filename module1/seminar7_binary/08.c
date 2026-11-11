#include <stdio.h>
#include <stdlib.h>

struct color
{
    unsigned char r, g, b;
};
typedef struct color Color;


int main()
{
    int width = 600, height = 400;
    Color* data = (Color*)malloc(sizeof(Color) * width * height);
    
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            if ((i - width/2) * (i - width/2) + (j - height/2) * (j - height/2) <= (height * 3/10) * (height * 3/10))
            {
                data[i + width * j].r = 190;
                data[i + width * j].g = 0;
                data[i + width * j].b = 41;
            }
            else
            {
                data[i + width * j].r = 255;
                data[i + width * j].g = 255;
                data[i + width * j].b = 255;
            }
        }
    }

    FILE* file = fopen("flag.ppm", "wb");
    fprintf(file, "P6\n%i %i\n255\n", width, height);
    fwrite(data, sizeof(Color), height * width, file);
    fclose(file);
    
    free(data);
}