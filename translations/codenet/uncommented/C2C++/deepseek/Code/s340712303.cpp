#include<iostream>
#define N 2000
using namespace std;

int num1, math[N+1];

int main(){
    int a, num2, ans, sum = 0;
    int i, j;

    math[0] = 1;
    
    cin >> num1;
    for(i = 0; i < num1; i++){
        cin >> a;
        sum += a;
        for(j = sum - a; j >= 0; j--){
            if(math[j] == 1) math[j + a] = 1;
        }
    }

    cin >> num2;
    for(i = 0; i < num2; i++){
        cin >> ans;
        cout << (math[ans] == 1 ? "yes\n" : "no\n");
    }

    return 0;
}
