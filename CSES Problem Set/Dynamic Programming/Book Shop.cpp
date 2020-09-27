#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
typedef int lld;

const lld N = 200043;
const lld MOD = 1000000007;

lld add(lld x, lld y)
{
    x =((x%MOD)+(y%MOD))%MOD;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

lld mul(lld x, lld y)
{
    return ((x%MOD)*(y%MOD))% MOD;
}

lld binpow(lld x, lld y)
{
    lld z = 1;
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

lld inv(lld x)
{
    return binpow(x, MOD - 2);
}

lld divide(lld x, lld y)
{
    return mul(x, inv(y));
}

// Combinations

/*
lld fact[N];

void precalc()
{
    fact[0] = 1;
    for(lld i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
}

lld C(lld n, lld k)
{   if(k>n)
        return 0;
    return divide(fact[n], mul(fact[k], fact[n - k]));
}
*/

//Segment Tree

/*
// lld ar[100],stree[500],ltree[500]; Define these
// si=segment index
// ss=segment start
// se=segment end
// qs=query start
// qe=query end
// qi=query index
// update in real array before calling update function

void build(lld si,lld ss,lld se)
{
    if(ss==se)
        stree[si]=ar[ss];
    else
    {
        lld mid=ss+(se-ss)/2;
        build(2*si,ss,mid);
        build(2*si+1,mid+1,se);
        stree[si]=min(stree[2*si],stree[2*si+1]);
    }
}
lld query(lld si,lld ss,lld se,lld qs,lld qe)
{
    if(qs>se || qe<ss)
        return LLONG_MAX;
    if(ss>=qs && se<=qe)
        return stree[si];
    lld mid=ss+(se-ss)/2;
    lld l=query(2*si,ss,mid,qs,qe);
    lld r=query(2*si+1,mid+1,se,qs,qe);
    return min(l,r);
}
void update(lld si,lld ss,lld se,lld qi)
{
    if(ss==se)
        stree[si]=ar[qi];
    else
    {
        lld mid=ss+(se-ss)/2;
        if(qi<=mid)
            update(2*si,ss,mid,qi);
        else
            update(2*si+1,mid+1,se,qi);
        stree[si]=min(stree[2*si],stree[2*si+1]);
    }
}

// Range Sum Query
lld lazy_query(lld si,lld ss,lld se,lld qs,lld qe)
{
    if(ltree[si]!=0)
    {
        lld dx=ltree[si];
        ltree[si]=0;
        stree[si]+=dx*(se-ss+1);
        if(ss!=se)
            ltree[2*si]+=dx,ltree[2*si+1]+=dx;
    }
    if(qs>se || qe<ss)
        return 0;
    if(ss>=qs && se<=qe)
        return stree[si];
    lld mid=ss+(se-ss)/2;
    lld l=lazy_query(2*si,ss,mid,qs,qe);
    lld r=lazy_query(2*si+1,mid+1,se,qs,qe);
    return l+r;
}
void lazy_update(lld si,lld ss,lld se,lld qs,lld qe,lld val)
{
    if(ltree[si]!=0)
    {
        lld dx=ltree[si];
        ltree[si]=0;
        stree[si]+=dx*(se-ss+1);
        if(ss!=se)
            ltree[2*si]+=dx,ltree[2*si+1]+=dx;
    }
    if(qs>se || qe<ss)
        return;
    if(ss>=qs && se<=qe)
    {
        lld dx=val*(se-ss+1);
        stree[si]+=dx;
        if(se!=ss)
        ltree[2*si]+=val,ltree[2*si+1]+=val;
        return;
    }
    lld mid=ss+(se-ss)/2;
    lazy_update(2*si,ss,mid,qs,qe,val);
    lazy_update(2*si+1,mid+1,se,qs,qe,val);
    stree[si]=stree[2*si]+stree[2*si+1];
}
*/
lld n,x;
vector<vector<lld>>dp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t,i,j;
    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>n>>x;
        lld ar[n+1]={0};
        lld br[n+1]={0};
        dp.resize(n+1,vector<lld>(x+1,0));
        for(i=1;i<=n;i++)
            cin>>ar[i];
        for(i=1;i<=n;i++)
            cin>>br[i];
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=x;j++)
            {dp[i][j]=dp[i-1][j];
                lld l=j-ar[i];
                if(l>=0)
                    dp[i][j]=max(dp[i][j],dp[i-1][l]+br[i]);
            }
        }
        cout<<dp[n][x]<<endl;

    }
}



