
// +build ignore
#include <bits/stdc++.h>

using namespace std;

// Scanner struct for handling input
struct Scanner {
    istream& sc;
    Scanner(istream& sc) : sc(sc) {}
    string nextStr() {
        string s;
        sc >> s;
        return s;
    }
    int nextInt() {
        int i;
        sc >> i;
        return i;
    }
    float nextFloat() {
        float f;
        sc >> f;
        return f;
    }
    string nextRuneSlice() {
        string s;
        getline(sc, s);
        return s;
    }
    vector<int> nextIntSlice(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }
    vector<float> nextFloatSlice(int n) {
        vector<float> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextFloat();
        }
        return res;
    }
};

// run processes the input and produces output
int run(istream& input, ostream& output) {
    Scanner sc(input);
    int N = sc.nextInt();
    string S = sc.nextStr();

    // Handle case where there are no elements
    if (N == 0) {
        return 0;
    }

    // If there are fewer than 4 elements, output 0
    if (N < 4) {
        output << 0 << endl;
        return 0;
    }

    // Count occurrences of each color
    int nr = 0, nb = 0, ng = 0;
    for (char c : S) {
        if (c == 'R') {
            nr++;
        }
        if (c == 'B') {
            nb++;
        }
        if (c == 'G') {
            ng++;
        }
    }

    int same = 0; // Counter for same color combinations

    // Iterate through possible combinations of indices
    for (int a = 1; a < N; a++) {
        int i = 0, j = 1 * a, k = 2 * a;
        if (k >= N) {
            break; // Exit if index exceeds string length
        }
        for (k = k; k < N; k++) {
            // Check if the colors at the indices are different
            if (S[i]!= S[j] && S[i]!= S[k] && S[j]!= S[k]) {
                same++; // Increment same color combination counter
            }
            i++; // Move to the next index
            j++;
            k++;
        }
    }

    // Calculate total combinations of different colors
    int tot = nr * nb * ng;

    // Output the result by subtracting same combinations from total
    output << tot - same << endl;

    return 0; // Return success
}

// main function to execute the program
int main() {
    return run(cin, cout); // Run the program and exit
}

