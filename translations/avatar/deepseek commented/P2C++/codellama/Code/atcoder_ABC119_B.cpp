
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<double> x;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        stringstream ss(s);
        double d;
        ss >> d;
        if (ss.fail()) {
            string t;
            ss >> t;
            if (t == "JPY") {
                d *= 1.0;
            } else if (t == "BTC") {
                d *= 380000.0;
            }
        }
        x.push_back(d);
    }
    double sum = 0.0;
    for (int i = 0; i < x.size(); i++) {
        sum += x[i];
    }
    cout << sum << endl;
    return 0;
}

