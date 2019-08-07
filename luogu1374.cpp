#include<bits/stdc++.h>
using namespace std;
int ans, n, S[50];
bool find(int step, int now)
{
    if (step>ans || now<=0 || now<<(ans-step)<n) return 0;
    if (now==n || now<<(ans-step)==n) return 1;
    S[step]=now;
    for(int i=0; i<=step; i++){
        if (find(step+1, now+S[i])) return 1;
        if (find(step+1, now-S[i])) return 1;
    }
    return 0;
}
int main(){
    while(~scanf("%d",&n)) {
    	ans=0;
    	while (!find(0, 1)) ++ans;
    printf("%d\n",ans);
    }
}
