#include <stdio.h>
#include <stdlib.h>
#include <math.h>



struct color
{
    unsigned char r, g, b;
};
typedef struct color Color;

const Color White = {255, 255, 255};
const Color Black = {0, 0, 0};


// Функция, которая рисует линию от (x0, y0) до (x1, y1) цвета c на холте data
void draw_line(Color* data, int width, int height, int x0, int y0, int x1, int y1, Color c)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int ysign = y1 > y0 ? 1 : -1;
    int xsign = x1 > x0 ? 1 : -1;
    int error = (dx > dy ? dx : -dy)/2;

    if (dx >= dy)
    {
        int y = y0;
        for (int x = x0 ; x != x1; x += xsign)
        {
            data[x + width * y] = c;
            error += dy;
            if (error >= dx)
            {
                y += ysign;
                error -= dx;
            }
        }
    }
    else
    {
        int x = x0;
        for (int y = y0 ; y != y1; y += ysign)
        {
            data[x + width * y] = c;
            error += dx;
            if (error >= dy)
            {
                x += xsign;
                error -= dy;
            }
        }
    }

}

const float Angle = 20.0 / 180 * 3.1415;
void draw_node(Color* data, int width, int height, int x, int y, float angle, float length){
    float angle_left = angle - Angle;
    float angle_right = angle + Angle;
    float cur_length = 2.0 * length / 3.0;
    int x_left = round((float)x + cur_length * sin(angle_left));
    int y_left = round((float)y - cur_length * cos(angle_left));
    int x_right = round((float)x + cur_length * sin(angle_right));
    int y_right = round((float)y - cur_length * cos(angle_right));
    if (((x_left == x) && (y_left == y)) || ((x_right == x) && (y_right == y)) || (x_left < 0) || (x_right > width) || (y_left > height) || (y_right > height)){
        return;
    }
    draw_line(data, width, height, x, y, x_left, y_left, Black);
    draw_line(data, width, height, x, y, x_right, y_right, Black);
    draw_node(data, width, height, x_left, y_left, angle_left, cur_length);
    draw_node(data, width, height, x_right, y_right, angle_right, cur_length);
}



int main()
{   


    int width = 500, height = 500;
    Color* data = (Color*)malloc(sizeof(Color) * width * height);

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            data[i + width * j] = White;
        }
    }
    draw_node(data, width, height, width / 2, height, 0, 200);
    
    FILE* file = fopen("fractal.ppm", "wb");
    fprintf(file, "P6\n%d %d\n255\n", width, height);
    fwrite(data, sizeof(Color), height * width, file);
    fclose(file);
    
    free(data);
}