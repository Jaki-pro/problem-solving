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
    for(int i=0; i<n-1; i++)
    {
        int u, v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(parent, -1, sizeof(parent));
    memset(dist, 0, sizeof(dist));
    dfs(1, -1); // calculate First parent for all node
    for(int i=1; i<=20; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(parent[j][i-1]!=-1)
            {
                parent[j][i] = parent[parent[j][i-1]][i-1]; // Parse table
            }
        }
    }
    for(int i=1; i<=20; i++) cout<<dist[i]<<' ';
    cout<<endl;
    cin>>m;
    while(m--)
    {
        int u, v; // Kth parent of node u
        cin>>u>>v;
        if(dist[u]<dist[v]) swap(u, v); // Always consider the level of u is bigger than that of v
        int dif = dist[u]-dist[v];
        u = kthParent(u, dif); // Making levels equal.. Because LCA will work from same level
        int lca = LCA(u, v);
        cout<<lca<<endl;
    }
}
/*
20 // number of nodes
1 2 2 4 2 5 5 8 8 12 5 9 9 13 13 17 17 20 13 18 9 14 //Edges
1 3 3 7 7 11 7 10 10 15 15 19 10 16 3 6 // Edges
5 // number of query
1 3 // u, v
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
