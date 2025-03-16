
// +build ignore
#include <bits/stdc++.h>

using namespace std;

// I/O
// The Scanner struct is defined to read input efficiently.
struct Scanner {
    istream& sc;

    Scanner(istream& in) : sc(in) {}

    // Reads the next word from the input and returns it as a string.
    string nextStr() {
        string res;
        sc >> res;
        return res;
    }

    // Reads the next word, converts it to an integer, and returns it.
    int nextInt() {
        int res;
        sc >> res;
        return res;
    }

    // Reads the next word, converts it to a float64, and returns it.
    double nextFloat() {
        double res;
        sc >> res;
        return res;
    }

    // Reads the next word and returns it as a byte slice.
    string nextRuneSlice() {
        return nextStr();
    }

    // Reads `n` integers from the input and returns them as a slice.
    vector<int> nextIntSlice(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    // Reads `n` floats from the input and returns them as a slice.
    vector<double> nextFloatSlice(int n) {
        vector<double> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextFloat();
        }
        return res;
    }
};

// The run function reads the input, processes it, and prints the result.
int run(istream& input, ostream& output) {
    Scanner sc(input);
    // Reads the number of elements N and the string S.
    int N = sc.nextInt();
    string S = sc.nextStr();

    if (N == 0) {
    }

    if (N < 4) {
        output << 0 << endl;
        return 0;
    }

    // Counts the number of 'R', 'B', and 'G' characters in S.
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

    // Calculates the number of triplets where the characters are all different.
    int same = 0;
    for (int a = 1; a < N; a++) {
        int i = 0, j = a, k = 2 * a;
        if (k >= N) {
            break;
        }
        for (; k < N; i++, j++, k++) {
            if (S[i]!= S[j] && S[i]!= S[k] && S[j]!= S[k]) {
                same++;
            }
        }
    }

    // Calculates the total number of possible triplets.
    int tot = nr * nb * ng;

    // Prints the difference between the total number of possible triplets and the number of triplets with all different characters.
    output << tot - same << endl;

    return 0;
}

// The main function calls the run function with standard input and output, and exits with the return value of run.
int main() {
    return run(cin, cout);
}

