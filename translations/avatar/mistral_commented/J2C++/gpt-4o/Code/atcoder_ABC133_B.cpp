#include <iostream>  // For input and output
#include <cmath>    // For square root calculation
#include <vector>   // For using vectors
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;  // Reading the number of vectors N and their dimensions D

    // Creating a 2D vector 'vectors' of size N x D to store the vectors
    vector<vector<int>> vectors(N, vector<int>(D));

    // Reading the components of each vector from user input and storing it in the 'vectors' vector
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            cin >> vectors[i][j];
        }
    }

    // Initializing the answer variable to 0
    int answer = 0;

    // Iterating through all pairs of vectors (i, j) where i < j
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            // Calculating the Euclidean distance between the vectors i and j
            int dist = 0;
            for (int d = 0; d < D; d++) {
                int x = vectors[i][d] - vectors[j][d];  // Difference between corresponding components
                dist += (x * x);  // Squaring the difference and adding to the distance
            }

            // Calculating the square root of the distance and checking if it is a perfect square
            double sq = sqrt(dist);
            answer += (fabs(sq - floor(sq)) < 0.001 ? 1 : 0);
        }
    }

    // Printing the final answer
    cout << answer << endl;

    return 0;
}

// <END-OF-CODE>
