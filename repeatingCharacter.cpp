#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solve(string str)
{
    if (str.size() == 0)
    {
        return 0;
    }
    int maxans = INT16_MIN;
    for (int i = 0; i < str.length(); i++)
    {
        unordered_set<int> Set;
        for (int j = i; j < str.length(); j++)
        {
            if (Set.find(str[j]) != Set.end())
            {
                maxans = max(maxans, j - i);
                break;
            }
            Set.insert(str[j]);
        }
    }
    return maxans;
}

int main()
{
    string str = "takeUforward";
    cout << "The length of the longest substring is " << solve(str) << endl;
    return 0;
}