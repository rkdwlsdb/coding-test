#include <bits/stdc++.h>
using namespace std;

int n, pos;
string fp, pre, post, fname;

int main(){
    cin >> n >> fp;
    pos = fp.find("*");
    pre = fp.substr(0,pos);
    post = fp.substr(pos+1);
    
    for(int i=0; i<n; i++){
        cin >> fname;
        if((pre+post).size() > fname.size()) cout << "NE\n";
        else{
            if(fname.substr(0, pre.size()) == pre && fname.substr(fname.size()-post.size(), fname.size()) == post) cout << "DA\n";
            else cout << "NE\n";
        }
    }
    
    return 0;
}