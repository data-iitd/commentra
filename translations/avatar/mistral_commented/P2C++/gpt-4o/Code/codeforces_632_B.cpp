#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>

using namespace std;

// Function to calculate Bob's maximum strength based on the given pieces
int Bob_sMaxStrength(const vector<pair<int, char>>& pieces) {
    int p_score = 0, s_score = 0;
    int p_max_score = 0, s_max_score = 0;

    // Iterate through each piece and update the scores accordingly
    for (const auto& piece : pieces) {
        // If the piece belongs to player A, add its score to p_score
        if (piece.second == 'A') {
            p_score += piece.first;
            // Update p_max_score if the current p_score is greater
            if (p_score > p_max_score) {
                p_max_score = p_score;
            }
        } else { // If the piece belongs to player B
            p_score -= piece.first;
        }
    }

    // Iterate through the pieces in reverse order and update the scores for player S
    for (int i = pieces.size() - 1; i >= 0; --i) {
        // If the current piece belongs to player A, add its score to s_score
        if (pieces[i].second == 'A') {
            s_score += pieces[i].first;
            // Update s_max_score if the current s_score is greater
            if (s_score > s_max_score) {
                s_max_score = s_score;
            }
        } else { // If the current piece belongs to player B
            s_score -= pieces[i].first;
        }
    }

    // Return the maximum score between Bob's and Sally's scores
    return max(p_max_score, s_max_score);
}

// This function is the entry point of the program
int main() {
    // Read input from standard input
    string line;
    getline(cin, line); // Read the first line (not used)

    // Read the second line and parse it into a vector of pairs
    getline(cin, line);
    istringstream iss(line);
    vector<pair<int, char>> pieces;
    int score;
    char player;

    while (iss >> score >> player) {
        pieces.emplace_back(score, player);
    }

    // Call the function to find Bob's maximum strength
    int result = Bob_sMaxStrength(pieces);

    // Print the result
    cout << result << endl;

    return 0;
}

// <END-OF-CODE>
