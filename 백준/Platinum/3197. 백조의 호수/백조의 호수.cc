#include <bits/stdc++.h> 
using namespace std;
int n, m, y, x, ly, lx, swan_visited[1501][1501], visited[1501][1501], cnt=0;
char a[1501][1501];
int dy[]={-1, 0, 1, 0}, dx[]={0, 1, 0, -1};
string s;
queue<pair<int, int>>swan_Q, waterQ, swan_tmpQ, water_tmpQ;
void qClear(queue<pair<int, int>> &q){
    queue<pair<int, int>> emptyQ;
    swap(q, emptyQ);
}
bool swanOK(){
    while(swan_Q.size()){
        tie(y, x)=swan_Q.front();swan_Q.pop();
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || ny >=n || nx<0 || nx>=m || swan_visited[ny][nx])continue;
            swan_visited[ny][nx]=1;   
            if(a[ny][nx] == 'L') return 1;
            if(a[ny][nx] == '.'){
                swan_Q.push({ny, nx});
            }
            if(a[ny][nx] == 'X'){
                swan_tmpQ.push({ny, nx});
            }
        }
    }
    return 0;
}

void water_melting(){
    while(waterQ.size()){
        tie(y, x)=waterQ.front();waterQ.pop();
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || ny >=n || nx<0 || nx>=m || visited[ny][nx])continue;
            if(a[ny][nx] == 'X'){
                visited[ny][nx]=1;
                water_tmpQ.push({ny, nx});
                a[ny][nx] = '.';
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<m; j++){
            a[i][j] = s[j];
            if(a[i][j] == 'L'){
                ly = i;
                lx = j;
            }
            if(a[i][j] == '.' || a[i][j] == 'L'){
                visited[i][j] = 1;
                waterQ.push({i, j});
            }
        }
    }
    swan_visited[ly][lx]=1;
    swan_Q.push({ly, lx});
    while(1){
        // 백조가 만날 수 있는지 확인 만약 .이라면 임시 큐에 넣음 - 만난다면 true로 break(종료조건)
        if(swanOK()) break;

        // 물과 인접한 X를 찾아 water_tmpQ에 넣음 
        water_melting();

        // 임시큐를 다시 큐에 넣고
        swan_Q = swan_tmpQ;
        waterQ = water_tmpQ;

        // 큐를 초기화 
        qClear(swan_tmpQ);
        qClear(water_tmpQ);

        // 카운트 증가 
        cnt++;
    }
    cout << cnt << '\n';
}