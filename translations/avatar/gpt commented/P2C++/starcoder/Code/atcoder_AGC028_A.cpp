#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Read the values of N and M from input
    int N, M;
    cin >> N >> M;

    // Read the strings S and T from input
    string S, T;
    cin >> S >> T;

    // Convert strings S and T into lists for easier indexing
    vector<char> list_S(S.begin(), S.end());
    vector<char> list_T(T.begin(), T.end());

    // Create a list of indices from 0 to N-1
    vector<int> Number_i(N);
    for (int i = 0; i < N; i++) {
        Number_i[i] = i;
    }

    // Initialize an empty list to store calculated indices
    vector<int> Number_iMN;

    // Calculate the scaled indices based on the ratio of M to N
    for (int i = 0; i < N; i++) {
        Number_iMN.push_back(i * M / N);
    }

    // Create a list of indices from 0 to M-1
    vector<int> Number_j(M);
    for (int j = 0; j < M; j++) {
        Number_j[j] = j;
    }

    // Find the common indices between the scaled Number_iMN and Number_j
    vector<int> Kaburi_j;
    for (int j = 0; j < M; j++) {
        if (Number_j[j] in Number_iMN) {
            Kaburi_j.push_back(j);
        }
    }

    // Initialize an empty list to store the corresponding indices in the original range
    vector<int> Kaburi_i;

    // Calculate the corresponding indices in the original range based on Kaburi_j
    for (int j = 0; j < Kaburi_j.size(); j++) {
        Kaburi_i.push_back(int(Kaburi_j[j] * N / M));
    }

    // Initialize a counter for iteration and a flag for mismatch detection
    int counter = 0;
    int Flag = 0;

    // Get the size of the Kaburi_i list
    int Kaburi_Size = Kaburi_i.size();

    // Check if the characters at the calculated indices in S and T match
    while (counter <= Kaburi_Size - 1) {
        if (list_S[Kaburi_i[counter]] == list_T[Kaburi_j[counter]]) {
            // Characters match, continue checking
            counter++;
        } else {
            // Set flag if a mismatch is found
            Flag = 1;
            break;
        }
    }

    // Function to calculate the greatest common divisor (GCD) of two numbers
    int gcd(int a, int b) {
        while (b > 0) {
            a = b;
            b = a % b;
        }
        return a;
    }

    // Output the result based on the flag indicating if a mismatch was found
    if (Flag == 1) {
        // Print -1 if there was a mismatch
        cout << -1 << endl;
    } else {
        // Print the least common multiple (LCM) of N and M
        cout << int(N * M / gcd(N, M)) << endl;
    }

    return 0;
}

