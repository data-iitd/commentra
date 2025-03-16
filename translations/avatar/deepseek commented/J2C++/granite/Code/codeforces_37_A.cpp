

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create an instance of FastScanner to read input efficiently
    FastScanner input;

    // Read the number of integers
    int n = input.nextInt();

    // Create a unordered_map to store the frequency of each integer
    unordered_map<int, int> map;

    // Read n integers and update their counts in the hash map
    for (int i = 0; i < n; i++) {
        int val = input.nextInt();
        map[val]++;
    }

    // Initialize max to the smallest possible integer value
    int max = INT_MIN;

    // Iterate through the hash map to find the maximum count
    for (auto entry : map) {
        int value = entry.second;
        max = max(max, value);
    }

    // Print the maximum count and the size of the hash map
    cout << max << " " << map.size() << endl;

    return 0;
}

// Utility class to read input efficiently
class FastScanner {
public:
    BufferedReader br;
    stringstream ss;

    FastScanner() {
        br = BufferedReader(new InputStreamReader(cin));
    }

    string next() {
        while (ss.str().empty()) {
            string line = br.readLine();
            if (line == null) return "";
            ss = stringstream(line);
        }
        string result;
        ss >> result;
        return result;
    }

    int nextInt() {
        return stoi(next());
    }

    long nextLong() {
        return stol(next());
    }

    double nextDouble() {
        return stod(next());
    }

    string nextLine() {
        string line = br.readLine();
        if (line == null) return "";
        return line;
    }
};

// End of code