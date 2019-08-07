#include<bits/stdc++.h>
using namespace std;
long long m,n,l,r,mid;
long long xxr(long long x)
{
    long long ans=0;
    long long k=1;
    while (++k) {
    	long long num=1;
    	long long i=x;
    	while (i>0) {
    		if (num>=4) ans+=i;
            num++;
    		i/=k;
		}
		if(num<=4)return ans;
	}
}
int main(){
    scanf("%lld", &m);
    l=8,r=1e16+1;
    while (l<r) {
        mid=(l+r)>>1;
        if (xxr(mid)<m) l=mid+1;
        else r=mid;
    }
    if (xxr(l)==m) printf("%lld\n",l);
    else puts("-1");
    return 0;
}