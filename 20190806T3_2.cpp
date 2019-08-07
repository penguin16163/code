#include<bits/stdc++.h>
#define Maxn 10005
#define rp(i,j,n) for(register int i=j;i<=n;++i)
using namespace std;
char a[Maxn];
int n,cnt;
long long dp[21][Maxn][2][2];
int link[21];
long long L,R,K;
struct node {
	int fail,num;
	int _34[34];
} ter[Maxn];
queue<int> q;
void build() {
	int u(0);
	for(register int i=1; a[i]; ++i) {
		int _19=a[i]-'0';
		if(!ter[u]._34[_19]) ter[u]._34[_19]=++cnt;
		u=ter[u]._34[_19];
	}
	ter[u].num=1;
}
void get_fail() {
	rp(i,0,9) if(ter[0]._34[i])q.push(ter[0]._34[i]);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		rp(i,0,9) {
			int v=ter[u]._34[i];
			if(v) {
				ter[v].fail=ter[ter[u].fail]._34[i],q.push(v);
				ter[ter[u]._34[i]].num|=ter[ter[ter[u].fail]._34[i]].num;
			} else ter[u]._34[i]=ter[ter[u].fail]._34[i];
		}
	}
}
long long dddp(long long x) {
	if(!x) return 0;
	memset(dp,0,sizeof(dp));
	dp[0][0][0][1]=1;
	long long wa,sr;
	wa=sr=1;
	while(sr<=x/10) ++wa,sr=(sr<<1)+(sr<<3);
	for(register long long i=wa,cpp=x; i!=0; cpp/=10,--i) link[i]=cpp%10;
	rp(i,0,wa-1) rp(t,0,cnt) rp(k1,0,1) rp(k2,0,1) {
		long long ccf=dp[i][t][k1][k2];
		if(ccf) {
			rp(to,0,9) {
				if(k2&&to==link[i+1]) {
					dp[i+1][ter[t]._34[to]][k1||ter[ter[t]._34[to]].num][1]+=ccf;
					break;
				} else dp[i+1][ter[t]._34[to]][k1||ter[ter[t]._34[to]].num][0]+=ccf;
			}
		}
	}
	long long ans=0;
	rp(i,0,cnt) ans+=dp[wa][i][1][0]+dp[wa][i][1][1];
	return ans;
}
int main() {
	cin>>L>>R>>K>>n;
	rp(i,1,n) {
		cin>>a+1;
		if(strlen(a+1)<=19)build();
	}
	get_fail();
	long long ans=-1,s=dddp(L-1);
	while(L<=R) {
		long long mid=L+R>>1;
		if(dddp(mid)-s>=K) ans=mid,R=mid-1;
		else L=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}
