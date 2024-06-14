#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubArray(vector<int> &arr)
{
    int n = arr.size();
    int max_len = 0;
    int sum = 0;
    unordered_map<int, int> sumIndexMap;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            max_len = i + 1;
        }
        else if (sumIndexMap.find(sum) != sumIndexMap.end())
        {
            max_len = max(max_len, i - sumIndexMap[sum]);
        }
        else
        {
            sumIndexMap[sum] = i;
        }
    }
    return max_len;
}

int main()
{
    vector<int> a = {9, -3, 3, -1, 6, -5};
    cout << longestSubArray(a) << endl;
    return 0;
}