#include<bits/stdc++.h>
using namespace std;
int s[100005][2], sum[100005][2], color[100005], number[100005];
int n, m, ans;
int main()
{
    scanf ("%d %d",&n, &m);
    for (int i=1;i<=n;i++){
        scanf("%d", &number[i]);
    }
    for (int i=1;i<=n;i++){
        scanf ("%d", &color[i]);
        s[color[i]][i%2]++;
        sum[color[i]][i%2]=(sum[color[i]][i%2]+number[i])%10007;
    }
    for (int i=1;i<=n;i++){
        ans=(ans+i*((s[color[i]][i%2]-2)*number[i]%10007+sum[color[i]][i%2]))%10007;
    }
    printf ("%d\n", ans);
    return 0;
}