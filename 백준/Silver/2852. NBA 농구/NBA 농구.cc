#include<bits/stdc++.h>
using namespace std;

int n, t, asum, bsum, A, B;
string s, pre;

string print(int sum){
    string m = "00" + to_string(sum / 60);
    string s = "00" + to_string(sum % 60);
    return m.substr(m.size()-2, 2) + ":" + s.substr(s.size()-2, 2);
}
int stringToInt(string a){
    return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str()) ;
}
void go(int &sum, string s){
    sum += stringToInt(s) - stringToInt(pre);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> t >> s;
        if(A > B) go(asum, s);
        else if(B > A) go(bsum, s);
        t == 1? A++ : B++;
        pre = s;
    }
    if(A > B) go(asum, "48:00");
    else if(B > A) go(bsum, "48:00");
    cout << print(asum) << '\n';
    cout << print(bsum) << '\n';
    return 0;
}