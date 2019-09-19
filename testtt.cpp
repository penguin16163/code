#include <iostream>
#define maxn 200005
using namespace std;
int n,k,p;
int color,price;
int last[maxn];
int sum[maxn];
int cnt[maxn];
int ans = 0;
int now;
int main(){
    cin >> n >> k >> p;
    for (int i=1;i<=n;i++){
        cin >> color >> price;
        if (price <= p)
            now = i;
        if (now >= last[color])
            sum[color] = cnt[color];
        last[color] = i;
        ans += sum[color];
        cnt[color]++;
    }
    cout << ans << endl;
    return 0;
}
