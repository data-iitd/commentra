#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

int Bob_sMaxStrength(const vector<tuple<int, char>>& pieces) {
    int pScore = 0, sScore = 0;
    int pMaxScore = 0, sMaxScore = 0;

    for (const auto& piece : pieces) {
        if (get<1>(piece) == 'B') {
            pScore += get<0>(piece);
        }
    }
    pMaxScore = pScore;

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

    return (pMaxScore > sMaxScore) ? pMaxScore : sMaxScore;
}

int main() {
    int n;
    cin >> n; // Read the number of pieces
    vector<tuple<int, char>> pieces(n);

    for (int i = 0; i < n; ++i) {
        int strength;
        char type;
        cin >> strength >> type;
        pieces[i] = make_tuple(strength, type);
    }

    cout << Bob_sMaxStrength(pieces) << endl;

    return 0;
}

// <END-OF-CODE>
