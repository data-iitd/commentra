#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Minimum function
int min(int a, int b) {
    // Determine the minimum of two integers
    return a < b ? a : b;
}

// Maximum function
int max(int a, int b) {
    // Determine the maximum of two integers
    return a > b ? a : b;
}

// Scanner structure definition
class Scanner {
public:
    Scanner(istream& is) : is_(is) {}

    // Next function to read the next token as a string
    string next() {
        string token;
        is_ >> token;
        return token;
    }

    // NextLine function to read the next line as a string
    string nextLine() {
        string line;
        getline(is_, line);
        return line;
    }

    // NextInt function to read the next integer from the standard input
    int nextInt() {
        int value;
        is_ >> value;
        return value;
    }

    // NextIntArray function to read an array of integers from the standard input
    vector<int> nextIntArray() {
        string line;
        getline(is_, line);
        vector<int> result;
        stringstream ss(line);
        int value;
        while (ss >> value) {
            result.push_back(value);
        }
        return result;
    }

private:
    istream& is_;
};

int main() {
    Scanner sc(cin);

    // Read the first string from the standard input
    string S = sc.next();

    // Check if the string starts with "YAKI"
    if (S.substr(0, 4) == "YAKI") {
        cout << "Yes" << endl; // Print "Yes" if the condition is true
    } else {
        cout << "No" << endl; // Print "No" if the condition is false
    }

    return 0;
}

