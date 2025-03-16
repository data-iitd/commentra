
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a Scanner object to read input from the user
    // Read the number of vectors (N) and their dimensionality (D)
    int N, D;
    cin >> N >> D;

    // Initialize a 2D vector to store the vectors
    vector<vector<int>> vectors(N, vector<int>(D));

    // Read each vector's components from the input
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            cin >> vectors[i][j];
        }
    }

    // Initialize a counter for the number of pairs with integer distances
    int answer = 0;

    // Calculate the pairwise distances between all vectors
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int dist = 0;

            // Calculate the squared distance between vector i and vector j
            for (int d = 0; d < D; d++) {
                int x = (vectors[i][d] - vectors[j][d]);
                dist += (x * x);
            }

            // Calculate the Euclidean distance
            double sq = sqrt(dist);

            // Check if the distance is an integer (within a small epsilon)
            answer += (abs(sq - floor(sq)) < 0.001? 1 : 0);
        }
    }

    // Output the total count of pairs with integer distances
    cout << answer << endl;

    return 0;
}
