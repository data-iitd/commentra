
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    // Read input (the first input is ignored)
    int n;
    cin >> n;

    // Read the second line of input, split it into integers and corresponding characters,
    // and create a vector of pieces where each piece is a tuple of (score, character)
    vector<tuple<int, char>> pieces;
    int score;
    char player;
    while (cin >> score >> player) {
        pieces.emplace_back(score, player);
    }

    // Call the function to calculate Bob's maximum strength and return the result
    return Bob_sMaxStrength(pieces);
}

int Bob_sMaxStrength(vector<tuple<int, char>> pieces) {
    // Initialize scores for player A and player B, and their maximum scores
    int pScore = 0, sScore = 0;
    int pMaxScore = 0, sMaxScore = 0;
    for (const auto& piece : pieces) {
        if (get<1>(piece) == 'B') {  // If the piece belongs to player B
            sScore += get<0>(piece);  // Add the score of the piece to player B's score
        }
    }
    sMaxScore = sScore;

    // Calculate maximum score for player A by iterating through pieces from the start
    for (const auto& piece : pieces) {
        if (get<1>(piece) == 'A') {  // If the piece belongs to player A
            pScore += get<0>(piece);  // Add the score of the piece to player A's score
            if (pScore > pMaxScore) {  // Update maximum score if current score exceeds it
                pMaxScore = pScore;
            }
        } else {  // If the piece belongs to player B
            pScore -= get<0>(piece);  // Subtract the score of the piece from player A's score
        }
    }

    // Calculate maximum score for player B by iterating through pieces from the end
    for (int i = pieces.size() - 1; i >= 0; i--) {
        if (get<1>(pieces[i]) == 'A') {  // If the piece belongs to player A
            sScore += get<0>(pieces[i]);  // Add the score of the piece to player B's score
            if (sScore > sMaxScore) {  // Update maximum score if current score exceeds it
                sMaxScore = sScore;
            }
        } else {  // If the piece belongs to player B
            sScore -= get<0>(pieces[i]);  // Subtract the score of the piece from player B's score
        }
    }

    // Return the maximum score between player A and player B
    return max(pMaxScore, sMaxScore);
}

