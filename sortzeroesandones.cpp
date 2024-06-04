#include <vector>
#include <iostream>
using namespace std;

void sortArray(vector<int> &arr, int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    int n = 6;
    sortArray(arr, n);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}