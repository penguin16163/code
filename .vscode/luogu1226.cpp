#include<bits/stdc++.h>
using namespace std;
long long b,p,k;
inline long long quick_power(long long b, long long p, long long mod)
{
    long long base=b, ans=1;
    while (p) {
        if (p & 1) {
            ans=ans*base%mod;
        }
        base=base*base%mod;
        p>>=1;
    }
    return ans%mod;
}
int main()
{
    scanf("%lld %lld %lld", &b, &p, &k);
    printf("%lld^%lld mod %lld=%lld", b, p, k, quick_power(b,p,k));
}