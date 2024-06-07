#include <iostream>
#include <vector>

using namespace std;


int majority_element(vector<int> a){
    int n = a.size();
    int el = -1;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if(cnt == 0){
            cnt = 1;
            el = a[i];
        }
        else if(el == a[i]) cnt++;
        else cnt--;
    }

    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(el == a[i]) cnt++;
    }
    if(cnt > (n / 2)) return el;
    return -1;
}

int main(){
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majority_element(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}