#include <iostream>
using namespace std;

int main() {
    int candeleIntere, b;
    cin >> candeleIntere >> b;

    int s = 0;
    int restoSciolte = 0;

    while (candeleIntere > 0 || restoSciolte >= b) {
        s += candeleIntere;
        restoSciolte += candeleIntere % b;
        candeleIntere /= b;
        candeleIntere += restoSciolte / b;
        restoSciolte %= b;
    }

    cout << s << endl;
    return 0;
}

