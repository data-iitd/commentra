#include <iostream>
using namespace std;

int main() {
    int v[10];
    int sum = 0;

    for(int i = 0; i < 10; i++)
        cin >> v[i];

    for(int i = 0; i < 10; i++)
        sum += v[i];

    cout << sum << endl;

    return 0;
}

// <END-OF-CODE>
