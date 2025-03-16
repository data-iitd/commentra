
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef pair<int, char> P;

int main() {
    int n;
    cin >> n;
    vector<P> pieces(n);
    for (int i = 0; i < n; i++) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    int pScore = sScore = pMaxScore = sMaxScore = accumulate(pieces.begin(), pieces.end(), 0, [](int sum, P p) { return sum + (p.second == 'B'? 0 : p.first); });
    for (int i = 0; i < n; i++) {
        if (pieces[i].second == 'A') {
            pScore += pieces[i].first;
            pMaxScore = max(pMaxScore, pScore);
        }
        else {
            pScore -= pieces[i].first;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (pieces[i].second == 'A') {
            sScore += pieces[i].first;
            sMaxScore = max(sMaxScore, sScore);
        }
        else {
            sScore -= pieces[i].first;
        }
    }
    cout << max(pMaxScore, sMaxScore) << endl;
    return 0;
}
//END-OF-CODE