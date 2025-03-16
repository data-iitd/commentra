#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Initialize variables N and K with user input
    int N, K;
    cin >> N >> K;

    // Create a vector 'v' of size N to store the input integers
    vector<int> v(N);

    // Read N integers from the user and store them in the vector 'v'
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    // Calculate the number of subarrays of size K that can be formed from the vector 'v'
    int count = ((N - 1) + ((K - 1) - 1)) / (K - 1);

    // Output the result to the console
    cout << count << '\n';
}
