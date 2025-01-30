#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int maxw = INT_MIN;
        int maxh = INT_MIN;
        while(n--){
            int w, h;
            cin>>w>>h;
            maxw= max(maxw,w);
            maxh = max(maxh, h);
            
            
        }
        cout<<2*(maxw+maxh)<<endl;
    }
}