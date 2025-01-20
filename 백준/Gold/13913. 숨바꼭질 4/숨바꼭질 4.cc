#include <bits/stdc++.h> 
using namespace std;
int n, k, ret;
int visited[200004], preV[200004];
vector<int>v;

int main(){
    cin >> n >> k;
    visited[n]=1;
    queue<int>q;
    q.push(n);
    while(q.size()){
        int here = q.front();q.pop();
        if(here == k){
            ret = visited[k] - 1;
            break;
        }
        for(int next : {here-1, here+1, 2 * here}){
            if(next < 0 || next > 200000 || visited[next]) continue;
            visited[next] = visited[here]+1;
            preV[next] = here; // e.g. preV[10] = 5;
            q.push(next);
        }
    }
    for(int i=k; i!=n; i=preV[i]){
        v.push_back(i);
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    cout << ret << '\n';
    for(int i:v){
        cout << i << " ";
    }
    cout << '\n';
}