#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int s = 0;
    int restoSciolte = 0;
    while (a > 0 || restoSciolte >= b) {
        a += restoSciolte / b;
        restoSciolte %= b;
        s += a;
        restoSciolte += a % b;
        a /= b;
    }
    cout << s << endl;
    return 0;
}

