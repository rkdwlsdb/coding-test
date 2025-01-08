#include<bits/stdc++.h>
using namespace std;

int n, m, a[104][104], visited[104][104], ret, cnt;
int dy[4]={-1, 0, 1, 0}, dx[4]={0, 1, 0, -1};
vector<pair<int, int>>v;
void go(int y, int x){
    visited[y][x] = 1;
    if(a[y][x] == 1){
        v.push_back({y, x});
        return;
    }
    for(int i=0; i<4; i++){
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
        go(ny, nx);
    }
    return;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    while(1){
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        v.clear();
        go(0,0);
        cnt = v.size();
        for(pair<int, int> b : v){
            a[b.first][b.second] = 0;
        }
        bool flag=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j]) flag=1;
            }
        }
        ret++;
        if(!flag) break;
    }
    cout << ret << '\n'; // 걸린 시간 
    cout << cnt << '\n'; // 마지막에 남은 치즈 수
    return 0;
}