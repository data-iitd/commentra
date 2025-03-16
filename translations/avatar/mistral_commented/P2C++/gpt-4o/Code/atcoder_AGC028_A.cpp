#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Function to calculate the greatest common divisor of two integers
int gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // Define input variables N and M as integers
    int N, M;
    cin >> N >> M;

    // Comments: Get the dimensions N and M of the matrices S and T from user input

    // Initialize variables S and T as strings
    string S, T;
    cin >> S;
    cin >> T;

    // Convert strings S and T into vectors
    vector<char> list_S(S.begin(), S.end());
    vector<char> list_T(T.begin(), T.end());

    // Initialize a vector Number_i containing numbers from 0 to N-1
    vector<int> Number_i(N);
    for (int i = 0; i < N; ++i) {
        Number_i[i] = i;
    }

    // Initialize a vector Number_iMN to store the results of the division i*M/N
    vector<int> Number_iMN;
    for (int i : Number_i) {
        Number_iMN.push_back(static_cast<int>(i * M / N));
    }

    // Initialize a vector Number_j containing numbers from 0 to M-1
    vector<int> Number_j(M);
    for (int j = 0; j < M; ++j) {
        Number_j[j] = j;
    }

    // Find the common elements between Number_iMN and Number_j using set intersection
    set<int> set_Number_iMN(Number_iMN.begin(), Number_iMN.end());
    set<int> set_Number_j(Number_j.begin(), Number_j.end());
    vector<int> Kaburi_j;

    for (int j : set_Number_j) {
        if (set_Number_iMN.count(j)) {
            Kaburi_j.push_back(j);
        }
    }

    // Initialize a vector Kaburi_i to store the integer representations of the common elements
    vector<int> Kaburi_i;
    for (int j : Kaburi_j) {
        Kaburi_i.push_back(static_cast<int>(j * N / M));
    }

    // Initialize a counter variable to keep track of the current index in Kaburi_i
    int counter = 0;
    // Initialize a flag variable to indicate whether there is a mismatch between S and T
    int Flag = 0;

    // Determine the size of Kaburi_i
    int Kaburi_Size = Kaburi_i.size();

    // Iterate through each index in Kaburi_i until the end of the list
    while (counter < Kaburi_Size) {
        // Check if the corresponding elements in S and T match
        if (list_S[Kaburi_i[counter]] != list_T[Kaburi_j[counter]]) {
            // Set the flag variable to 1 if there is a mismatch
            Flag = 1;
            // Break out of the loop
            break;
        }
        // Increment the counter variable
        counter++;
    }

    // Check if there is a mismatch between S and T
    if (Flag == 1) {
        // Print -1 if there is a mismatch
        cout << -1 << endl;
    } else {
        // Calculate and print the product of N and M divided by their greatest common divisor
        cout << (N * M) / gcd(N, M) << endl;
    }

    return 0;
}

// <END-OF-CODE>
