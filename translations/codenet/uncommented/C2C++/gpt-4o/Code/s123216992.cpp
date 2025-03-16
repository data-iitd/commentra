#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a, b;
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        if (b < a) swap(&a, &b);
        cout << a << " " << b << endl;
    }
    return 0;
}

// <END-OF-CODE>
