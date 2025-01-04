#include<bits/stdc++.h>
using namespace std;

int n, c, tmp, a[1004];
vector<pair<int, int>> v;
map<int, int> mp, mp_order;
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){ // cnt
        return mp_order[a.second] < mp_order[b.second];
    }
    return a.first > b.first;
}
int main(){
    cin >> n >> c;
    for(int i=0; i<n; i++){
        cin >> a[i];
        mp[a[i]]++; // cnt
        if(mp_order[a[i]] == 0){
            mp_order[a[i]] = i+1;
        }
    }
    for(auto it:mp){
        v.push_back({it.second,it.first}); // cnt, n 
    }
    sort(v.begin(), v.end(), cmp);
    for(auto i:v){
        for(int j=0; j<i.first; j++){
            cout << i.second << " ";
        }
    }
    return 0;   
}
