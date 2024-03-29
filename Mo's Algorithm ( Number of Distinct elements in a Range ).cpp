/// Find number of Distinct elements in a range Using MO's Algorithm & SQRT Decomposition
#include<bits/stdc++.h>
using namespace std;
#define ll              long long int

const ll blck = 600; // Size of Block
struct query{
    ll r, l, in;
};
const ll N = 2e5+4;
query Q[N];
ll ans[N];
vector<ll> v(N);
vector<ll> mp(2e6,0);

/// MO's Sorting..If blocks are same then Sort according to R
/// Otherwise Sort accodring to blocks
bool comp(query q1, query q2)
{
    if((q1.l/blck)==(q2.l/blck))return q1.r<q2.r;
    return (q1.l/blck)<(q2.l/blck);
}

/// Have to clear mp, ans, v If multiple Test Cases are Available
void solve(int tc)
{
    ll n, cnt=0;
    cin>>n;
    for(int i=0; i<n; i++) cin>>v[i];

    int q;cin>>q; /// Number of Queries
    for(int i=0; i<q; i++)
    {
        int u, v; cin>>u>>v;
        Q[i].in=i, Q[i].l = u-1, Q[i].r = v-1; /// Storing query
    }
    sort(Q, Q+q, comp); /// Sort the Query known as MO's Sort

    int ML = 0, MR = -1; /// Left pointer and Right Pointer
    for(int i=0; i<q; i++)
    {
        int ind = Q[i].in,  L = Q[i].l, R = Q[i].r;
        while(ML<L)
        {
            mp[v[ML]]--;
            if(mp[v[ML]]==0) cnt--;
            ML++;
        }
        while(ML>L)
        {
            ML--;
            mp[v[ML]]++;
            if(mp[v[ML]]==1) cnt++;
        }
        while(MR<R)
        {
            MR++;
            mp[v[MR]]++;
            if(mp[v[MR]]==1) cnt++;
        }
        while(MR>R)
        {
            mp[v[MR]]--;
            if(mp[v[MR]]==0) cnt--;
            MR--;
        }
        ans[ind] = cnt;
    }
    for(int i=0; i<q; i++) cout<<ans[i]<<' '; cout<<endl;
}
int main()
{
    int t=1;
//    cin>>t;
    for(int i=1; i<=t; i++) solve(i);
    return 0;
}
