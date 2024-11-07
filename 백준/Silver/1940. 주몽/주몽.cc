#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 19:50 ~ 

int n, m, arr[15004];
ll ret;
// 150 000 000 000 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    if(n == 1){
        cout << 0 << '\n';
        return 0;
    }
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] + arr[j] == m){
                ret++;
            }
        }
    }
    cout << ret << '\n';
    return 0;
}