#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int I() {
    int x;
    cin >> x;
    return x;
}

vector<int> LI() {
    string line;
    getline(cin, line);
    vector<int> numbers;
    stringstream ss(line);
    int number;
    while (ss >> number) {
        numbers.push_back(number);
    }
    return numbers;
}

string main() {
    int N = I();
    vector<int> S = LI();
    sort(S.begin(), S.end(), greater<int>());
    vector<bool> flag(S.size(), true);
    vector<int> cur;
    cur.push_back(S[0]);
    flag[0] = false;
    for (int i = 0; i < N; ++i) {
        int j = 0;
        int jM = cur.size();
        for (int k = 0; k < S.size(); ++k) {
            if (flag[k] && S[k] < cur[j]) {
                cur.push_back(S[k]);
                j++;
                flag[k] = false;
                if (j == jM) {
                    break;
                }
            }
        }
        if (j == jM) {
            return "No";
        }
        sort(cur.begin(), cur.end(), greater<int>());
    }
    return "Yes";
}

int main() {
    cout << main() << endl;
    return 0;
}
