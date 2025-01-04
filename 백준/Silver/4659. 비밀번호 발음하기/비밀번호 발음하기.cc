#include<bits/stdc++.h>
using namespace std;
/*
1. 모음이 있는지 확인 
2. 같은 글자가 연속인지 확인 이때 ee와 oo는 허용
*/

string s;
int lcnt, vcnt; // 모음, 자음 

int main(){
    while(1){
        cin >> s;
        if(s.compare("end") == 0) break;
        lcnt = vcnt = 0;
        bool flag = 0;
        bool include_Vowel = 0;
        int prev = -1; 
        for(int i=0; i<s.length(); i++){
            int idx = s[i];
            if(idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u'){
                include_Vowel = 1;
                lcnt++;
                vcnt=0;
            }
            else {
                lcnt=0;
                vcnt++; 
            }
            if(vcnt == 3 || lcnt == 3) flag = 1;
            if(i > 0 && (prev == idx) && (idx != 'e' && idx != 'o')){
                flag = 1;
            }
            prev = idx;
        }
        if(!include_Vowel) flag=1;
        if(flag){
            cout << "<" << s << "> is not acceptable.\n";
        }
        else cout << "<" << s << "> is acceptable.\n";
    }
    return 0;
}