#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;
vector<lld>adj[1000];
vector<lld>trp[1000];
lld visited1[1000]={0};
lld visited2[1000]={0};
vector<lld>ar;
lld j=0;
stack<lld>s;
void dfs(lld x)
{
    lld i;
    visited1[x]=1;
    for(i=0;i<adj[x].size();i++)
    {
        if(visited1[adj[x][i]]==0)
            dfs(adj[x][i]);
    }
    s.push(x);
}
void dfs2(lld x)
{
    lld i;
    visited2[x]=1;
    ar.push_back(x);
    for(i=0;i<trp[x].size();i++)
    {
        if(visited2[trp[x][i]]==0)
            dfs2(trp[x][i]);
    }

}
void ssc()
{
    lld ctr=0;
    while(!s.empty())
    {
        lld x =s.top();
        s.pop();
        if(visited2[x]==0)
           {
               dfs2(x);
               ctr++;
        lld i;
        for(i=j;i<ar.size();i++)
        {
           cout<<ar[i]<<" ";
        }
        j=ar.size();
        cout<<endl;
           }
    }
    cout<<ctr<<endl;
}
int main()
{

    lld n;
    cin>>n;
    lld m;
    cin>>m;
    lld i;
    for(i=0;i<m;i++)
    {
        lld a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        trp[b].push_back(a);
    }
    for(i=0;i<n;i++)
    {
       if(visited1[i]==0)
        dfs(i);
    }
    ssc();


}
