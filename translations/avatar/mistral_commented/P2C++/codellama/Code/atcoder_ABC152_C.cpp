#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Get the number of elements in the array from user input
    int N;
    cin >> N;

    // Initialize an empty vector 'n' of size N
    vector<int> n(N);

    // Get the elements of the array from user input and store them in 'n'
    for (int i = 0; i < N; i++) {
        cin >> n[i];
    }

    // Initialize variables 'a' and 'pos'
    int a = 1, pos = 0;

    // Iterate through the vector 'n' starting from the second element
    for (int i = 1; i < N; i++) {
        // Check if the current element is greater than the previous one
        if (n[pos] > n[i]) {
            // Increment the variable 'a' if the condition is true
            a += 1;
            // Update the position of the previous greater element
            pos = i;
        }
    }

    // Print the value of 'a' as the output
    cout << a << endl;

    return 0;
}

