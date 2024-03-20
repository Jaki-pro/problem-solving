#include<bits/stdc++.h>
using namespace std;
#define ll              long long int
const int N = 1e6;
int parent[N+2][21];
vector<int> graph[N+3];
map<pair<int, int>, int> mp;
void dfs(int u, int par)
{
    parent[u][0] = par;
    for(auto c:graph[u])
    {
        if(c==par) continue;
        dfs(c, u);
    }
}
void solve()
{
    ll n, m, a, b, cnt=0, mx=0, mn = INT_MAX, sum=0;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int u, v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(parent, -1, sizeof(parent));
    dfs(1, -1);
    for(int i=1; i<=20; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(parent[j][i-1]!=-1)
            {
                parent[j][i] = parent[parent[j][i-1]][i-1];
            }
        }
    }
    cin>>m;
    while(m--)
    {
        int u, k;
        cin>>u>>k;
        for(int i=20; i>=0; i--)
        {
            if( (1<<i)&k )
            {
                if(parent[u][i] == -1) {u=-1; break;}
                u = parent[u][i];
            }
        }
        cout<<u<<endl;
    }
}
int main()
{
    int t=1;
    solve();
    return 0;
}
