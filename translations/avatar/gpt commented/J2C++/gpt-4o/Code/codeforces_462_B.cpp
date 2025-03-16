#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class c462b {
public:
    int left = 0; // Count of letters left

    bool operator<(const c462b& other) const {
        return left < other.left; // Compare based on the count of letters
    }
};

int main() {
    // Initialize input and output streams
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the first line of input to extract n and k
    int n, k;
    cin >> n >> k;

    // Create a vector of c462b objects to count occurrences of each letter
    vector<c462b> cards(26); 

    // Read the string of cards and count the occurrences of each letter
    string s;
    cin >> s; 
    for (char c : s) {
        cards[c - 'A'].left++; // Increment the count for the corresponding letter
    }

    long long ans = 0; // Variable to store the final answer

    // Perform k operations to maximize the score
    for (int i = 0; i < k; i++) {
        sort(cards.begin(), cards.end()); // Sort the cards based on the count of letters

        // Determine the number of changes to make for the most frequent letter
        long long change = min(cards[25].left, k - i); 
        ans += change * change; // Update the answer with the square of changes

        // Decrease the count of the most frequent letter by the number of changes made
        cards[25].left -= change; 
        i += change - 1; // Adjust the loop counter based on changes made
    }

    // Output the final result
    cout << ans << endl; 

    return 0; // End of the program
}

// <END-OF-CODE>
