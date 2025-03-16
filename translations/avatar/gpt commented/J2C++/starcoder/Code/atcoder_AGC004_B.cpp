#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of elements (N) and a long value (x) from input
    int N;
    long x;
    cin >> N >> x;
    
    // Initialize a list to store the prime numbers
    vector<long> srimeList(N);
    
    // Read N long values into the srimeList
    for (int i = 0; i < N; i++) {
        cin >> srimeList[i];
    }
    
    // Initialize a 2D list to store costs
    vector<vector<long>> costList(N, vector<long>(N));
    
    // Create a 2D array for costs, where each row corresponds to an element in srimeList
    for (int i = 0; i < N; i++) {
        // Set the first column of costList to the corresponding values from srimeList
        costList[i][0] = srimeList[i];
        // Calculate the minimum costs for each subsequent column
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N]);
        }
    }
    
    // Initialize a list to store the final results
    vector<long> result(N);
    
    // Calculate the result for each index based on the costs and the value of x
    for (int i = 0; i < N; i++) {
        result[i] = i * x + accumulate(costList[i].begin(), costList[i].end(), 0L);
    }
    
    // Print the minimum value from the result list
    cout << *min_element(result.begin(), result.end()) << endl;
}

