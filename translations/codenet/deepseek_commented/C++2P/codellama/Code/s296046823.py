#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K; // 1. Reading the values of N and K from the standard input.

    vector<int> v(N); // 2. Initializing a vector of size N to store N integers.
    for (int i = 0; i < N; ++i)
        cin >> v[i]; // 3. Reading N integers from the standard input and storing them in the vector v.

    # Calculating the number of groups that can be formed using the formula ceil((N-1) / (K-1)).
    count = ((N - 1) + ((K - 1) - 1)) / (K - 1)
    print(count) // 5. Outputting the calculated count.
}

