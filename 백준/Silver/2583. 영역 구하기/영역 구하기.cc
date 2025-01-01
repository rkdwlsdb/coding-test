/*
1. k의 좌표인 부분을 1로 표시 
2. dfs로 a[y][x] == 0인 부분을 커넥티드 콤포넌트를 cnt++ 
3. 2번할때 dfs한 회수를 area++; 
*/

// 23:25 ~ 00:03

#include<bits/stdc++.h>
using namespace std;

int m, n, k;
int x_1, x_2, y_1, y_2, a[104][104], v[104][104], cnt, area[104];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<int> ret;

int dfs(int y, int x){
    v[y][x] = 1;
    int ret = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= m || nx < 0 || nx >= n || v[ny][nx] == 1)continue;
        if(a[ny][nx] == 1) continue;
        ret += dfs(ny, nx);
    }
    return ret;
}

int main(){
    cin >> m >> n >> k;
    while(k--){
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        for(int i=x_1; i<x_2; i++){
            for(int j=y_1; j<y_2; j++){
                a[j][i] = 1;
            }
        }   
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(a[i][j] != 1 && v[i][j] == 0){
                ret.push_back(dfs(i, j));
            }
        }
    }
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    sort(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for(int i: ret) cout << i << " ";
    return 0;
}
