

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Take input from the user
    int n;
    cin >> n;
    vector<tuple<int, char>> pieces(n);
    for (int i = 0; i < n; i++) {
        int value;
        char type;
        cin >> value >> type;
        pieces[i] = make_tuple(value, type);
    }
    
    // Call the Bob_sMaxStrength function with the processed pieces and return its result
    return Bob_sMaxStrength(pieces);
}

int Bob_sMaxStrength(vector<tuple<int, char>> pieces) {
    // Initialize scores for both ends and their maximum scores
    int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0;
    for (auto piece : pieces) {
        if (get<1>(piece) == 'B') {
            pScore += get<0>(piece);
        }
    }
    pMaxScore = pScore;
    
    // Calculate the score from the front (left to right)
    for (auto piece : pieces) {
        if (get<1>(piece) == 'A') {
            pScore += get<0>(piece);
        } else {
            pScore -= get<0>(piece);
        }
        pMaxScore = max(pMaxScore, pScore);
    }
    
    // Calculate the score from the back (right to left)
    for (int i = pieces.size() - 1; i >= 0; i--) {
        if (get<1>(pieces[i]) == 'A') {
            sScore += get<0>(pieces[i]);
        } else {
            sScore -= get<0>(pieces[i]);
        }
        sMaxScore = max(sMaxScore, sScore);
    }
    
    // Return the maximum score between the two ends
    return max(pMaxScore, sMaxScore);
}

int main() {
    // Call the main function and print its result
    cout << main() << endl;
    return 0;
}

