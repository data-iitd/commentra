
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the value of N
    long long N;
    cin >> N;

    // Initialize min to 0 and find the minimum of the first five inputs
    long long min = 0;
    for (int i = 0; i < 5; i++) {
        if (i == 0)
            cin >> min;
        else
            min = min < sc.nextLong()? min : sc.nextLong();
    }

    // Calculate the result and print it
    cout << (long long)ceil((double)N / min) + 4 << endl;
}

