
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Take input from the user
    int n;
    cin >> n;
    cin.ignore();
    // Process the input to get a tuple of (value, type) pairs for each piece
    vector<pair<int, char>> pieces;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int value;
    char type;
    while (ss >> value >> type) {
        pieces.push_back(make_pair(value, type));
    }
    // Call the Bob_sMaxStrength function with the processed pieces and return its result
    cout << Bob_sMaxStrength(pieces) << endl;
    return 0;
}

int Bob_sMaxStrength(vector<pair<int, char>> pieces) {
    // Initialize scores for both ends and their maximum scores
    int pScore = sScore = pMaxScore = sMaxScore = accumulate(pieces.begin(), pieces.end(), 0, [](int sum, pair<int, char> piece) {
        return sum + (piece.second == 'B' ? piece.first : 0);
    });
    
    // Calculate the score from the front (left to right)
    for (auto piece : pieces) {
        if (piece.second == 'A') {
            pScore += piece.first;
            if (pScore > pMaxScore) {
                pMaxScore = pScore;
            }
        } else {
            pScore -= piece.first;
        }
    }
    
    // Calculate the score from the back (right to left)
    for (auto it = pieces.rbegin(); it != pieces.rend(); it++) {
        if (it->second == 'A') {
            sScore += it->first;
            if (sScore > sMaxScore) {
                sMaxScore = sScore;
            }
        } else {
            sScore -= it->first;
        }
    }
    
    // Return the maximum score between the two ends
    if (pMaxScore > sMaxScore) {
        return pMaxScore;
    }
    return sMaxScore;
}

// 