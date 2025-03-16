#include <iostream>
#include <cmath>
#include <queue>
#include <random>
#include <limits>

using namespace std;

int main() {
    long long N;
    cin >> N;

    // Initialize min to 0 and find the minimum of the first five inputs
    long long min = 0;
    for (int i = 0; i < 5; i++) {
        long long temp;
        cin >> temp;
        if (i == 0)
            min = temp;
        else
            min = min < temp ? min : temp;
    }

    // Calculate the result and print it
    cout << static_cast<long long>(ceil(static_cast<double>(N) / min)) + 4 << endl;

    return 0;
}
