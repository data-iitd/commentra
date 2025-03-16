#include <iostream>
using namespace std;

int main() {
    int h, a;
    cin >> h >> a;

    // Calculate the number of shoes needed by performing integer division
    int sho = h / a;

    // Calculate the remaining height after accounting for full shoes
    int am = h % a;

    // If there is any remaining height, we need one additional shoe
    if (am != 0) {
        sho += 1;  // Increment the shoe count by 1 for the remaining height
    }

    // Print the total number of shoes required
    cout << sho << endl;

    return 0;
}

