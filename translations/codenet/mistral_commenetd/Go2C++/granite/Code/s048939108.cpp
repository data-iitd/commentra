

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

// Initialize a new scanner
struct Scanner {
    char buf[1000];
    int p;
    Scanner() {
        p = 0;
        fgets(buf, sizeof(buf), stdin);
    }

    // Read the next string from the standard input
    string next() {
        p = 0;
        while (buf[p] =='') {
            p++;
        }
        int start = p;
        while (buf[p]!='') {
            p++;
        }
        string result = string(buf + start, p - start);
        p++;
        return result;
    }

    // NextLine function to read the next line as a string
    string nextLine() {
        p = 0;
        while (buf[p]!= '\n') {
            p++;
        }
        string result = string(buf, p);
        p++;
        return result;
    }

    // NextInt function to read the next integer from the standard input
    int nextInt() {
        char c;
        int v = 0;
        while ((c = buf[p++])!='') {
            v = v * 10 + (c - '0');
        }
        return v;
    }

    // NextIntArray function to read an array of integers from the standard input
    vector<int> nextIntArray() {
        vector<int> result;
        int v;
        while (true) {
            v = nextInt();
            if (v == 0) {
                break;
            }
            result.push_back(v);
        }
        return result;
    }
};

int main() {
    Scanner sc;
    string S = sc.next();
    if (S.substr(0, 5) == "YAKI") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

// Minimum function
int min(int a, int b) {
    // Determine the minimum of two integers
    if (a > b) {
        return b;
    }
    return a;
}

// Maximum function
int max(int a, int b) {
    // Determine the maximum of two integers
    if (a > b) {
        return a;
    }
    return b;
}

