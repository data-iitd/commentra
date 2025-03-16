#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

// Function to split a string into a vector of strings
vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to convert a string to an integer
int toInt(const string &s) {
    return stoi(s);
}

// Function to convert a string to a float
float toFloat(const string &s) {
    return stof(s);
}

// Function to process input and output
void Run(istream &r, ostream &w) {
    string line;
    getline(r, line);
    vector<string> parts = split(line, ' ');
    int N = toInt(parts[0]);
    int D = toInt(parts[1]);

    vector<vector<int>> lines;
    for (int i = 0; i < N; ++i) {
        getline(r, line);
        vector<string> nums = split(line, ' ');
        vector<int> lineInts;
        for (const auto &num : nums) {
            lineInts.push_back(toInt(num));
        }
        lines.push_back(lineInts);
    }

    int count = 0;
    for (const auto &line : lines) {
        int x = line[0];
        int y = line[1];
        float d = sqrt(x * x + y * y);
        if (D >= d) {
            ++count;
        }
    }

    w << count << endl;
}

int main() {
    Run(cin, cout);
    return 0;
}

