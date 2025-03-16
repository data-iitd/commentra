#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Read the number of vectors (N) and the dimension (D)
    int N, D;
    cin >> N >> D;

    // Initialize the vector to store the vectors
    vector<vector<int>> vectors(N, vector<int>(D));

    // Read each vector's components from the input
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            cin >> vectors[i][j];
        }
    }

    // Initialize the answer variable
    int answer = 0;

    // Calculate the Euclidean distance between each pair of vectors
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int dist = 0;
            for (int d = 0; d < D; d++) {
                int x = (vectors[i][d] - vectors[j][d]);
                dist += (x * x);
            }
            double sq = sqrt(dist);
            // Check if the distance is an integer and increment the answer if it is
            answer += (fabs(sq - floor(sq)) < 0.001 ? 1 : 0);
        }
    }

    // Print the answer
    cout << answer << endl;

    return 0;
}

// <END-OF-CODE>
