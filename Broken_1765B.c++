#include <string>
#include <iostream>
#include <vector>

using namespace std;

void calculate(string s, int n){
    for(int i = 1; i < n - 1; i++){
        if(i % 2 !=0){
            if(s[i] != s[i+1]){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        calculate(s, n);
    }
    return 0;
}