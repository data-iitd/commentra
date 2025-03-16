
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Scanner struct for handling input
struct Scanner {
    string nextStr() {
        string str;
        cin >> str;
        return str;
    }

    int nextInt() {
        int i;
        cin >> i;
        return i;
    }

    float nextFloat() {
        float f;
        cin >> f;
        return f;
    }

    string nextRuneSlice() {
        string str;
        cin >> str;
        return str;
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
    Scanner sc; // Create a new scanner instance
    int N = sc.nextInt(); // Read the number of elements
    string S = sc.nextStr(); // Read the string of colors

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
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            nr++;
        }
        if (S[i] == 'B') {
            nb++;
        }
        if (S[i] == 'G') {
            ng++;
        }
    }

    int same = 0; // Counter for same color combinations

    // Iterate through possible combinations of indices
    for (int a = 1; a < N; a++) {
        int i = 0;
        int j = 1 * a;
        int k = 2 * a;
        if (k >= N) {
            break; // Exit if index exceeds string length
        }
        for (; k < N; k++) {
            // Check if the colors at the indices are different
            if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
                same++; // Increment same color combination counter
            }
            i += 1; // Move to the next index
            j += 1;
            k += 1;
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
    run(cin, cout); // Run the program and exit
    return 0;
}

