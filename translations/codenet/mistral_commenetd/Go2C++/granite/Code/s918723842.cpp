

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Scanner {
    string buf;
    int p;
    Scanner() {
        buf = "";
        p = 0;
    }
    string Next() {
        // Set the current position p to the beginning of the buffer if it's at the end.
        if (p == buf.size()) {
            getline(cin, buf);
            p = 0;
        }
        // Start index of the token in the buffer.
        int start = p;
        // Read the input until a non-whitespace character is found.
        while (p < buf.size() && buf[p] =='') {
            p++;
        }
        // Read the token, including the whitespace character if any.
        string result = buf.substr(start, p - start);
        // Increment the current position p.
        p++;
        return result;
    }
    string NextLine() {
        // Set the current position p to the beginning of the buffer if it's at the end.
        if (p == buf.size()) {
            getline(cin, buf);
            p = 0;
        }
        // Start index of the line in the buffer.
        int start = p;
        // Read the input until the end of the line is reached.
        while (p < buf.size() && buf[p]!= '\n') {
            p++;
        }
        // Read the line, including the newline character if any.
        string result = buf.substr(start, p - start);
        // Increment the current position p.
        p++;
        return result;
    }
    int NextInt() {
        // Read the next token as a string.
        string token = Next();
        // Parse the token as an integer and return the result.
        int v = stoi(token);
        return v;
    }
    int NextInt64() {
        // Read the next token as a string.
        string token = Next();
        // Parse the token as a 64-bit integer and return the result.
        int64_t v = stoll(token);
        return v;
    }
    double NextFloat() {
        // Read the next token as a string.
        string token = Next();
        // Parse the token as a floating-point number and return the result.
        double v = stod(token);
        return v;
    }
    vector<int> NextIntArray() {
        // Read the next line as a string.
        string line = NextLine();
        // Split the line into tokens using spaces as delimiters.
        vector<string> tokens = split(line, " ");
        // Parse each token as an integer and append it to the result vector.
        vector<int> result;
        for (string token : tokens) {
            int v = stoi(token);
            result.push_back(v);
        }
        return result;
    }
    vector<int64_t> NextInt64Array() {
        // Read the next line as a string.
        string line = NextLine();
        // Split the line into tokens using spaces as delimiters.
        vector<string> tokens = split(line, " ");
        // Parse each token as a 64-bit integer and append it to the result vector.
        vector<int64_t> result;
        for (string token : tokens) {
            int64_t v = stoll(token);
            result.push_back(v);
        }
        return result;
    }
    map<int, bool> NextMap() {
        // Read the next line as a string.
        string line = NextLine();
        // Split the line into tokens using spaces as delimiters.
        vector<string> tokens = split(line, " ");
        // Parse each token as an integer and create a key-value pair.
        map<int, bool> mp;
        for (string token : tokens) {
            int key = stoi(split(token, ":")[0]);
            mp[key] = true;
        }
        return mp;
    }
private:
    vector<string> split(string s, string delimiter) {
        vector<string> result;
        size_t pos = 0;
        while ((pos = s.find(delimiter))!= string::npos) {
            result.push_back(s.substr(0, pos));
            s.erase(0, pos + delimiter.length());
        }
        result.push_back(s);
        return result;
    }
};

int main() {
    Scanner sc;
    int H = sc.NextInt();
    int W = sc.NextInt();
    int N = sc.NextInt();
    int A = max(H, W);
    cout << (N + A - 1) / A << endl;
    return 0;
}

