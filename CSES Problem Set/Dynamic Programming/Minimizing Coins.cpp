#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;

const lld N = 200043;
const lld MOD = 1000000007;

lld add(lld x, lld y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

lld mul(lld x, lld y)
{
    return (x * 1ll * y) % MOD;
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
{
    return divide(fact[n], mul(fact[k], fact[n - k]));
}
*/
lld n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t,i,j;
    t=1;
    while(t--)
    {
        lld x;
        cin>>n>>x;
        lld ar[n];
        for(i=0;i<n;i++)
            cin>>ar[i];

        lld dp[x+1];
        for(i=0;i<=x;i++)
            dp[i]=100000000000;
        dp[0]=0;
        for(i=0;i<n;i++)
        {
            for(j=ar[i];j<=x;j++)
                if(j>=ar[i] && dp[j-ar[i]]!=100000000000)
                dp[j]=min(dp[j],dp[j-ar[i]]+1);
        }
        if(dp[x]!=100000000000)
        cout<<dp[x]<<endl;
        else
            cout<<-1<<endl;
    }
}
