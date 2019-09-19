#include<bits/stdc++.h>
#define ll long long
#define maxN 100005
using namespace std;
vector <int> bottem;
vector <int> top;
ll x[maxN], y[maxN], z[maxN];
ll r, h;
int f[maxN];
int n, T;
bool flag;
inline bool dist(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2) 
{	
    return 4*r*r>=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
}
inline void initialize()
{
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	memset(z,0,sizeof(z));
	for (int i=1; i<=n; ++i) f[i]=i;
	bottem.clear();
	top.clear();
}
inline int find(int x) {
	if (f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
int main()
{
	scanf("%d", &T);
	while (T--) {
    	scanf("%d %lld %lld", &n, &h, &r);
    	initialize();
		for (int i=1; i<=n; ++i) {
			scanf("%lld %lld %lld", &x[i], &y[i], &z[i]);
			if (z[i]+r>=h) top.push_back(i);
			if (z[i]-r<=0) bottem.push_back(i);
			for (int j=1; j<i; ++j) {
				if (dist(x[i],y[i],z[i],x[j],y[j],z[j])) {
					int a=find(i);
					int b=find(j);
					if (a!=b) f[a]=b;
				}
			}
		}
		flag=0;
		for (int i=1; i<=bottem.size(); ++i) {
			for (int j=1; j<=top.size(); ++j) {
				if (find(bottem[i-1])==find(top[j-1])) {
					flag=1;
					break;
				}
			}
			if (flag) break;
		} 
		if (flag) puts("Yes");
		else puts("No");
	}
	return 0;
 } 
