#include<bits/stdc++.h>
using namespace std;
/*- c를 만날때까지 -1
- c를 만나면 0으로 바꾸고 다음 c를 만날때까지 ++
- 다음 c를 만나면 또 0으로 바꾸고*/

int h, w, a[104][104], c[104][104];
char s[104];

int main(){
    cin >> h >> w;
    for(int i=0; i<h; i++){
        scanf("%s", &s);
        for(int j=0; j<w; j++){
            a[i][j] = s[j];
        }
    }
    for(int i=0; i<h; i++){
        int min=0;
        for(int j=0; j<w; j++){
            if(a[i][j] == 99){ // c일때 
                c[i][j] = 0;
                min = 1;
            }
            if(min == 0 && a[i][j] != 99) c[i][j] = -1;
            if(min >= 1 && a[i][j] != 99) c[i][j] = min++;            
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}