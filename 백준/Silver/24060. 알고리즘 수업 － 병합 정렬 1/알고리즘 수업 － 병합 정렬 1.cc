#include<bits/stdc++.h>

using namespace std;

int A[500004], tmp[500004];
int n, k, cnt;
bool flag=false;

void merge(int A[], int p, int q, int r);

void merge_sort(int A[], int p, int r){ // A를 오름차순 정렬 
    if(p < r){
        int q = floor((p+r)/2);
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

void merge(int A[], int p, int q, int r){
    int i = p;
    int j = q+1;
    int t = 1;

    while(i <= q && j <= r){
        if(A[i] <= A[j]){
            tmp[t++] = A[i++];
        }
        else {
            tmp[t++] = A[j++];
        }

    }

    while(i <= q){
        tmp[t++] = A[i++]; 
    }
    while(j <= r){
        tmp[t++] = A[j++];
    }
    i = p;
    t = 1;
    while(i<=r){
        A[i++] = tmp[t++];
        cnt++;
        // cout<< cnt <<'\n';
        if(cnt == k){
            cout << A[i-1];
            flag = true;
            return;
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    merge_sort(A, 0, n-1);
    if(!flag){
        cout << -1;
    }
    return 0;
}