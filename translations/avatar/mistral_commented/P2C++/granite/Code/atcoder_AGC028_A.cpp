
#####
# Code
#####

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Define input variables N and M as integers
    int N, M;
    cin >> N >> M;

    // Comments: Get the dimensions N and M of the matrices S and T from user input

    // Initialize variables S and T as strings
    string S, T;
    cin >> S >> T;

    // Convert strings S and T into vectors of characters
    vector<char> list_S(S.begin(), S.end());
    vector<char> list_T(T.begin(), T.end());

    // Initialize a vector Number_i containing numbers from 0 to N-1
    vector<int> Number_i(N);
    for (int i = 0; i < N; i++) {
        Number_i[i] = i;
    }

    // Initialize a vector Number_j containing numbers from 0 to M-1
    vector<int> Number_j(M);
    for (int j = 0; j < M; j++) {
        Number_j[j] = j;
    }

    // Find the common elements between Number_i and Number_j using set intersection
    vector<int> Kaburi_j;
    set_intersection(Number_i.begin(), Number_i.end(), Number_j.begin(), Number_j.end(), back_inserter(Kaburi_j));

    // Initialize a vector Kaburi_i to store the integer representations of the common elements
    vector<int> Kaburi_i;
    for (int j : Kaburi_j) {
        Kaburi_i.push_back(j * N / M);
    }

    // Initialize a counter variable to keep track of the current index in Kaburi_i
    int counter = 0;

    // Initialize a flag variable to indicate whether there is a mismatch between S and T
    bool Flag = false;

    // Determine the size of Kaburi_i
    int Kaburi_Size = Kaburi_i.size();

    // Iterate through each index in Kaburi_i until the end of the list
    while (counter <= Kaburi_Size - 1) {
        // Check if the corresponding elements in S and T match
        if (list_S[Kaburi_i[counter]]!= list_T[Kaburi_j[counter]]) {
            // Set the flag variable to true if there is a mismatch
            Flag = true;
            // Break out of the loop
            break;
        }
        // Increment the counter variable
        counter++;
    }

    // Define a function gcd(a, b) to calculate the greatest common divisor of two integers
    int gcd(int a, int b) {
        // While b is not equal to 0, keep updating a and b using the modulo operator
        while (b > 0) {
            a = b;
            b = a % b;
        }
        // Return the final value of a as the greatest common divisor
        return a;
    }

    // Check if there is a mismatch between S and T
    if (Flag) {
        // Print -1 if there is a mismatch
        cout << -1 << endl;
    } else {
        // Calculate and print the product of N and M divided by their greatest common divisor
        cout << int(N * M / gcd(N, M)) << endl;
    }

    return 0;
}
