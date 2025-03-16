#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    // Read input (the first input is ignored)
    cin.ignore();
    
    // Read the second line of input, split it into integers and corresponding characters,
    // and create a vector of pieces where each piece is a pair of (score, character)
    vector<pair<int, char>> pieces;
    for (string s; getline(cin, s); ) {
        int score;
        char character;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] =='') {
                score = stoi(s.substr(0, i));
                character = s[i + 1];
                break;
            }
        }
        pieces.push_back(make_pair(score, character));
    }
    
    // Call the function to calculate Bob's maximum strength and return the result
    return Bob_sMaxStrength(pieces);
}

int Bob_sMaxStrength(vector<pair<int, char>> pieces) {
    // Initialize scores for player A and player B, and their maximum scores
    int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0;
    for (pair<int, char> piece : pieces) {
        if (piece.second == 'B') {  // If the piece belongs to player B
            pScore += piece.first;  // Add the score of the piece to player A's score
            if (pScore > pMaxScore) {  // Update maximum score if current score exceeds it
                pMaxScore = pScore;
            }
        } else {  // If the piece belongs to player A
            pScore -= piece.first;  // Subtract the score of the piece from player A's score
    }

    // Calculate maximum score for player B by iterating through pieces from the end
    for (int i = pieces.size() - 1; i >= 0; i--) {
        if (pieces[i].second == 'B') {  // If the piece belongs to player B
            sScore += pieces[i].first;  // Add the score of the piece to player B's score
            if (sScore > sMaxScore) {  // Update maximum score if current score exceeds it
                sMaxScore = sScore;
            }
        } else {  // If the piece belongs to player A
            sScore -= pieces[i].first;  // Subtract the score of the piece from player B's score
    }

    // Return the maximum score between player A and player B
    if (pMaxScore > sMaxScore) {
        return pMaxScore;
    }
    return sMaxScore;
}

