#include<bits/stdc++.h>
using namespace std;

/*
주어진 영상이 0으로만 되어있으면 0 1로만 되어잇으면 1 
1. n을 0이 될떄까지 반으로 쪼갬 8 -> 4 -> 2 -> 0 
2. (0,0)을 기준으로 현재 -> 오른쪽 -> 아래 -> 우측아래가 같으면 ret 0 or 1 
3. 값이 다르면 순서대로 출력 
*/

int n;
string s;
char a[64][64];
string quard(int y, int x, int size){
    if(size == 1)return string(1, a[y][x]);

    // 영역검사 
    char b = a[y][x];
    string ret = "";
    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            if(b!=a[i][j]){ // 만약 값이 다르면 
                ret += "(";
                ret += quard(y, x, size/2);
                ret += quard(y, x+size/2, size/2);
                ret += quard(y+size/2, x, size/2);
                ret += quard(y+size/2, x+size/2, size/2);
                ret += ")";
                return ret;
            }
        }
    }
    return string(1, a[y][x]);
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<n; j++){
            a[i][j] = s[j];
        }
    }
    cout << quard(0, 0, n);
    return 0;
}