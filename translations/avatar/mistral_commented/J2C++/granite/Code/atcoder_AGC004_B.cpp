
#include <iostream> // Including theiostream library for input/output operations
#include <vector> // Including the vector library for dynamic arrays
#include <algorithm> // Including the algorithm library for sorting and searching operations

using namespace std; // Using the standard namespace

int main() {
    int N; // Variable to store the number of elements in the array
    long x; // Variable to store the multiplier

    // Reading input from the console
    cin >> N >> x;

    vector<long> srimeList(N); // Creating a vector of size N to store the elements

    // Reading elements of the array and adding them to the vector
    for (int i = 0; i < N; i++) {
        cin >> srimeList[i];
    }

    vector<vector<long>> costList(N, vector<long>(N)); // Creating a 2D vector to store the cost arrays

    // Filling the cost arrays with the minimum cost for each index and each cast number
    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i]; // Setting the first element of the cost array to the original element
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N]);
        }
    }

    vector<long> result(N); // Creating a vector to store the final result

    // Calculating the result for each index and adding it to the vector
    for (int i = 0; i < N; i++) {
        long temp = i * x; // Multiplying the index with the multiplier
        for (int j = 0; j < N; j++) { // Iterating through the cost array and adding the costs
            temp += costList[i][j];
        }
        result[i] = temp;
    }

    // Printing the minimum result
    cout << *min_element(result.begin(), result.end()) << endl; // Using the min_element function from the algorithm library to find the minimum element in the result vector

    return 0; // Returning 0 to indicate successful execution of the program
}

