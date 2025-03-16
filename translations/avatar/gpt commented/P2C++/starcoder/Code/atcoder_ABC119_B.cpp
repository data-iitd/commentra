#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<float> x(N);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s == "JPY") {
            x[i] = 1.0;
        } else if (s == "BTC") {
            x[i] = 380000.0;
        } else {
            x[i] = stof(s);
        }
    }
    cout << accumulate(x.begin(), x.end(), 0.0) << endl;
    return 0;
}

