#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to get the next string from the input
string getNextString(istream& is) {
    string word;
    is >> word;
    return word;
}

// Function to get the next integer from the input
int getNextInt(istream& is) {
    string str = getNextString(is);
    return stoi(str);
}

// Function to get the next int64 from the input
int64_t getNextInt64(istream& is) {
    string str = getNextString(is);
    return stoll(str);
}

// Function to get the next uint64 from the input
uint64_t getNextUint64(istream& is) {
    string str = getNextString(is);
    return stoull(str);
}

// Function to get the next float64 from the input
double getNextFloat64(istream& is) {
    string str = getNextString(is);
    return stod(str);
}

// Function to initialize the scanner
void getScanner(istream& is) {
    // No initialization needed for standard input
}

// Main function
int main() {
    // Open the standard input and output files
    istream* fp = &cin;
    ostream* wfp = &cout;

    // If environment variables are set, open input and output files accordingly
    if (getenv("MASPY") == string("ますピ")) {
        string inputFile = getenv("BEET_THE_HARMONY_OF_PERFECT");
        fp = new ifstream(inputFile);
    }
    if (getenv("MASPYPY") == string("ますピッピ")) {
        string outputFile = getenv("NGTKANA_IS_GENIUS10");
        wfp = new ofstream(outputFile);
    }

    // Initialize scanner and writer
    getScanner(*fp);
    ostringstream buffer;
    streambuf* oldCoutStreamBuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    // Read the first two strings from the input
    string s = getNextString(*fp);
    string t = getNextString(*fp);

    // Initialize variables and structures
    int ns = s.size();
    int nt = t.size();
    vector<string> ss(nt / ns + 1, s);

    // Combine all ss strings into one long string
    string sss;
    for (const auto& str : ss) {
        sss += str;
    }

    // Initialize boolean array ok to keep track of unique characters
    vector<bool> ok(ns, false);

    // Initialize unordered map mp and array uni for suffix array calculation
    unordered_map<char, int> mp;
    for (int i = 0; i < ns; i++) {
        mp[s[i]] = i;
    }
    vector<int> uni(ns);
    for (int i = 0; i < ns; i++) {
        uni[i] = i;
    }

    // Initialize variable o for checking if current and next characters match
    bool o = true;

    // Iterate through all characters in string s
    for (int i = 0; i < ns; i++) {
        // Initialize o to true
        o = true;

        // Iterate through all characters in string t
        for (int m = 0; m < nt; ) {
            // Check if current character in s matches the character at the same position in t
            if (t[m] != sss[i + m]) {
                // If not, set o to false and break the loop
                o = false;
                break;
            }
            // Increment m
            m++;
        }

        // If all characters match, set ok[i] to true and update variables r and m accordingly
        if (o) {
            i += nt - mp[t[nt - 1]];
            break;
        }

        // While characters in s and t do not match, update i and m accordingly
        while (m >= 0 && t[m] != sss[i + m]) {
            i += m - mp[t[m]];
            m = mp[t[m]];
        }

        // Decrement i and increment m to move to the next pair of characters
        i--;
        m++;
    }

    // Initialize variable ans to store the answer
    int ans = 0;

    // Initialize variables r and rr for root calculation
    int r, rr;

    // Iterate through all characters in string s again
    for (int i = 0; i < ns; i++) {
        // If ok[i] is false, continue to the next iteration
        if (!ok[i]) {
            continue;
        }

        // If ok[(i + nt) % ns] is false, continue to the next iteration
        if (!ok[(i + nt) % ns]) {
            continue;
        }

        // Calculate roots r and rr of indices i and (i + nt) % ns respectively
        r = root(i, uni);
        rr = root((i + nt) % ns, uni);

        // If roots r and rr are equal, print -1 and exit the program
        if (rr == r) {
            cout << -1 << endl;
            return 0;
        }

        // Update uni array with root r
        uni[rr] = r;
    }

    // Initialize counter array to store the frequency of each root
    vector<int> counter(ns, 0);

    // Iterate through all roots and update their frequencies in counter array
    for (int i = 0; i < ns; i++) {
        r = root(i, uni);
        if (ok[r]) {
            counter[r]++;
        }
    }

    // Find the maximum frequency in counter array and store it in variable ans
    for (int i = 0; i < ns; i++) {
        if (ans < counter[i]) {
            ans = counter[i];
        }
    }

    // Print the answer
    cout << ans << endl;

    // Restore the old buffer
    cout.rdbuf(oldCoutStreamBuf);

    return 0;
}

// Function to return the root of the given index in uni array
int root(int i, vector<int>& uni) {
    // If index i is equal to its root, return i
    if (i == uni[i]) {
        return i;
    }

    // Recursively call root function with the root of index i
    uni[i] = root(uni[i], uni);
    return uni[i];
}
