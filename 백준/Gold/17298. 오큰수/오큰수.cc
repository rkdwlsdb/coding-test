#include<bits/stdc++.h>
using namespace std;
int n, a[1000001], ret[1000001];
stack<int>stk;

int main(){
    cin >> n;
    memset(ret, -1, sizeof(ret));
    for(int i=0; i<n; i++){
        cin >> a[i]; // a[0] = 3, a[1] = 5
        while(stk.size() && a[stk.top()] < a[i]){
            ret[stk.top()] = a[i]; // ret[0] = 5
            stk.pop();
        }
        stk.push(i); // 0
    }
    for(int i=0; i<n; i++) cout << ret[i] << " ";
    return 0;
}