#include <iostream> // Including iostream for input/output
#include <vector>   // Including vector for dynamic array
#include <cmath>    // Including cmath for sqrt function

using namespace std;

int main() {
    int N;
    cin >> N; // Reading the number of points
    vector<vector<int>> pos(N, vector<int>(2)); // Initializing a 2D vector to store coordinates

    // Reading coordinates of points
    for (int i = 0; i < N; i++) {
        cin >> pos[i][0]; // Reading x-coordinate
        cin >> pos[i][1]; // Reading y-coordinate
    }

    double sum = 0; // Initializing sum to store the total distance

    // Calculating the sum of distances between all pairs of points
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue; // Skipping the diagonal elements
            sum += sqrt(pow(pos[i][0] - pos[j][0], 2) + pow(pos[i][1] - pos[j][1], 2)); // Adding distance to sum
        }
    }

    // Calculating and printing the average distance
    cout << sum / N << endl;

    return 0;
}

// <END-OF-CODE>
