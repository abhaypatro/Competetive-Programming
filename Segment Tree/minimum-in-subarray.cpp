
#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;
lld ar[100000];
lld tr[400000];
void build(lld s ,lld e , lld in)
{
    if(s==e)
    {
        tr[in]=ar[s];
        return;
    }
    else
    {
        lld mid=(s+e)/2;
        build(s,mid,2*in);
        build(mid+1,e,2*in+1);
        tr[in]=min(tr[2*in],tr[2*in+1]);
    }
}
void update(lld s, lld e, lld val , lld ind, lld in )
{
   if(s==e)
   {
       ar[s]=val;
       tr[in]=val;
       return;

   }
   else{
    lld mid=(s+e)/2;
    if(ind>mid)
    {
        update(mid+1,e,val,ind,2*in+1);
    }
    else
    {
        update(s,mid,val,ind,2*in);
    }
    tr[in]=min(tr[2*in],tr[2*in+1]);
   }
}
int query(lld s , lld e , lld l,lld r,lld in)
{
    if(s>r || e<l)
        return INT_MAX;
    else
        if(s>=l && e<=r)
        return tr[in];
    else
    {
        lld mid=(s+e)/2;
        lld ans1=query(s,mid,l,r,2*in);
        lld ans2=query(mid+1,e,l,r,2*in+1);
        return min(ans1,ans2);
    }
}
int main()
{
  lld n,t;
  cin>>n>>t;
  lld i;
  for(i=1;i<=n;i++)
  {
      cin>>ar[i];
  }
  build(1,n,1);
  // for(i=1;i<=n;i++)
  //   cout<<tr[i]<<" ";
  //   cout<<endl;
  //   update(0,n-1,10,2,1);
  // for(i=1;i<=n;i++)
  //   cout<<tr[i]<<" ";
  //   cout<<endl;
  //   cout<<query(0,n-1,2,4,1);
    while(t--)
    {
        lld a,b;
        char ch;
        cin>>ch>>a>>b;
        if(ch=='q')
            cout<<query(1,n,a,b,1)<<endl;
        else
            update(1,n,b,a,1);
        
    }
    
}
