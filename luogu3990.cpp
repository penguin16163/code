#include<bits/stdc++.h>
using namespace std;
inline void quick
int main()
{
    scanf("%d %d", &n, &k);
    for (int i=1; i<=n; ++i) 
        for (int j=1; j<=n; ++j) 
            scanf("%d", &a[i][j]);
    quick_power();
}