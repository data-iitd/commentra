
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Take input from the user
    cin.ignore();
    // Process the input to get a tuple of (value, type) pairs for each piece
    vector<pair<int, string>> pieces;
    string line;
    while (getline(cin, line)) {
        pieces.push_back(make_pair(stoi(line), line[0]));
    }
    // Call the Bob_sMaxStrength function with the processed pieces and return its result
    return Bob_sMaxStrength(pieces);
}

int Bob_sMaxStrength(vector<pair<int, string>> pieces) {
    // Initialize scores for both ends and their maximum scores
    int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0;
    for (auto piece : pieces) {
        if (piece.second == 'B') {
            pScore += piece.first;
            if (pScore > pMaxScore) {
                pMaxScore = pScore;
            }
        } else {
            sScore += piece.first;
            if (sScore > sMaxScore) {
                sMaxScore = sScore;
            }
        }
    }
    // Return the maximum score between the two ends
    if (pMaxScore > sMaxScore) {
        return pMaxScore;
    }
    return sMaxScore;
}

