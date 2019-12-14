#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;
vector<lld>ar(100000);
vector< pair<lld,lld> > tr(400000);
void build(lld s , lld e , lld in)
{
    if(s==e)
    {
        tr[in].first=ar[s];
        tr[in].second=s;
    }
    else
    {
        lld mid=(s+e)/2;
        build(s,mid,2*in);
        build(mid+1,e,2*in+1);
        if(tr[2*in].first > tr[2*in+1].first)
        {
            tr[in].first=tr[2*in].first;
            tr[in].second=tr[2*in].second;
        }
        else
        {
             tr[in].first=tr[2*in+1].first;
             tr[in].second=tr[2*in+1].second;
        }
    }
}
void update(lld s , lld e , lld in , lld ind , lld val)
{
    if(s==e)
    {
        ar[s]=val;
        tr[in].first=val;
        tr[in].second=ind;
    }
    else
    {
        lld mid=(s+e)/2;
        if(ind>mid)
            update(mid+1,e,2*in+1,ind,val);
        else
            update(s,mid,2*in,ind,val);

        if(tr[2*in].first>tr[2*in+1].first)
        {
            tr[in].first=tr[2*in].first;
            tr[in].second=tr[2*in].second;
        }
        else
        {
             tr[in].first=tr[2*in+1].first;
             tr[in].second=tr[2*in+1].second;
        }

    }
}
pair<lld , lld> query(lld s, lld e, lld l , lld r , lld in)
{
    if(r<s || l>e)
    {
       return make_pair(INT_MIN,-1);
    }
    else
    if(s>=l && e<=r)
    {
        return tr[in];
    }
    else
    {
        lld mid;
        mid=(s+e)/2;
        pair<lld,lld> p=query(s,mid,l,r,2*in);
        pair<lld,lld> q=query(mid+1,e,l,r,2*in+1);
        if(p.first>q.first)
            return p;
        else
            return q;
    }
}
int main()
{
    lld n;
    cin>>n;
    lld i;
    for(i=1;i<=n;i++)
        cin>>ar[i];
    build(1,n,1);
    // for(i=1;i<=2*n;i++)
    //     cout<<tr[i].first<<" ";
    cout<<endl;
    lld t;
    cin>>t;
    while(t--)
    {
      char ch;
      lld a,b;
      cin>>ch>>a>>b;
      if(ch=='U')
        update(1,n,1,a,b);
    
      else
      {
          pair<lld,lld>p=query(1,n,a,b,1);
          lld temp=p.first;
          // cout<<temp<<" "<<p.second<<" ";
           pair<lld,lld>q,r;
          if(p.second!=a)
          q=query(1,n,a,p.second-1,1);
          else
              q.first=0;
          if(p.second!=b)
          r=query(1,n,p.second+1,b,1);
          else
              r.first=0;
          lld temp2=max(q.first,r.first);

          cout<<temp+temp2<<endl;
      }
    }
}
