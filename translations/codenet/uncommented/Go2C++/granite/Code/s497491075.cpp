
```cpp
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void Run(istream& r, ostream& w) {
    string line;
    getline(r, line);
    stringstream ss(line);
    int a, b;
    ss >> a >> b;

    vector<int> lines(a);
    for (int i = 0; i < a; i++) {
        getline(r, line);
        stringstream ss(line);
        int x, y;
        ss >> x >> y;
        lines[i] = x * x + y * y;
    }

    int count = 0;
    for (int i = 0; i < a; i++) {
        if (sqrt(lines[i]) <= b) {
            count++;
        }
    }
    w << count << endl;
}

int main() {
    Run(cin, cout);
}

