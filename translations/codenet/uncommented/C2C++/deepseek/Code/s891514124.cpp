#include <iostream>
using namespace std;

int main() {
    int S;
    cin >> S;

    if (S < 60) {
        cout << "0:0:" << S << endl;
    } else if (S < 3600) {
        cout << "0:" << S / 60 << ":" << S % 60 << endl;
    } else {
        cout << S / 3600 << ":" << (S % 3600) / 60 << ":" << (S % 60) << endl;
    }

    return 0;
}
