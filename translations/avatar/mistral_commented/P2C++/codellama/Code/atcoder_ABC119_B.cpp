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
        string input;
        cin >> input;

        stringstream ss(input);
        string token;
        double value = 0.0;
        while (ss >> token) {
            if (token == "JPY") {
                value *= 1.0;
            } else if (token == "BTC") {
                value *= 380000.0;
            } else {
                value = stod(token);
            }
        }

        x.push_back(value);
    }

    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += x[i];
    }

    cout << sum << endl;

    return 0;
}

