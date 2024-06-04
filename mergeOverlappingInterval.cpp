#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> arr){
    int n = arr.size();

    vector<vector<int>> ans;
    
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }else{
            ans.back()[1] = max(arr[i][1], ans.back()[1]);
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout<<"The merged overlapping interval is: "<<"\n";

    for(auto i: ans){
        cout<<"[" <<i[0] <<", " <<i[1]<<"] ";
    }
    cout<<endl;
    return 0;
}