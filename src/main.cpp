#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &arr){
    int maxVal = 0;
    int minVal = INT_MAX;

    int n = arr.size();

    for(int i = 0; i < n; i++){
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i] - minVal);
    }
    return maxVal;
}

int main(int argc, char *argv[])
{
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    std::cout << "The max value is: " <<maxPro<< std::endl;
}
