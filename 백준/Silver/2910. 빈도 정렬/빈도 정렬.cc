#include<bits/stdc++.h>
using namespace std;
/*
1. 정렬 문제 
2. 순위가 정해져 있는 정렬 문제(1순위 count, 2순위 order) 
3. 따라서 map이 2개가 필요한것을 알아야함
4. 정렬까지해야하니까 vector넣어서 cmp를 기준으로 정렬한 후 
5. 출력 
*/

int n, c, a;
vector<pair<int, int>> v;
map<int, int> mp_cnt, mp_order;

bool cmp(pair<int, int> a, pair<int, int>b){
    if(a.first == b.first){
        return mp_order[a.second] < mp_order[b.second];
    }
    return a.first > b.first;
}

int main(){
    cin >> n >> c;
    for(int i=0; i<n; i++){
        cin >> a;
        mp_cnt[a]++;
        if(mp_order[a]==0) mp_order[a] = i+1; // 순서를 넣어주는 용도 
    }
    for(auto it: mp_cnt){
        v.push_back({it.second, it.first}); // cnt, n 
    }
    sort(v.begin(), v.end(), cmp);
    for(auto i:v){
        for(int j=0; j<i.first; j++){
            cout << i.second << " ";
        }   
    }
    cout << "\n";
    return 0;
}
