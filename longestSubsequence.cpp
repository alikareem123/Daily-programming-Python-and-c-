#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longest_subsequence(vector<int> &a)
{
    int n = a.size();
    int longest = 0;

    unordered_set<int> st;
    for (auto it : a)
    {
        st.insert(it);
    }
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x++, cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 4, 3, 0};
    cout << "The longest successive subsequence is " << longest_subsequence(a) << endl;
    return 0;
}