#include<bits/stdc++.h>
using namespace std;
int a[7];
int main()
{
    for (int i=2; i<=6; ++i) a[i]=i+1;
    int m;
    do {
        m=2;;
        for (int i=3; i<=6; ++i) if (a[m]>a[i]) m=i;
        a[m]+=m;
        m=1;
        for (int i=2; i<=5; ++i) {
            a[m]+=m;
            for (int j=i+1; j<=6; ++j) {
                if (a[i]<a[j]) m=0;
            }
        }
    } while (m==0);
    printf("%d", a[2]);
}