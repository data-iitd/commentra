#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Custom scanner struct to read input
class Scanner {
private:
    istream& in;
    string buffer;
    string::size_type pos;

    void pre() {
        if (pos >= buffer.size()) {
            buffer.clear();
            getline(in, buffer);
            pos = 0;
        }
    }

public:
    Scanner(istream& is) : in(is), buffer(), pos(0) {}

    // Function to read the next word
    string next() {
        pre();
        string::size_type start = pos;
        while (pos < buffer.size() && buffer[pos] != ' ') {
            pos++;
        }
        string result = buffer.substr(start, pos - start);
        pos++; // Move past the space
        return result;
    }

    // Function to read the next line
    string nextLine() {
        pre();
        string result = buffer.substr(pos);
        pos = buffer.size();
        return result;
    }

    // Function to read the next integer
    int nextInt() {
        return stoi(next());
    }
};

int main() {
    // Initialize logger to include short file names
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Create a new scanner to read input
    Scanner sc(cin);

    // Read two integers from the input
    int x = sc.nextInt();
    int y = sc.nextInt();

    // Define an array containing three slices, each representing a group of months with the same number of days
    vector<vector<int>> a = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};

    // Iterate over the array to determine which group each of the integers belongs to
    int xt = -1, yt = -1;
    for (int i = 0; i < 3; ++i) {
        for (int n : a[i]) {
            if (x == n) {
                xt = i;
            }
            if (y == n) {
                yt = i;
            }
        }
    }

    // Compare the groups of x and y to determine if they belong to the same group
    if (xt == yt) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
