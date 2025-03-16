#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

int Bob_sMaxStrength(const vector<tuple<int, char>>& pieces) {
    int pScore = 0, sScore = 0;
    int pMaxScore = 0, sMaxScore = 0;

    // Calculate initial score for 'B' pieces
    for (const auto& piece : pieces) {
        if (get<1>(piece) == 'B') {
            pScore += get<0>(piece);
        }
    }
    pMaxScore = pScore;

    // Calculate the score from the front (left to right)
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

    // Calculate the score from the back (right to left)
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

    // Return the maximum score between the two ends
    return max(pMaxScore, sMaxScore);
}

int main() {
    // Take input from the user
    string temp;
    getline(cin, temp); // Read the first line (not used)
    
    // Read the second line for values
    vector<tuple<int, char>> pieces;
    string values;
    getline(cin, values);
    string types;
    getline(cin, types);

    // Process the input to get a vector of (value, type) pairs for each piece
    size_t pos = 0;
    while ((pos = values.find(' ')) != string::npos) {
        int value = stoi(values.substr(0, pos));
        char type = types[pieces.size()];
        pieces.emplace_back(value, type);
        values.erase(0, pos + 1);
    }
    // Add the last piece
    if (!values.empty()) {
        int value = stoi(values);
        char type = types[pieces.size()];
        pieces.emplace_back(value, type);
    }

    // Call the Bob_sMaxStrength function with the processed pieces and return its result
    cout << Bob_sMaxStrength(pieces) << endl;

    return 0;
}

// <END-OF-CODE>
