
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the input and split it into an array of strings
    string input[3];
    cin >> input[1] >> input[2];
    int m = stoi(input[1]);
    int s = stoi(input[2]);
    int f = s;
    
    // Initialize the maximum time and a HashMap to store the intervals
    int maxT = -1;
    map<int, vector<int>> map;
    
    // Read the intervals from the input and store them in the HashMap
    while (m > 0) {
        string mth[3];
        cin >> mth[0] >> mth[1] >> mth[2];
        int k = stoi(mth[0]);
        map.insert(pair<int, vector<int>>(k, vector<int>{stoi(mth[1]), stoi(mth[2])}));
        maxT = max(maxT, k);
        m--;
    }
    
    // Initialize a StringBuilder to build the sequence of actions
    string actions = "";
    
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
            a = map.find(t)->second[0];
            b = map.find(t)->second[1];
        }
        if (map.find(t)!= map.end() && ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b))) {
            actions += 'X';
        } else {
            actions += M;
            cur += d;
        }
        if (cur == f) break;
    }
    
    // Continue moving in the determined direction until reaching the final position
    while (cur!= f) {
        actions += M;
        cur += d;
    }
    
    // Print the sequence of actions
    cout << actions << endl;
}

