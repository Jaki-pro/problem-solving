#include<bits/stdc++.h>
using namespace std;
#define ll              long long int
const int N = 1e6;
int parent[N+2][21];
int dist[N+3], ans[N+2];
vector<int> graph[N+3];

void dfs(int u, int par)
{
    parent[u][0] = par;
    for(auto c:graph[u])
    {
        if(c==par) continue;
        dist[c]=dist[u]+1;
        dfs(c, u);
    }
}
void dfs2(int u, int par)
{
    for(auto c:graph[u])
    {
        if(c==par) continue;
        dfs2(c, u);

    }
    if(par!=-1) ans[par] += ans[u];
}
int kthParent(int u, int k)
{
    for(int i=20; i>=0; i--)
    {
        if( (1<<i)&k )
        {
            if(parent[u][i] == -1) {return -1;}
            u = parent[u][i];
        }
    }
    return u;
}
int LCA(int u, int v)
{
    if(u==v) return u;
    int lca;
    for(int i=20; i>=0; i--)
    {
        if( parent[u][i]==-1 ) continue;
        else
        {
            if(parent[u][i] != parent[v][i]) {u = parent[u][i], v=parent[v][i];}

        }
    }
    return parent[u][0];
}
void solve()
{
    ll n, m, a, b, cnt=0, mx=0, mn = INT_MAX, sum=0;
    cin>>n;
    cin>>m;
    for(int i=0; i<n-1; i++)
    {
        int u, v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(parent, -1, sizeof(parent));
    memset(dist, 0, sizeof(dist));
    memset(ans, 0, sizeof(ans));
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
    while(m--)
    {
        int u, v;
        cin>>u>>v;
        ans[u]++, ans[v]++;
        if(dist[u]<dist[v]) swap(u, v);
        int dif = dist[u]-dist[v];
        u = kthParent(u, dif);
        int lca = LCA(u, v);
        ans[lca]--;
        if(parent[lca][0]) ans[parent[lca][0]]--;
    }
    dfs2(1, -1);
    for(int i=1; i<=n; i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<"\n";

}
/*
20
1 2 2 4 2 5 5 8 8 12 5 9 9 13 13 17 17 20 13 18 9 14
1 3 3 7 7 11 7 10 10 15 15 19 10 16 3 6
5
1 3
1 1
19 10
9 9
9 14
*/
int main()
{
    int t=1;
    solve();
    return 0;
}
