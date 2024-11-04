#include<bits/stdc++.h>
using namespace std;

int n, arr[26];
string temp, ret;

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> temp;
        arr[temp[0]-'a'] += 1;
    }
    for(int i=0; i<26; i++){
        if(arr[i] >= 5){
            ret += i+'a';
        }
    }
    if(ret.size()) cout << ret << '\n';
    else cout << "PREDAJA\n";
    return 0;
}