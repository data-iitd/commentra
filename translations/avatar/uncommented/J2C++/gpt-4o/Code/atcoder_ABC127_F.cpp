#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input

    priority_queue<int> pqmax; // Max-heap
    priority_queue<int, vector<int>, greater<int>> pqmin; // Min-heap
    long long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string command;
        ss >> command;

        if (command[0] == '2') {
            long long ans = min;
            ans *= pqmin.size();
            ans -= sumMin;
            long long ans1 = min;
            ans1 *= pqmax.size();
            ans1 = sumMax - ans1;
            cout << min << " " << (ans + ans1 + sumb) << "\n";
        } else {
            int in;
            ss >> in;
            long long value;
            ss >> value;
            sumb += value;

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
            }
            if (pqmin.size() < pqmax.size()) {
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

// <END-OF-CODE>
