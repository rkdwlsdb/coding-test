#include <bits/stdc++.h>
using namespace std; 
int n, l, r, visited[50][50], a[50][50], sum, cnt;
int dy[]={-1, 0, 1, 0}, dx[]={0, 1, 0, -1};
vector<pair<int, int>>v;
void dfs(int y, int x){
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
        if(abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r){
            visited[ny][nx]=1;
            v.push_back({ny, nx});
            sum += a[ny][nx];
            dfs(ny, nx);
        }
    }
}
int main(){
    cin >> n >> l >> r;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    while(1){
        bool flag = 0;
        memset(visited, 0, sizeof(visited));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    v.clear();
                    v.push_back({i, j});
                    visited[i][j] = 1;
                    sum = a[i][j];
                    dfs(i, j);
                    if(v.size()==1)continue;
                    for(pair<int, int> b : v){
                        a[b.first][b.second] = sum / v.size();
                        flag = 1;
                    }
                }
            }
        }
        if(!flag) break;
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}