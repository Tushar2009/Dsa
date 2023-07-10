#include <bits/stdc++.h>
using namespace std;
// The upper bound algorithm finds the first or the smallest index in a sorted array
// where the value at that index is greater than the given key i.e. x.
//  Time Complexity: O(logN), where N = size of the given array.
int upperBound(vector<int> &arr, int x, int n)
{
    // Write your code here.
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
    // return upper_bound(arr.begin(),arr.end(),x)-arr.begin(); syntax for stl
}