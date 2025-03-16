#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after reading the integer

    priority_queue<int> pqmax; // Max Heap to store the maximum elements
    priority_queue<int, vector<int>, greater<int>> pqmin; // Min Heap to store the minimum elements
    long long sumMin = 0, sumMax = 0, sumb = 0; // Variables to store the sum of minimum and maximum elements and the sum of the current element
    int min = 0; // Variable to store the minimum element

    while (t--) {
        string s;
        getline(cin, s);
        vector<string> tokens;
        string token;
        for (char c : s) {
            if (c == ' ') {
                tokens.push_back(token);
                token.clear();
            } else {
                token += c;
            }
        }
        tokens.push_back(token);

        if (tokens[0][0] == '2') {
            long long ans = min;
            ans *= pqmin.size();
            ans -= sumMin;
            long long ans1 = min;
            ans1 = sumMax - ans1;
            cout << min << " " << (ans + ans1 + sumb) << "\n";
        } else {
            int in = stoi(tokens[1]);
            sumb += stoll(tokens[2]);

            if (in > min) {
                pqmax.push(in);
                sumMax += in;
            } else {
                pqmin.push(in);
                sumMin += in;
            }

            if (pqmin.size() > pqmax.size()) {
                sumMax += pqmin.top();
                sumMin -= pqmin.top();
                pqmax.push(pqmin.top());
                pqmin.pop();
            } else if (pqmin.size() < pqmax.size()) {
                sumMax -= pqmax.top();
                sumMin += pqmax.top();
                pqmin.push(pqmax.top());
                pqmax.pop();
            }

            min = pqmin.top();
        }
    }

    return 0;
}
