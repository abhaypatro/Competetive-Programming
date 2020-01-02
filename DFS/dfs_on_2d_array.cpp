#include<bits/stdc++.h>
using namespace std;
// Returns the maximum number of 1's connected by a edge
int isposs(int i,int j, int visited[][50],int n, char cake[][55])
{
    if(i<0 || i>=n || j<0 || j>=n || (visited[i][j]==1) ||(cake[i][j]=='0') )
        return 0;
    else
        return 1;
}
int dfs(char cake[][55], int n, int visited[][50], int i , int j)
{     
    int p=0,q=0,r=0,s=0;
      visited[i][j]=1;
      if(isposs(i-1,j,visited,n,cake))
          p=dfs(cake,n,visited,i-1,j);
    if(isposs(i+1,j,visited,n,cake))
          q=dfs(cake,n,visited,i+1,j);
    if(isposs(i,j+1,visited,n,cake))
          r=dfs(cake,n,visited,i,j+1);
    if(isposs(i,j-1,visited,n,cake))
          s=dfs(cake,n,visited,i,j-1);
    
    return(1+p+q+r+s);
}
int solve(int n,char cake[][55])
{
    int ctr=0;
    int visited[50][50];
    int i,j;
    for(i=0; i<50;i++)
    {
    for(j=0;j<50;j++)
        visited[i][j]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(cake[i][j]=='1' && visited[i][j]==0)
            {
                int a=dfs(cake,n,visited,i,j);
                if(a>ctr)
                    ctr=a;
             }
       }
    }
    return ctr;

}
