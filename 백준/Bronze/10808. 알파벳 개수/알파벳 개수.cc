#include <bits/stdc++.h>
using namespace std;

int arr[26], i;
string word;

int main(){
    cin >> word;
    for(int i=0; i<word.size(); i++){
        arr[word[i]-'a'] += 1;
    }
    for(int i:arr){
        cout << i << " ";
    }
    "\n";
    return 0;
}