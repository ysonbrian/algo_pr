#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int count;
    int a;
    for(int i = 0; i < 3; i ++){
        count = 0;
        for(int j = 0; j < 4; j++) {
            cin >> a;
            if(a == 1) count+=1;
        }
        if(count == 4) {
            cout << "E\n";
        } else if(count == 3) {
            cout <<"A\n";
        } else if(count == 2) {
            cout <<"B\n";
        } else if(count == 1){
            cout <<"C\n";
        } else {
            cout <<"D\n";
        }
    }


    return 0;
}
