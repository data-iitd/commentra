
// by syu
#include <bits/stdc++.h>
using namespace std;

// Define a custom Scanner class to read input efficiently.
class Scanner {
public:
    Scanner(std::istream& in, int max = 1048576) : in(in), buffer(max) {
        in.rdbuf()->pubsetbuf(buffer.data(), max);
        split();
    }

    string next() {
        split();
        return tokens.front();
    }

    int nextInt() {
        return stoi(next());
    }

private:
    std::istream& in;
    std::string buffer;
    std::stringstream ss;
    std::vector<std::string> tokens;

    void split() {
        std::string item;
        while (std::getline(ss, item,'')) {
            if (!item.empty()) {
                tokens.push_back(item);
            }
        }
        tokens.clear();
        ss.str(buffer);
        ss.clear();
        in >> buffer;
    }
};

int main() {
    // Initialize a global Scanner instance to read from standard input.
    Scanner in(std::cin);

    // Read two integers, n and k, from the input.
    int n = in.nextInt();
    int k = in.nextInt();

    // Check if n is divisible by k.
    if (n % k == 0) {
        // If n is divisible by k, print 0.
        cout << 0 << endl;
    } else {
        // If n is not divisible by k, print 1.
        cout << 1 << endl;
    }
}

// Helper function to print a line of output.
void Pln(std::ostream& out, std::vector<string> s) {
    for (auto& item : s) {
        out << item << " ";
    }
    out << endl;
}

// Helper function to print a line of output.
void Pln(std::vector<string> s) {
    Pln(cout, s);
}

// Helper function to print a line of output.
void Pln(std::vector<int> s) {
    vector<string> ss;
    for (auto& item : s) {
        ss.push_back(to_string(item));
    }
    Pln(ss);
}

// Helper function to print a line of output.
void Pln(int s) {
    Pln(vector<int>{s});
}

// Helper function to print a line of output.
void Pln(string s) {
    Pln(vector<string>{s});
}

// Helper function to print a line of output.
void Pln() {
    cout << endl;
}

// Translate the above C++ code to Java and end with comment "