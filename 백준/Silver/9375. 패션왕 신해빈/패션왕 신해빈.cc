#include <bits/stdc++.h>
using namespace std;

// 18:34 ~  
typedef long long ll;
int t, n;
string a, b;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while(t--){
        map <string, int> mp;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a >> b;
            mp[b]++;
        }
        ll ret=1;
        for(auto it:mp){
            ret *= ((ll)it.second+1);
        }
        ret--;
        cout << ret << '\n';
    }
    
    return 0;
}