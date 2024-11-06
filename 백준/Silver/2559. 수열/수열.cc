// 10:17 ~

#include <bits/stdc++.h>
using namespace std;

int n, k;
int p[100005];
int ret, maxNum;

int main(){
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> p[i];
        p[i] += p[i-1];
    }
    if(n == k){
        cout << p[n] << '\n';
        return 0;
    }
    for(int i=k; i<=n; i++){
        ret = p[i] - p[i-k];
        if(ret > maxNum) maxNum = ret;
    }
    cout << maxNum << '\n';
    return 0;
}