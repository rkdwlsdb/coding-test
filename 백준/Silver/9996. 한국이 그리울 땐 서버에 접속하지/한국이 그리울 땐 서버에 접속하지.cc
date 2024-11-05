#include<bits/stdc++.h>
using namespace std;

// 16:46 ~ 17:13(27min)

int n;
string p;

int main(){
    cin >> n >> p;
    int pos = p.find('*');
    string p1 = p.substr(0, pos);
    string p2 = p.substr(pos+1);

    for(int i=0; i<n;  i++){
        cin >> p;
        if(p.size() < (p1.size()+p2.size())) cout << "NE\n"; 
        else if(p1 == p.substr(0, pos) && p2 == p.substr(p.size()-p2.size())) cout << "DA\n";
        else cout << "NE\n"; 
    }
    return 0;
}