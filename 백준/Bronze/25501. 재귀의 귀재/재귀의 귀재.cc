#include<bits/stdc++.h>
using namespace std;

int t;
string s;
int cnt;
int ret;

int recursion(const char *s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    // printf("ABBA: %d\n", isPalindrome("ABBA")); // 1
    // printf("ABC: %d\n", isPalindrome("ABC"));   // 0
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> s;
        ret = isPalindrome(s.c_str());
        cout << ret << " " << cnt << '\n';
        cnt = 0;
    }
}