#include <stdio.h>

float yearfrac(int year, int day){
    int days;
    if (year % 4 == 0) days = 366;
    else days = 365;
    return (float)day/days;
}

int main(){
    int year;
    int day;
    scanf("%i %i", &year, &day);
    printf("%f", yearfrac(year, day));
}