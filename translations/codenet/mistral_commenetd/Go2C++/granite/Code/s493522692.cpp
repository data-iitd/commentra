

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

// Util functions
string nextStr() {
    string s;
    getline(cin, s);
    return s;
}

int nextInt() {
    int i;
    cin >> i;
    return i;
}

// With a comment explaining what the function does:
// Scans the next token, a rune, into sc.Text() and returns it as a string.
string nextStr() {
    string s;
    getline(cin, s);
    return s;
}

int nextInt() {
    int i;
    cin >> i;
    return i;
}

// Helper functions for mathematical operations
int maxInt(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// With a comment explaining what the function does:
// Returns the maximum of two integers.
int maxInt(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int minInt(int a, int b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

// With a comment explaining what the function does:
// Returns the minimum of two integers.
int minInt(int a, int b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

int absInt(int a) {
    if (a >= 0) {
        return a;
    } else {
        return -a;
    }
}

// With a comment explaining what the function does:
// Returns the absolute value of an integer.
int absInt(int a) {
    if (a >= 0) {
        return a;
    } else {
        return -a;
    }
}

float maxFloat64(float a, float b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// With a comment explaining what the function does:
// Returns the maximum of two floating-point numbers.
float maxFloat64(float a, float b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

float minFloat64(float a, float b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

// With a comment explaining what the function does:
// Returns the minimum of two floating-point numbers.
float minFloat64(float a, float b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

int str2Int(string s) {
    int n;
    stringstream ss(s);
    ss >> n;
    return n;
}

// With a comment explaining what the function does:
// Converts a string to an integer.
int str2Int(string s) {
    int n;
    stringstream ss(s);
    ss >> n;
    return n;
}

string reverse(string s) {
    string t = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        t += s[i];
    }
    return t;
}

// With a comment explaining what the function does:
// Reverses a given string.
string reverse(string s) {
    string t = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        t += s[i];
    }
    return t;
}

int powInt(int p, int q) {
    return pow(p, q);
}

// With a comment explaining what the function does:
// Calculates 'p' raised to the power of 'q'.
int powInt(int p, int q) {
    return pow(p, q);
}

bool isPrime(int x) {
    if (x == 1) {
        return false;
    }
    if (x == 2) {
        return true;
    }
    if (x % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

// With a comment explaining what the function does:
// Checks if a given number is prime.
bool isPrime(int x) {
    if (x == 1) {
        return false;
    }
    if (x == 2) {
        return true;
    }
    if (x % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

vector<int> PrimeFactors(int n) {
    vector<int> pfs;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            pfs.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        pfs.push_back(n);
    }
    return pfs;
}

// With a comment explaining what the function does:
// Finds the prime factors of a given number.
vector<int> PrimeFactors(int n) {
    vector<int> pfs;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            pfs.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        pfs.push_back(n);
    }
    return pfs;
}

map<int, int> PrimeFactorsMap(int n) {
    map<int, int> pfs;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            pfs[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        pfs[n]++;
    }
    return pfs;
}

// With a comment explaining what the function does:
// Finds the prime factors of a given number and returns them as a map.
map<int, int> PrimeFactorsMap(int n) {
    map<int, int> pfs;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            pfs[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        pfs[n]++;
    }
    return pfs;
}

int main() {
    int n;
    cin >> n;
    return 0;
}

// With a comment explaining what the function does:
// Reads an integer from standard input and returns it.
int main() {
    int n;
    cin >> n;
    return 0;
}

string nextStr() {
    string s;
    getline(cin, s);
    return s;
}

// With a comment explaining what the function does:
// Reads a string from standard input and returns it.
string nextStr() {
    string s;
    getline(cin, s);
    return s;
}

int nextInt() {
    int n;
    cin >> n;
    return n;
}

// With a comment explaining what the function does:
// Reads an integer from standard input and returns it.
int nextInt() {
    int n;
    cin >> n;
    return n;
}

int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int maxInt(int a, int b) {
    int ma