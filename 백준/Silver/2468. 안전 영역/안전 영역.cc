#include<bits/stdc++.h>
using namespace std;

// 17:39 ~ 

int n, y, x, cnt, ret=1;
int a[104][104], v[104][104];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int h){
    v[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(v[ny][nx] == 0 && a[ny][nx] > h) {
            dfs(ny, nx, h);
        }
    }
    return;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    for(int h=1; h<=100; h++){
        cnt = 0;
        fill(&v[0][0], &v[0][0] + 104*104, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(a[i][j] > h && v[i][j] == 0){
                    dfs(i, j, h);
                    cnt++;
                }
            }
        }
        if(cnt > ret) ret = cnt;
    }
    cout << ret << '\n';

    return 0;
}