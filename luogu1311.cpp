#include<bits/stdc++.h> 
using namespace std;
int n, k, p, c, pri, ans, t;
int l[30], sum[30], cnt[30];
int main()
{
    scanf("%d%d%d", &n, &k, &p);
    for (int i=1; i<=n; ++i) {
		scanf("%d%d", &c, &pri);
        if (pri<=p) t=i;
        if (t>=l[c]) sum[c]=cnt[c];
        l[c]=i;
        ans+=sum[c];
        cnt[c]++;
    }
    printf("%d\n", ans);
    return 0;
}
