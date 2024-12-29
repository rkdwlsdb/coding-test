#include<bits/stdc++.h>
using namespace std;

int t, m, n, k, y, x, a[54][54], v[54][54], ret;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x){
    v[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(a[ny][nx] == 1 && v[ny][nx] == 0) dfs(ny, nx);
    }
    return;
}
int main(){
    cin >> t;
    for(int i=0; i<t; i++){
        fill(&a[0][0], &a[0][0] + 54 * 54, 0);
        fill(&v[0][0], &v[0][0] + 54 * 54, 0);
        ret = 0;
        
        cin >> m >> n >> k;
        for(int j=0; j<k; j++){
            cin >> x >> y;
            a[y][x] = 1;
        }
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(a[j][k] == 1 && v[j][k] == 0){
                    dfs(j, k);
                    ret++;
                }
            }
        }
        cout << ret << '\n';
    }
    return 0;
}