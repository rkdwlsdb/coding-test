#include<bits/stdc++.h>
using namespace std;
int n, m, j, l, r, temp, ret;

int main(){
    cin >> n >> m >> j;
    l = 1;
    for(int i=0; i<j; i++){
        r = l + m - 1;
        cin >> temp;
        if(temp >= l && temp <= r) continue;
        if(temp > r){
            ret += (temp - r);
            l += (temp - r);
        }
        else {
            ret += (l - temp);
            l = temp;
        }
    }
    cout << ret << '\n';
    return 0;
}