#include <bits/stdc++.h> 
using namespace std;
int n, m, sx, sy, ex, ey, visited[300][300];
char a[300][300];
int dy[]={-1, 0, 1, 0}, dx[]={0, 1, 0, -1};
queue<pair<int, int>> q;
void bfs(int y, int x){
    visited[y][x]=1;
    q.push({y, x});
    int cnt=0;
    while(a[ey][ex] != '0'){
        cnt++;
        queue<pair<int, int>> tmp;
        while(q.size()){
            tie(y, x) = q.front();q.pop(); 
            for(int i=0; i<4; i++){
                int ny = y+dy[i];
                int nx = x+dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])continue;
                visited[ny][nx] = cnt;
                if(a[ny][nx] != '0'){
                    a[ny][nx] = '0';
                    tmp.push({ny, nx});
                }
                else if(a[ny][nx] == '0') q.push({ny, nx});
            }
        }
        q = tmp;
    }
}
int main(){
    string s;
    cin >> n >> m;
    cin >> sy >> sx >> ey >> ex; // 좌표 받을대 y, x 주의 
    sx--;sy--;ex--;ey--; // 좌표를 보면 1부터 시작함 
    for(int i=0; i<n; i++){
        cin >> s; // string 받음
        for(int j=0; j<m; j++){
            a[i][j] = s[j];
        }
    }
    bfs(sy, sx);
    cout << visited[ey][ex] << '\n';
}