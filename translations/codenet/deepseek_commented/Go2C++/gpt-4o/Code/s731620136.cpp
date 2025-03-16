#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// The run function reads the input, processes it, and prints the result.
int run(istream &input, ostream &output) {
    int N;
    string S;
    
    input >> N >> S;

    if (N < 4) {
        output << 0 << endl;
        return 0;
    }

    // Counts the number of 'R', 'B', and 'G' characters in S.
    int nr = 0, nb = 0, ng = 0;
    for (char c : S) {
        if (c == 'R') {
            nr++;
        } else if (c == 'B') {
            nb++;
        } else if (c == 'G') {
            ng++;
        }
    }

    // Calculates the number of triplets where the characters are all different.
    int same = 0;
    for (int a = 1; a < N; a++) {
        int i = 0;
        int j = 1 * a;
        int k = 2 * a;
        if (k >= N) {
            break;
        }
        while (k < N) {
            if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
                same++;
            }
            i++;
            j++;
            k++;
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

// <END-OF-CODE>
