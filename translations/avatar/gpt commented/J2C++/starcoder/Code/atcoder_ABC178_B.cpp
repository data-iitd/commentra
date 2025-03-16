#include <bits/stdc++.h>
using namespace std;

// FastReader class to handle fast input
class FastReader { 
    public:
    std::istream *stream;
    FastReader() {
        stream = new std::stringstream;
    }
    void init(std::string s) {
        delete stream;
        stream = new std::stringstream(s);
    }
    std::string next() {
        return getline(*stream, '\n').substr(0, stream->gcount() - 1);
    }
    int nextInt() {
        return std::stoi(next());
    }
    long long nextLong() {
        return std::stoll(next());
    }
    double nextDouble() {
        return std::stod(next());
    }
    long long nextLongLong() {
        return std::stoll(next());
    }
    unsigned long long nextUnsignedLongLong() {
        return std::stoull(next());
    }
};

// Method to compute (x^y) % mod using modular exponentiation
int modPower(int x, int y, int mod) { 
    int res = 1; 
    x %= mod; // Reduce x modulo mod
    if (x == 0) return 0; // If x is 0, return 0
    
    // Loop until y becomes 0
    while (y > 0) { 
        // If y is odd, multiply x with result
        if (y % 2 == 1) { 
            res = (res * x) % mod; 
        } 
        y = y >> 1; // Divide y by 2
        x = (x * x) % mod; // Square x
    } 
    return res; // Return the final result
} 

// Pair class to hold two related values
template <typename T1, typename T2>
class pair { 
    public:
    T1 first; 
    T2 second; 
    pair(T1 first, T2 second) { 
        this->first = first; 
        this->second = second; 
    } 
}; 

// Main method to execute the program
int main() { 
    FastReader in; // Create an instance of FastReader
    long long a[4]; // Array to hold four long integers
    
    // Read four long integers from input
    for (int i = 0; i < 4; i++) 
        a[i] = in.nextLong(); 
    
    // Calculate and print the maximum product of pairs from the array
    cout << max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2]))) << endl; 
    return 0; 
}

