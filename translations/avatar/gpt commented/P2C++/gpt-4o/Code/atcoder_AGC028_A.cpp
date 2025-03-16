#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // Read the values of N and M from input
    int N, M;
    cin >> N >> M;

    // Read the strings S and T from input
    string S, T;
    cin >> S >> T;

    // Create a vector of indices from 0 to N-1
    vector<int> Number_i(N);
    for (int i = 0; i < N; ++i) {
        Number_i[i] = i;
    }

    // Initialize a vector to store calculated indices
    vector<double> Number_iMN(N);

    // Calculate the scaled indices based on the ratio of M to N
    for (int i = 0; i < N; ++i) {
        Number_iMN[i] = i * static_cast<double>(M) / N;
    }

    // Create a vector of indices from 0 to M-1
    vector<int> Number_j(M);
    for (int j = 0; j < M; ++j) {
        Number_j[j] = j;
    }

    // Find the common indices between the scaled Number_iMN and Number_j
    set<int> Kaburi_j_set;
    for (int j = 0; j < M; ++j) {
        int index = static_cast<int>(Number_iMN[j]);
        if (index < M) {
            Kaburi_j_set.insert(index);
        }
    }

    // Initialize a vector to store the corresponding indices in the original range
    vector<int> Kaburi_i;

    // Calculate the corresponding indices in the original range based on Kaburi_j
    for (int j : Kaburi_j_set) {
        Kaburi_i.push_back(static_cast<int>(j * N / M));
    }

    // Initialize a counter for iteration and a flag for mismatch detection
    int counter = 0;
    int Flag = 0;

    // Get the size of the Kaburi_i list
    int Kaburi_Size = Kaburi_i.size();

    // Check if the characters at the calculated indices in S and T match
    while (counter < Kaburi_Size) {
        if (S[Kaburi_i[counter]] == T[Kaburi_j[counter]]) {
            // Characters match, continue checking
        } else {
            Flag = 1;  // Set flag if a mismatch is found
            break;  // Exit the loop on mismatch
        }
        counter++;  // Move to the next index
    }

    // Output the result based on the flag indicating if a mismatch was found
    if (Flag == 1) {
        cout << -1 << endl;  // Print -1 if there was a mismatch
    } else {
        // Print the least common multiple (LCM) of N and M
        cout << (N * M) / gcd(N, M) << endl;
    }

    return 0;
}

// <END-OF-CODE>
