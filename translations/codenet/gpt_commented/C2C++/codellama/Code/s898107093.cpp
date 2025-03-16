#include<string>
#include<iostream>
#include<cstdlib>

using namespace std;

int main() {
    // Declare pointers for storing team names and initialize scores
    string *t, *h;
    int n, taro = 0, hanako = 0, i;

    // Read the number of rounds (n) from input
    cin >> n;

    // Allocate memory for team names for both players
    t = new string[n];
    h = new string[n];
    
    // Loop through each round to read team names and calculate scores
    for (i = 0; i < n; i++) {
        // Read team names for both players
        cin >> t[i];
        cin >> h[i];
        
        // Compare team names and update scores based on the comparison
        if (t[i] < h[i]) {
            // If Hanako's team name is lexicographically smaller, she gets 3 points
            hanako += 3;
        }
        if (t[i] > h[i]) {
            // If Taro's team name is lexicographically larger, he gets 3 points
            taro += 3;
        }
        if (t[i] == h[i]) {
            // If both team names are the same, both players get 1 point
            taro += 1;
            hanako += 1;
        }
    }
    
    // Output the final scores of Taro and Hanako
    cout << taro << " " << hanako << endl;
    
    // Free the memory allocated for the pointers to team names
    delete[] t;
    delete[] h;
    
    return 0;
}

