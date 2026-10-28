#include <stdio.h>
#include <math.h>

#define step 0.01
#define eps 0.0000000001

double f(double x, double t){
    return pow(t, (x - 1)) * exp(-t);
}

double gamma(double x){
    double area = 1;
    double t = 0;
    double res = 0;
    while (true){
        if ((res > 0) && (area <= eps)) break;
        area = (f(x, t) + f(x, t + step)) * step / 2;
        if (area >= eps) res += area;
        t += step;
    }
    return res;
}

int main(){
    double x;
    scanf("%lf", &x );
    printf("%lf\n", gamma(x));
}