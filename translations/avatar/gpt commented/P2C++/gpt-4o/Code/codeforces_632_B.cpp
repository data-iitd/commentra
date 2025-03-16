#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <sstream>

using namespace std;

int Bob_sMaxStrength(const vector<tuple<int, char>>& pieces) {
    int pScore = 0, sScore = 0;
    int pMaxScore = 0, sMaxScore = 0;

    // Calculate initial score for player B
    for (const auto& piece : pieces) {
        if (get<1>(piece) == 'B') {
            pScore += get<0>(piece);
        }
    }
    pMaxScore = pScore;

    // Calculate maximum score for player A
    for (const auto& piece : pieces) {
        if (get<1>(piece) == 'A') {
            pScore += get<0>(piece);
            if (pScore > pMaxScore) {
                pMaxScore = pScore;
            }
        } else {
            pScore -= get<0>(piece);
        }
    }

    // Calculate maximum score for player B
    for (int i = pieces.size() - 1; i >= 0; --i) {
        if (get<1>(pieces[i]) == 'A') {
            sScore += get<0>(pieces[i]);
            if (sScore > sMaxScore) {
                sMaxScore = sScore;
            }
        } else {
            sScore -= get<0>(pieces[i]);
        }
    }

    // Return the maximum score between player A and player B
    return max(pMaxScore, sMaxScore);
}

int main() {
    // Read input (the first input is ignored)
    string ignore;
    getline(cin, ignore);

    // Read the second line of input
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<tuple<int, char>> pieces;
    int score;
    string characters;

    // Read scores and characters
    while (ss >> score) {
        pieces.emplace_back(score, ' '); // Placeholder for character
    }
    getline(cin, characters);

    // Assign characters to the pieces
    for (size_t i = 0; i < pieces.size(); ++i) {
        get<1>(pieces[i]) = characters[i];
    }

    // Call the function to calculate Bob's maximum strength and return the result
    cout << Bob_sMaxStrength(pieces) << endl;

    return 0;
}

// <END-OF-CODE>
