#include <iostream> // For input and output
#include <vector>   // For using vector
#include <algorithm> // For using min_element
#include <limits>   // For using numeric_limits

using namespace std;

int main() {
    int N; // Variable to store the number of elements in the array
    long long x; // Variable to store the multiplier

    // Reading input from the console
    cin >> N >> x;

    vector<long long> srimeList(N); // Creating a vector to store the elements

    // Reading elements of the array and adding them to the vector
    for (int i = 0; i < N; i++) {
        cin >> srimeList[i];
    }

    vector<vector<long long>> costList(N, vector<long long>(N)); // Creating a 2D vector to store the cost arrays

    // Filling the cost arrays with the minimum cost for each index and each cast number
    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i]; // Setting the first element of the cost array to the original element
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N]);
        }
    }

    vector<long long> result(N); // Creating a vector to store the final result

    // Calculating the result for each index and adding it to the vector
    for (int i = 0; i < N; i++) {
        long long temp = i * x; // Multiplying the index with the multiplier
        for (long long cost : costList[i]) { // Iterating through the cost array and adding the costs
            temp += cost;
        }
        result[i] = temp;
    }

    // Printing the minimum result
    cout << *min_element(result.begin(), result.end()) << endl;

    return 0;
}

// <END-OF-CODE>
