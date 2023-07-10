#include <bits/stdc++.h>
using namespace std;
// Time Complexity :O(nlogn)
int LongestSubsetWithZeroSum(vector<int> arr)
{

    // Write your code here
    int n = arr.size();
    unordered_map<int, int> mp;
    int maxi = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (mp.find(sum) != mp.end())
            {
                maxi = max(maxi, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
    }
    return maxi;
}