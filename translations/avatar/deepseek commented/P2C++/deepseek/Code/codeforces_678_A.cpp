#include <iostream>
using namespace std;

int main() {
    int vamshi, z;
    cin >> vamshi >> z;

    // Calculating the result using integer division and addition
    int result = (vamshi / z + 1) * z;

    // Printing the result
    cout << result << endl;

    return 0;
}

