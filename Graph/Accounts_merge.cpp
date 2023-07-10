#include <bits/stdc++.h>
using namespace std;
class disjointSet
{
    vector<int> rank, parent, size;

public:
    disjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    // code here
    int n = accounts.size();
    disjointSet ds(n);
    unordered_map<string, int> mapMailNode;
    // mapping each name to a particular node starting from 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {
            string mail = accounts[i][j];
            if (mapMailNode.find(mail) == mapMailNode.end())
            {
                mapMailNode[mail] = i;
            }
            else
            {
                ds.unionBySize(i, mapMailNode[mail]);
            }
        }
    }
    // storing part
    vector<string> mergeMail[n];
    for (auto it : mapMailNode)
    {
        string mail = it.first;
        int node = ds.findUPar(it.second);
        mergeMail[node].push_back(mail);
    }
    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
        if (mergeMail[i].size() == 0)
            continue;
        sort(mergeMail[i].begin(), mergeMail[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for (auto it : mergeMail[i])
        {
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}