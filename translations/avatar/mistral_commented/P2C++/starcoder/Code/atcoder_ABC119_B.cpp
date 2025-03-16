#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<double> x(N);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s.find("JPY")!= string::npos) {
            s.replace(s.find("JPY"), 3, "* 1.0");
        }
        if (s.find("BTC")!= string::npos) {
            s.replace(s.find("BTC"), 3, "* 380000.0");
        }
        x[i] = eval(s);
    }
    cout << accumulate(x.begin(), x.end(), 0.0) << endl;
    return 0;
}

