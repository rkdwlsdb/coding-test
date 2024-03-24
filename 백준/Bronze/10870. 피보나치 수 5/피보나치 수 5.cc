#include<bits/stdc++.h>
using namespace std;

int n;

int fin(int n){
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    return fin(n-1)+fin(n-2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cout << fin(n);
}