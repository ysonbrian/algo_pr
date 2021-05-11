#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[20];
char tem[20];
int main() {
  int num, a,b, lens, temp =0, res;

  cin >> num;

  for(int i = 0; i<num; i++) {
    temp = 0;
    cin >> a;
    for(int j = 0; j<a; j++) {
      cin >> b >> s;
      if(b>=temp) {
        temp=b;
        strcpy(tem,s);
        lens=strlen(s);
      }
    }
    cout<<tem<<endl;
  }
}
