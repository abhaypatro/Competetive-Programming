#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;

const lld N = 200043;
const lld MOD = 1000000007;

const lld MAXN=200005; // size of array
const lld K=21; // logarithm base 2 of MAXN
lld st[MAXN][K + 1];// sparse table
lld logarithm[MAXN+1];

lld func(lld a,lld b) // any idempotent function
{
    return min(a,b);
}
void init(lld ar[],lld A)
{
    logarithm[1] = 0;
    for (lld i = 2; i <= MAXN; i++)
        logarithm[i] = logarithm[i/2] + 1;

    for (lld i = 0; i < A; i++)
    st[i][0] = ar[i];

    for (lld j = 1; j <= K; j++)
        for (lld i = 0; i + (1 << j) <= A; i++)
            st[i][j] = func(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}
lld query(lld L,lld R)
{
    lld j = logarithm[R - L + 1];
    lld ans = func(st[L][j], st[R - (1 << j) + 1][j]);
    return ans;
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
        lld n;
        cin>>n;
        lld ar[n];
        for(i=0;i<n;i++)
            cin>>ar[i];
        init(ar,n);
        lld q;
        cin>>q;
        while(q--)
        {
            lld l,r;
            cin>>l>>r;
            cout<<query(l,r)<<endl;
        }
    }
}


