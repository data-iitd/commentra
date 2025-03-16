#include <iostream>
using namespace std;

int main() {
    // Read two integers from input, separated by a space
    int vamshi, z;
    cin >> vamshi >> z;

    // Calculate the smallest multiple of z that is greater than or equal to vamshi
    // This is done by performing integer division of vamshi by z, adding 1, and then multiplying by z
    int result = (vamshi / z + 1) * z;

    // Print the result
    cout << result << endl;

    return 0;
}

// <END-OF-CODE>
