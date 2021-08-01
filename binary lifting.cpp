#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;

const lld N = 200043;
const lld MOD = 1000000007;

lld level[200005]={0}; // level of node
vector<lld>v[200005]; // adjacency list of tree
lld parent[200005]; // Parent table
lld LCA[200005][32]; // LCA array
lld par[200005];
lld n; // number of nodes
void dfs(lld child , lld parent)
{
    par[child]=parent;
    LCA[child][0]=parent;
    for(lld x: v[child])
    {
        if(x==parent)
            continue;
        level[x]=level[child]+1;
        dfs(x,child);
    }
}
void init()
{
    memset(LCA,-1,sizeof(LCA));
    dfs(1,-1);
    lld i,j;
    for(j=1;j<=30;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(LCA[i][j-1]!=-1)
            {
                lld x=LCA[i][j-1];
                LCA[i][j]=LCA[x][j-1];
            }
        }
    }
}
lld fun(lld a,lld b)
{
    lld i,j;
    if(level[a]<level[b])
        swap(a,b);
    lld d=level[a]-level[b];
    while(d>0)
    {
        lld x=log2(d);
        d-=(1<<x);
        a=LCA[a][x];
    }
    if(a==b)
        return a;
    for(i=30;i>=0;i--)
    {
        if(LCA[a][i]!=-1 && (LCA[a][i]!=LCA[b][i]))
            a=LCA[a][i],b=LCA[b][i];
    }
    return par[a];
}
lld dist(lld a,lld b)
{
    return level[a]+level[b]-2*level[fun(a,b)];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t,i,j;
    t=1;
    //cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<n;i++)
        {
            lld a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        init();
        lld q;
        cin>>q;
        while(q--)
        {
            lld a,b;
            cin>>a>>b;
            cout<<fun(a,b)<<endl;
        }
    }
}


