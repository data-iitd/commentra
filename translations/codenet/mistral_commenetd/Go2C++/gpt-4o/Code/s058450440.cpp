#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

vector<int> a;
int ans = 0;

// Function to perform Depth First Search (DFS) algorithm
void dfs(int left, int i, int res) {
    if (left == 0) {
        ans += res;
        return;
    }

    for (int j = i; j < a.size(); j++) {
        dfs(left - 1, j + 1, res * a[j]);
    }
}

// Main function definition
int main() {
    int n;
    cin >> n; // Reading the number of test cases

    map<char, int> dic; // Initializing a map to store the frequency of each character

    // Reading strings and updating the map
    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;
        if (c[0] == 'M' || c[0] == 'A' || c[0] == 'R' || c[0] == 'C' || c[0] == 'H') {
            dic[c[0]]++;
        }
    }

    // Converting map values to integers and appending them to the 'a' vector
    for (const auto& pair : dic) {
        a.push_back(pair.second);
    }

    // Calling the 'dfs' function with initial arguments
    dfs(3, 0, 1);

    // Printing the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
