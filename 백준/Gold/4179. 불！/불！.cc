#include <bits/stdc++.h>
using namespace std; 
int INF = 987654321;
char a[1004][1004];
int n, m, sy, sx, ret, y, x;
int dy[]={-1, 0, 1, 0}, dx[]={0, 1, 0, -1};
int fire_check[1004][1004], person_check[1004][1004];
bool in(int a, int b){
    return 0<=a && a<n && 0<=b && b<m;
}   
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    queue<pair<int,int>>q;
    cin >> n >> m;
    fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'F'){
                fire_check[i][j] = 1;
                q.push({i, j});
            }
            if(a[i][j] == 'J'){
                sx = j;
                sy = i;
            }
        }
    }

    // fire BFS 탐색해서 누적 
    while(q.size()){ // fire들이 쌓여있어서 
        tie(y, x) = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(!in(ny, nx)) continue;
            if(fire_check[ny][nx] != INF || a[ny][nx] == '#') continue;
            fire_check[ny][nx] = fire_check[y][x]+1;
            q.push({ny, nx});
        }
    }

    person_check[sy][sx] = 1;
    q.push({sy, sx});
    while(q.size()){ // 지훈이가 탈출하기위해 
        tie(y, x) = q.front(); q.pop();
        if(x == m-1 || y == n-1 || x == 0 || y == 0){
            ret = person_check[y][x];
            break;
        }
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(!in(ny, nx)) continue;
            if(person_check[ny][nx] || a[ny][nx] == '#') continue;
            if(fire_check[ny][nx] <= person_check[y][x] + 1) continue;
            person_check[ny][nx] = person_check[y][x]+1;
            q.push({ny, nx});
        }
    }
    if(ret != 0) cout << ret << '\n';
    else cout << "IMPOSSIBLE \n";
	return 0;
}