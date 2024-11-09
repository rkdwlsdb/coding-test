// #include <bits/stdc++.h>

// using namespace std;

// // 21:10 ~ 

// int n, cnt;
// string s;

// int main(){
//     cin >> n;
//     for(int i=0; i<n ;i++){
//         cin >> s;
//         stack<char> stk;
//         for(char a:s){
//             if(stk.size()&&stk.top() == a)stk.pop();
//             else stk.push(a);
//         }
//         if(stk.size() == 0)cnt++;
//     }
//     cout << cnt << '\n';
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

// 21:10 ~ 

int n, cnt;
string s;

int main(){
    cin >> n;
    for(int i=0; i<n ;i++){
        vector<char> s1;
        cin >> s;
        //  사이즈가 홀수면 바로 통과 
        if(s.size()&1)continue;

        for(int j=0; j<s.size(); j++){    
            if(!s1.size()){
                s1.push_back(s[j]);
                continue;
            }
            // cout << "j: " << j << " s1[s1.size()-1]: " << s1[s1.size()-1] << " s[j]: " << s[j] << '\n';
            if(s[j] == s1[s1.size()-1]) s1.pop_back();
            else s1.push_back(s[j]);
        }
        if(!s1.size())cnt++;
    }
    cout << cnt << '\n';
    return 0;
}