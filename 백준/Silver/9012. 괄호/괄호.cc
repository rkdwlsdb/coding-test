#include<bits/stdc++.h>
using namespace std;
int n;
string s;

bool check(string s){
    stack<char>stk;
    for(char a:s){
        if(stk.empty() && a == ')') return 0; 
        if(a == '(') stk.push('(');
        else{
            if(!stk.empty() && stk.top() == '(') stk.pop();
        }
    }
    if(stk.empty()) return 1;
    else return 0;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        if(check(s)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}