
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;  // Read an input line (not used in further calculations)

    string a;
    cin >> a;  // Read a string input from the user

    int count = 0;
    int result = 1;

    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '1') {
            result *= count + 1;
            count = 0;
        } else {
            count++;
        }
    }

    if (count > 0) {
        result *= count + 1;
    }

    cout << result << endl;  // Print the result

    return 0;
}

