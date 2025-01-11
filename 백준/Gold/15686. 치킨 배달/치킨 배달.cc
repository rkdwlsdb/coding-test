#include <bits/stdc++.h>
using namespace std; 
int n, m, a[54][54], result=987654321;
vector<vector<int>>chickenLst;
vector<pair<int,int>> h, c;
// 치킨집 M개 고르는 함수 
void combi(int start, vector<int> v){ // -1, 빈 벡터
    if(v.size() == m){
        chickenLst.push_back(v);
        return;
    }
    for(int i=start+1; i<c.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

// main 로직
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) h.push_back({i, j});
            if(a[i][j] == 2) c.push_back({i, j});
        }
    } 
    vector<int> v; // 경우의 수를 만들 벡터
    combi(-1, v);
    for(vector<int> cLst : chickenLst){
        int ret=0;
        for(pair<int, int> home : h){
            int _min = 987654321;
            for(int ch : cLst){
                int _dist = abs(home.first - c[ch].first) + abs(home.second - c[ch].second);
                _min = min(_min, _dist);
            }
            ret += _min;
        }
        result = min(result, ret);
    }
    cout << result << '\n';
    return 0;
}
