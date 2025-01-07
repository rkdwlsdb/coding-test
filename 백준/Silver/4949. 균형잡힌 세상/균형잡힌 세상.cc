#include<bits/stdc++.h>
using namespace std;
string s;
string parsing_string(string s){
    int start = 0;
    int end = s.find('.');
    return s.substr(start, end+1);
}
bool check(string s){
    stack<char> stk;
    for(char a:s){
        if(a == '(') stk.push('(');
        else if (a == ')'){
            if(!stk.empty() && stk.top() == '(') stk.pop();
            else return 0;
        }
        if(a == '[') stk.push('[');
        else if(a == ']'){
            if(!stk.empty() && stk.top() == '[' ) stk.pop();
            else return 0;
        }
    }
    if(stk.empty()) return 1;
    else return 0;
}
int main(){
    while(getline(cin, s)){
        // cout << s << '\n';
        string s1 = parsing_string(s);
        // cout << "s1: " << s1 << '\n';
        if(s1.size() == 1 && s1 == ".") break;
        // cout << s1 << '\n';
        if(check(s1)) cout << "yes\n";
        else cout << "no\n";
        s.substr(s1.size());
    }
    return 0;
}