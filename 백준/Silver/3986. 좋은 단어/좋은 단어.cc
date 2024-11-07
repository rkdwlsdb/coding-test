#include<bits/stdc++.h>

using namespace std;

int n, ret;
string w;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> w;
        stack<char> stk;
        for(auto i: w){
            if(stk.size() && stk.top() == i) stk.pop();
            else stk.push(i);
        }
        if (stk.size() == 0) ret++;
    }
    cout << ret << '\n';
    return 0;
}