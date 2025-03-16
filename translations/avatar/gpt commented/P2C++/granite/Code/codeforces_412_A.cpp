
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, k;
    string v;
    cin >> n >> k >> v;

    vector<string> moves;
    bool f = k - 1 < n - k;
    int m = min(k - 1, n - k);

    for (int i = 0; i < m; i++) {
        moves.push_back(f? "RIGHT" : "LEFT");
    }

    for (int i = 0; i < v.size(); i++) {
        moves.push_back("PRINT " + string(1, v[i]));
        moves.push_back(f? "LEFT" : "RIGHT");
    }

    for (int i = 0; i < moves.size() - 1; i++) {
        cout << moves[i] << endl;
    }

    return 0;
}

