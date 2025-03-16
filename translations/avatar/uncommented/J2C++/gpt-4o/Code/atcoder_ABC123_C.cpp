#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    long long N;
    cin >> N;
    long long min = 0;

    for (int i = 0; i < 5; i++) {
        long long temp;
        cin >> temp;
        if (i == 0) {
            min = temp;
        } else {
            min = std::min(min, temp);
        }
    }

    cout << static_cast<long long>(ceil(static_cast<double>(N) / min)) + 4 << endl;

    return 0;
}

// <END-OF-CODE>
