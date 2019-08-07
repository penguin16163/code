#include<cstdio>
double n;
int main()
{
    scanf("%lf", &n);
    printf("%.10lf",n*(n+1)/2/(2*n-1));
}
