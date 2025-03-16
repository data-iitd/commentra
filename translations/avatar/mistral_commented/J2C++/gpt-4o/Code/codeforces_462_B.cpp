#include <iostream>  // Importing required C++ classes for input and output
#include <vector>   // Importing required C++ classes for using vectors
#include <algorithm> // Importing required C++ classes for sorting
#include <string>   // Importing required C++ classes for string manipulation

using namespace std;

class Card {  // Defining a class to represent a card
public:
    int left = 0;  // The left counter of the card

    bool operator<(const Card& other) const {  // Overloading the less-than operator for custom comparison
        return left < other.left;  // Sorting in ascending order
    }
};

int main() {
    ios::sync_with_stdio(false);  // Speeding up input/output
    cin.tie(nullptr);  // Untying cin from cout

    int n, k;  // Variables to store the number of cards and queries
    cin >> n >> k;  // Reading the number of cards and queries

    vector<Card> cards(26);  // Creating a vector of size 26 to store the cards

    string s;  // String to hold the sequence of cards
    cin >> s;  // Reading the sequence of cards

    for (char c : s) {  // Iterating through each character in the sequence
        cards[c - 'A'].left++;  // Incrementing the left counter of the corresponding card
    }

    long long ans = 0;  // Initializing the answer variable to zero
    for (int i = 0; i < k; i++) {  // Iterating through each query
        sort(cards.begin(), cards.end());  // Sorting the cards vector in ascending order of their left counters
        long long change = min(cards[25].left, k - i);  // Calculating the number of cards to be moved
        ans += change * change;  // Adding the square of the number of cards moved to the answer
        cards[25].left -= change;  // Decreasing the left counter of the highest card by the number of cards moved
        i += change - 1;  // Skipping the next i-1 cards as they will have the same left counter
    }

    cout << ans << endl;  // Writing the answer to the standard output
    return 0;  // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
