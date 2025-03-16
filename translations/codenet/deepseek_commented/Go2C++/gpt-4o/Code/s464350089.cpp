#include <iostream>
using namespace std;

int main() {
    // Read the initial height `h` and the number of attacks `n`
    int h, n;
    cin >> h >> n;

    // Initialize a variable to keep track of the total damage dealt
    int a = 0;

    // Read each attack's damage and accumulate the total damage
    for (int i = 0; i < n; i++) {
        int damage;
        cin >> damage;
        a += damage;
    }

    // Check if the total damage is greater than or equal to the initial height
    if (h > a) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}

// <END-OF-CODE>
