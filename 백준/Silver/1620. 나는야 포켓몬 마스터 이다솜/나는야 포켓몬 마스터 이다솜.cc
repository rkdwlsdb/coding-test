#include<bits/stdc++.h>
using namespace std;

string s;
int n, m;
map <string, int> mp;
map <int, string> mp2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> s;
        mp.insert({s, i});
        mp2.insert({i, s});
    }
    for(int i=0; i<m; i++){
        cin >> s;
        if(atoi(s.c_str()) == 0){
            cout << mp[s] << '\n';
        }
        else cout << mp2[atoi(s.c_str())] << '\n';
    }
    return 0;
}