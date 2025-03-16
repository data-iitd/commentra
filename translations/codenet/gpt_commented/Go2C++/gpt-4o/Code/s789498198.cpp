#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <string>

using namespace std;

class Scanner {
public:
    Scanner() {
        // Initialize the input stream
        input_stream = &cin;
    }

    void readLine() {
        // Read a line from input
        getline(*input_stream, line);
        stringstream ss(line);
        string word;
        words.clear();
        while (ss >> word) {
            words.push_back(word);
        }
        current_index = 0;
    }

    string next() {
        if (current_index >= words.size()) {
            readLine(); // Read a new line if current index is out of bounds
        }
        return words[current_index++];
    }

    int nextInt() {
        return stoi(next()); // Convert the next string to int
    }

    vector<int> nextInts() {
        readLine(); // Read a new line
        vector<int> res;
        for (const string& word : words) {
            res.push_back(stoi(word)); // Convert each string to int
        }
        return res; // Return the vector of integers
    }

private:
    istream* input_stream; // Input stream
    string line; // Current line
    vector<string> words; // Words in the current line
    size_t current_index; // Current index in the words vector
};

int main() {
    Scanner sc; // Initialize the scanner
    vector<int> AB = sc.nextInts(); // Read two integers from input
    int A = AB[0];
    int B = AB[1];

    // Check if the sum of A and B is even
    if ((A + B) % 2 == 0) {
        // If even, print the average
        cout << (A + B) / 2 << endl;
    } else {
        // If odd, print "IMPOSSIBLE"
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}

// <END-OF-CODE>
