#include <bits/stdc++.h>

using namespace std;

char arr[26], mid;
string s, ret;
int status;

int main() {
  cin >> s;
  for (char i : s) arr[i]++;
  for (int i = 'Z'; i >= 'A'; i--) {
      if(arr[i]){
          if (arr[i] & 1) {
              status++;
              mid = (char)i;
              arr[i]--;
          }
          if (status > 1) {
              cout << "I'm Sorry Hansoo\n";
              return 0;
          }
          for(int j = 0; j < arr[i]; j+=2){
            ret = (char)i + ret;
            ret += (char)i;
          }
      }
  }
  if (status){
      ret.insert(ret.begin()+ret.size()/2, mid);
  }
  cout << ret << '\n';
  return 0;
}