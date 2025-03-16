
#include <iostream> // Include the necessary libraries
#include <vector> // Include the necessary libraries
#include <algorithm> // Include the necessary libraries

using namespace std; // Use the standard namespace

int main() {
    int N, x; // Declare the variables N and x
    cin >> N >> x; // Read the input values N and x

    vector<long long> srimeList(N); // Create a vector to store the elements
    for (int i = 0; i < N; i++) {
        cin >> srimeList[i]; // Read N long integers and store in srimeList
    }

    vector<vector<long long>> costList(N, vector<long long>(N)); // Create a 2D vector to store costs
    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i]; // Initialize the first element of each row in costList
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N]);
        }
    }

    vector<long long> result(N); // Create a vector to store the final results
    for (int i = 0; i < N; i++) {
        result[i] = i * x + accumulate(costList[i].begin(), costList[i].end(), 0LL); // Calculate the minimum cost for each element in srimeList
    }

    // Print the minimum cost found
    cout << *min_element(result.begin(), result.end()) << endl; // Print the minimum cost found

    return 0; // Return 0 to indicate successful execution
}

