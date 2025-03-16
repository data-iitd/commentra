
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// I/O
// The Scanner struct is defined to read input efficiently.
struct Scanner {
    string str;
    int pos;

    Scanner() {
        str = "";
        pos = 0;
    }

    void readStr() {
        str = "";
        char c;
        while ((c = getchar()) != '\n') {
            str += c;
        }
    }

    void readInt() {
        str = "";
        char c;
        while ((c = getchar()) != '\n') {
            str += c;
        }
    }

    void readFloat() {
        str = "";
        char c;
        while ((c = getchar()) != '\n') {
            str += c;
        }
    }

    void readRuneSlice() {
        str = "";
        char c;
        while ((c = getchar()) != '\n') {
            str += c;
        }
    }

    void readIntSlice(int n) {
        str = "";
        char c;
        while ((c = getchar()) != '\n') {
            str += c;
        }
    }

    void readFloatSlice(int n) {
        str = "";
        char c;
        while ((c = getchar()) != '\n') {
            str += c;
        }
    }

    string nextStr() {
        string res = "";
        while (str[pos] != ' ') {
            res += str[pos];
            pos++;
        }
        pos++;
        return res;
    }

    int nextInt() {
        int res = 0;
        while (str[pos] != ' ') {
            res = res * 10 + (str[pos] - '0');
            pos++;
        }
        pos++;
        return res;
    }

    float nextFloat() {
        float res = 0;
        while (str[pos] != ' ') {
            res = res * 10 + (str[pos] - '0');
            pos++;
        }
        pos++;
        return res;
    }

    vector<string> nextRuneSlice() {
        vector<string> res;
        while (str[pos] != ' ') {
            res.push_back(str[pos]);
            pos++;
        }
        pos++;
        return res;
    }

    vector<int> nextIntSlice(int n) {
        vector<int> res;
        while (str[pos] != ' ') {
            res.push_back(str[pos] - '0');
            pos++;
        }
        pos++;
        return res;
    }

    vector<float> nextFloatSlice(int n) {
        vector<float> res;
        while (str[pos] != ' ') {
            res.push_back(str[pos] - '0');
            pos++;
        }
        pos++;
        return res;
    }
};

// The run function reads the input, processes it, and prints the result.
int run(istream& input, ostream& output) {
    Scanner sc;
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
    int nr = 0;
    int nb = 0;
    int ng = 0;
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
            i += 1;
            j += 1;
            k += 1;
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
    run(cin, cout);
    return 0;
}

