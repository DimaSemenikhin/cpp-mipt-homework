#include <stdio.h>
#include <math.h>
#define eps 0.0000000001

int solve_quadratic(double a, double b, double c, double* px1, double* px2){

    if (fabs(a) < eps){
        if (fabs(b) < eps){
            return 0;
        }
        *px1 = -c / b;
        return 1;
    }
    double D = b * b - 4 * a * c;
    if (fabs(D) < eps){
        *px1 = -b / (2 * a);
        return 1;
    }
    if (D < -eps){
        return 0;
    }
    *px1 = (-b + sqrt(D)) / (2 * a);
    *px2 = (-b - sqrt(D)) / (2 * a);
    return 2;
}

int main(){
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double x1 = 0;
    double x2 = 0;
    double* px1 = &x1;
    double* px2 = &x2;
    solve_quadratic(a, b, c, px1, px2);
    printf("x1 = %lf, x2 = %lf\n", *px1, *px2);
}