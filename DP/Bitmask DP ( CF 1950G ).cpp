///https://codeforces.com/contest/1950/problem/G
#include<bits/stdc++.h>
using namespace std;
#define FIO            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll              long long int
const int N = 1e5+3;
int dp[N+2][20][2];
bool ae[20][20], be[20][20];
int n, ans;
ll fun(ll mask, ll last, ll used)
{
    if(dp[mask][last][used]!=-1) { return dp[mask][last][used]; }
    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        if(mask & (1<<i)) continue;
        if(!used) ans = max(ans, 1+fun((1<<i), i, 1));
        else if(ae[i][last]==1 || be[i][last]==1) ans = max(ans, 1+fun(mask|(1<<i), i, 1));
    }
    return dp[mask][last][used]=ans;
}
void solve(int tc)
{
    ll cnt=0, mx=0, mn = INT_MAX, sum=0;
    cin>>n;
    vector<string> a, b;
    for(int i=0; i<n; i++)
    {
        string s, ss;cin>>s>>ss;
        a.push_back(s);
        b.push_back(ss);
    }
    for(ll i=0;i<(1LL<<n);i++){
        for(ll j=0;j<n;j++){
            for(ll k=0;k<2;k++)
                dp[i][j][k]=-1;
        }
    }
    memset(ae, false, sizeof(ae));
    memset(be, false, sizeof(be));
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            if(a[i]==a[j]) ae[i][j]=true;
            if(b[i]==b[j]) be[i][j]=true;
        }
    }
    cout<<n-fun(0, 0, 0) <<endl;
}

int main()
{
    FIO
    int t=1;
    cin>>t;
    for(int i=1; i<=t; i++) solve(i);
    return 0;
}
