#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N, M;
    cin >> N >> M; // Read the values of N and M
    string S, T;
    cin >> S; // Read the string S
    cin >> T; // Read the string T

    vector<char> list_S(S.begin(), S.end()); // Convert string S to a vector of characters
    vector<char> list_T(T.begin(), T.end()); // Convert string T to a vector of characters

    vector<int> Number_i(N);
    for (int i = 0; i < N; ++i) {
        Number_i[i] = i; // Create a list of indices from 0 to N-1
    }

    vector<double> Number_iMN(N);
    for (int i = 0; i < N; ++i) {
        Number_iMN[i] = i * static_cast<double>(M) / N; // Calculate a new list where each element is i * M / N
    }

    vector<int> Number_j(M);
    for (int j = 0; j < M; ++j) {
        Number_j[j] = j; // Create a list of indices from 0 to M-1
    }

    set<int> Kaburi_j_set;
    for (double value : Number_iMN) {
        if (value >= 0 && value < M) {
            Kaburi_j_set.insert(static_cast<int>(value)); // Find the intersection of Number_iMN and Number_j
        }
    }

    vector<int> Kaburi_j(Kaburi_j_set.begin(), Kaburi_j_set.end());
    vector<int> Kaburi_i(Kaburi_j.size());

    for (size_t j = 0; j < Kaburi_j.size(); ++j) {
        Kaburi_i[j] = static_cast<int>(Kaburi_j[j] * N / M); // Calculate Kaburi_i
    }

    int counter = 0;
    int Flag = 0;
    int Kaburi_Size = Kaburi_i.size(); // Initialize counter and flag

    while (counter < Kaburi_Size) {
        if (list_S[Kaburi_i[counter]] != list_T[Kaburi_j[counter]]) {
            Flag = 1; // Set flag if characters do not match
            break;
        }
        counter++;
    }

    if (Flag == 1) {
        cout << -1 << endl; // If the flag is 1, print -1
    } else {
        cout << (N * M) / gcd(N, M) << endl; // Print the result of N*M divided by the GCD of N and M
    }

    return 0;
}
