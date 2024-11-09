#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main(){
    while(scanf("%d", &n) != EOF){
        int i=1, ret=1;
        while(1){
            if(i%n == 0){
                cout << ret << '\n';
                break;
            }
            i = i*10+1;
            i %= n;
            ret+=1;
        }
    }
    
    return 0;
}