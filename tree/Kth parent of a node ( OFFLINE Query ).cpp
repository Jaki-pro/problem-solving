#include<bits/stdc++.h>
using namespace std;
#define ll              long long int
const int N = 1e6;
vector<int> path, graph[N+3], query[N+2];
map<pair<int, int>, int> mp;
void dfs(int u, int par)
{
    path.push_back(u);
    for(auto c:query[u]) // Node u er ekadhik parent ask korte pare
    {
        mp[{u, c}] = path[path.size()-c-1];
    }
    for(auto c:graph[u])
    {
        if(c==par) continue;
        dfs(c, u);
    }
    path.pop_back(); // Acting like a stack
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
    cin>>m;
    vector<pair<ll, ll>> query2(n+1);
    for(int i=0; i<m; i++)
    {
        int u, k; cin>>u>>k;
        query[u].push_back(k); // Same node er ekadhik K ber korte bolte pare
        query2[i] = {u, k}; // OFFLINE query SAVE
    }
    dfs(1, -1);
    for(int i=0; i<m;i++)
    {
        cout<<mp[query2[i]]<<endl;
    }
}
/*
20
// 19 Edges are...
1 2 2 4 2 5 5 8 5 9 8 12 9 13 13 17 17 20 13 18 9 14
1 3 3 6 3 7 7 10 10 15 15 19 10 16 7 11
5 // number of query
12 3 // node 12 er 3rd parent koto
9 3
20 5
15 3
15 4
*/
int main()
{
    int t=1;
    solve();
    return 0;
}
