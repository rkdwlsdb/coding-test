#include<bits/stdc++.h>
using namespace std;

int n;
string s, ns;
vector<string> v;
void go(){
    while(true){
        if(ns.size() && ns.front() == '0'){
            ns.erase(ns.begin());
        }
        else break;
    }
    if(ns.size() == 0) ns = "0";
    v.push_back(ns);
    ns = "";
}
bool cmp(string a, string b){
    if(a.size() == b.size()){
        return a < b;
    }
    return a.size() < b.size();
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        ns = "";
        for(int j=0; j<s.size(); j++){
            if(s[j]<65){
                ns += s[j]; 
            }
            else if(ns.size()){
                go();
            }
        }
        if(ns.size()) go();
    }
    sort(v.begin(), v.end(), cmp);
    for(auto it:v){
        cout << it << '\n';
    }
}