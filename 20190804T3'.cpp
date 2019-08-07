#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mo=1000000007;
int r[5005],ans[300100];
int n, m, maxx, sum;
long long s, inv, ANS, rest;
inline long long fast_power(long long x, long long p) 
{
    long long s=1,t=x%mo;
    while (p) {
        if (p & 1) (s*=t)%=mo;
        (t*=t)%=mo;
        p>>=1;
    }
    return s%mo;
}
signed main()
{
    scanf("%lld %lld", &n, &m);
    for (register int i=1; i<=n; ++i) {
        scanf("%lld", &r[i]);
        maxx=max(maxx, r[i]);
        sum+=r[i];
    }
    s=1;
    for (register int i=1; i<=n; ++i) (s*=i)%=mo;
    inv=fast_power(s,mo-2);
    for (register int i=1; i<=2*maxx; ++i) {
        rest=m-2*sum+i;
        if (rest>=0) {
            if (rest==0) {
                ans[i]=1;
            }
            else {
                if (i==1) {
                    ans[i]=1;
                    for (register int j=1; j<=n; ++j) 
                        (ans[i]*=(rest+j))%=mo;
                    (ans[i]*=inv)%=mo;
                }
                else ans[i]=ans[i-1]*(rest+n)%mo*fast_power(rest, mo-2)%mo;
            }
        }
    }
    for (register int i=1; i<=n; ++i)
        for (register int j=i+1; j<=n; ++j)
            if (m-(2*sum-r[i]-r[j])>=0) (ANS+=2*ans[r[i]+r[j]]%mo)%=mo;
    s=s*fast_power(n, mo-2)%mo*fast_power(n-1,mo-2)%mo;
    printf("%lld\n",  ANS*s%mo);
}