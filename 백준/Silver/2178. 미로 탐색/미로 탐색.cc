#include <bits/stdc++.h>
using namespace std;

// BFS 2:34 ~ 

const int mn = 104;
int mp[mn][mn], v[mn][mn], n, m, y, x;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &mp[i][j]);
        }
    }
    queue<pair<int,int>> q;
    v[0][0] = 1; 
    q.push({0, 0});
    while(q.size()){
        tie(y, x) = q.front(); q.pop(); // pair는 tie를 사용하여 변수를 받아옴 
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || mp[ny][nx] == 0)continue;
            if(v[ny][nx]) continue;
            v[ny][nx] = v[y][x] + 1;
            q.push({ny, nx});
        } 
    }
    printf("%d\n", v[n-1][m-1]);
    return 0;
}
