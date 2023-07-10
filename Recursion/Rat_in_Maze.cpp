#include<bits/stdc++.h>
using namespace std;
void solve(int i,int j,vector<vector<int>> &a,int n,vector<string> &ans,string move,vector<vector<int>> vis)
{
    if(i==n-1 && j==n-1)
    {
        ans.push_back(move);
        return;
    }
    if(i+1<n && !vis[i+1][j] && a[i+1][j]==1)
    {
        vis[i][j]==1;
        solve(i+1,j,a,n,ans,move+"D",vis);
        vis[i][j]=0;
    }
    if(j-1>=0 && !vis[i][j-1] && a[i][j-1]==1)
    {
        vis[i][j]=1;
        solve(i,j-1,a,n,ans,move+"L",vis);
        vis[i][j]=0;
    }
    if(j+1<n && !vis[i][j+1] && a[i][j+1]==1)
    {
        vis[i][j]=1;
        solve(i,j+1,a,n,ans,move+"R",vis);
        vis[i][j]=0;
    }
    if(i-1>=0 && !vis[i-1][j] && a[i-1][j]==1)
    {
        vis[i][j]=1;
        solve(i-1,j,a,n,ans,move+"U",vis);
        vis[i][j]=0;
    }

}
vector<string> findPath(vector<vector<int>> &m,int n)
{
    vector<string> ans;
    vector<vector<int>> visited(n,vector<int> (n,0));
    if(m[0][0]==1)solve(0,0,m,n,ans,"",visited);
    return ans;
}
int main()
{
    
}