
#include <bits/stdc++.h>

using namespace std;

// Function to read input
void read(istream &in, string &s) {
    in >> s;
}

// Function to print output
void print(ostream &out, string s) {
    out << s;
}

// Main function to start the program
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Variables to store the input
    string S;
    int score = 0;

    // Read the input string
    read(cin, S);

    // Iterate through each character in the string
    for (int i = 0; i < S.length(); i++) {
        char my; // Character representing my move
        char his; // Character representing his move

        // Determine my move based on the index
        my = i % 2 == 0? 'g' : 'p';

        // Read his move from the input string
        his = S.at(i);

        // Update the score based on the moves
        if (my!= his) {
            score += my == 'p'? 1 : -1;
        }
    }

    // Print the score
    print(cout, to_string(score) + "\n");
}

