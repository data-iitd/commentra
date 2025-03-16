

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create a BufferedReader to read input from the standard input
    BufferedReader reader(new InputStreamReader(System.in));
    
    // Read the input and split it into an array of strings
    string input;
    getline(cin, input);
    vector<string> tokens;
    stringstream ss(input);
    string token;
    while (getline(ss, token,'')) {
        tokens.push_back(token);
    }
    
    // Parse the required integers from the input
    int m = stoi(tokens[1]);
    int s = stoi(tokens[2]);
    int f = stoi(tokens[3]);
    
    // Initialize the maximum time and a HashMap to store the intervals
    int maxT = -1;
    unordered_map<int, vector<int>> map;
    
    // Read the intervals from the input and store them in the HashMap
    while (m > 0) {
        getline(cin, input);
        tokens.clear();
        ss = stringstream(input);
        while (getline(ss, token,'')) {
            tokens.push_back(token);
        }
        int k = stoi(tokens[0]);
        map[k] = {stoi(tokens[1]), stoi(tokens[2])};
        maxT = max(maxT, k);
        m--;
    }
    
    // Initialize a StringBuilder to build the sequence of actions
    stringstream actions;
    
    // Determine the direction of movement and initialize the current position
    char M = (s < f)? 'R' : 'L';
    int d = (s < f)? +1 : -1;
    int cur = s;
    
    // Variables to store the current interval's start and end
    int a = -1;
    int b = -1;
    
    // Build the sequence of actions based on the intervals and the current position
    for (int t = 1; t <= maxT; t++) {
        if (map.find(t)!= map.end()) {
            a = map[t][0];
            b = map[t][1];
        }
        if (map.find(t)!= map.end() && ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b))) {
            actions << 'X';
        } else {
            actions << M;
            cur += d;
        }
        if (cur == f) break;
    }
    
    // Continue moving in the determined direction until reaching the final position
    while (cur!= f) {
        actions << M;
        cur += d;
    }
    
    // Print the sequence of actions
    cout << actions.str() << endl;
    
    return 0;
}

