#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int nextInt() {
    int n;
    cin >> n;
    return n;
}

vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int min(int i, int j) {
    return i < j ? i : j;
}

int main() {
    int n = nextInt();
    int rt = static_cast<int>(sqrt(n));
    int minf = 100;
    for (int i = 1; i < rt + 1; i++) {
        if (n % i == 0) {
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            minf = min(minf, ndigit);
        }
    }
    cout << minf << endl;
    return 0;
}
