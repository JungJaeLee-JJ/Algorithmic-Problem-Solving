#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    n = n % 8;
    if(n == 0) n = 8;
    if(n == 1){
        cout << 1;
    }
    else if(n == 2 || n == 8){
        cout << 2;
    }
    else if(n == 3 || n == 7){
        cout << 3;
    }
    else if(n == 4 || n == 6){
        cout << 4;
    }
    else{
        cout << 5;
    }
    return 0;
}