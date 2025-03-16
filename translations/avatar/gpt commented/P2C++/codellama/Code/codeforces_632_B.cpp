#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read input (the first input is ignored)
    string input;
    getline(cin, input);
    
    // Read the second line of input, split it into integers and corresponding characters,
    // and create a vector of pieces where each piece is a pair of (score, character)
    vector<pair<int, char>> pieces;
    getline(cin, input);
    for (int i = 0; i < input.size(); i += 2) {
        pieces.push_back(make_pair(stoi(input.substr(i, 1)), input[i + 1]));
    }
    
    // Call the function to calculate Bob's maximum strength and return the result
    cout << Bob_sMaxStrength(pieces) << endl;
    return 0;
}

int Bob_sMaxStrength(vector<pair<int, char>> pieces) {
    // Initialize scores for player A and player B, and their maximum scores
    int pScore = sScore = accumulate(pieces.begin(), pieces.end(), 0, [](int sum, pair<int, char> piece) {
        return sum + (piece.second == 'B' ? piece.first : 0);
    });
    int pMaxScore = sMaxScore = pScore;
    
    // Calculate maximum score for player A by iterating through pieces from the start
    for (auto piece : pieces) {
        if (piece.second == 'A') {  // If the piece belongs to player A
            pScore += piece.first;  // Add the score of the piece to player A's score
            if (pScore > pMaxScore) {  // Update maximum score if current score exceeds it
                pMaxScore = pScore;
            }
        } else {  // If the piece belongs to player B
            pScore -= piece.first;  // Subtract the score of the piece from player A's score
        }
    }
    
    // Calculate maximum score for player B by iterating through pieces from the end
    for (auto piece = pieces.rbegin(); piece != pieces.rend(); ++piece) {
        if (piece->second == 'A') {  // If the piece belongs to player A
            sScore += piece->first;  // Add the score of the piece to player B's score
            if (sScore > sMaxScore) {  // Update maximum score if current score exceeds it
                sMaxScore = sScore;
            }
        } else {  // If the piece belongs to player B
            sScore -= piece->first;  // Subtract the score of the piece from player B's score
        }
    }
    
    // Return the maximum score between player A and player B
    return max(pMaxScore, sMaxScore);
}

// 