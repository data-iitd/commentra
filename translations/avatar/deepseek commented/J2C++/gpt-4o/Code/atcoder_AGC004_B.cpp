#include <iostream> // For input and output
#include <vector>   // For using vectors
#include <algorithm> // For using min_element
#include <numeric>  // For using accumulate

using namespace std;

int main() {
    int N;
    long long x;
    cin >> N >> x; // Read the number of elements N and the cost multiplier x

    vector<long long> srimeList(N); // Create a vector to store the elements
    for (int i = 0; i < N; i++) {
        cin >> srimeList[i]; // Read N long integers and add to srimeList
    }

    vector<vector<long long>> costList(N, vector<long long>(N)); // Create a 2D vector to store costs

    // Fill costList with the minimum costs for each element in srimeList
    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i]; // Initialize the first element of the cost array
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N]);
        }
    }

    vector<long long> result(N); // Create a vector to store the final results
    for (int i = 0; i < N; i++) {
        result[i] = i * x + accumulate(costList.begin(), costList.end(), 0LL, 
            [j = i](long long sum, const vector<long long>& costArray) {
                return sum + costArray[j];
            });
    }

    // Print the minimum cost found
    cout << *min_element(result.begin(), result.end()) << endl;

    return 0;
}

// <END-OF-CODE>
