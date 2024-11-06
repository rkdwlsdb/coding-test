// 11:13 ~

#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;
map <int, string> mp1;
map <string, int> mp2;

// 최대 범위 100,000,000,000

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> s;
        mp1[i] = s;
        mp2[s] = i;
    }
    for(int i=0; i<m; i++){
        cin >> s;
        if(atoi(s.c_str())) cout << mp1[atoi(s.c_str())] << '\n';
        else cout << mp2[s] << '\n';
    }
    return 0;
}