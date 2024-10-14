#include <bits/stdc++.h>
using namespace std;

int arr[100];
int a, b, c, cost;

int main(){
    int i, j, k;
    cin >> a >> b >> c;
    for(i=0; i<3; i++){
        cin >> j >> k;
        for(int i=j; j<k; j++){
            arr[j] += 1;
        }
    }
    for (int i:arr){
        if(i == 1) cost += a*i;
        else if(i == 2) cost += b*i;
        else if(i == 3) cost += c*i;
    }
    cout << cost << '\n';
}