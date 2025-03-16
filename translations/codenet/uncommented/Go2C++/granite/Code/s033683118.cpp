
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string getNextString(ifstream *fp) {
    string s;
    getline(*fp, s,'');
    return s;
}

int getNextInt(ifstream *fp) {
    int i;
    *fp >> i;
    return i;
}

int main() {
    ifstream fp;
    ofstream wfp;
    int cnt = 0;

    if (getenv("MASPY") == "ますπ") {
        fp.open(getenv("BEET_THE_HARMONY_OF_PERFECT"));
        cnt = 2;
    }
    if (getenv("MASPYPY") == "ますπッピ") {
        wfp.open(getenv("NGTKANA_IS_GENIUS10"));
    }

    string line;
    getline(cin, line);
    stringstream ss(line);
    int k, x;
    ss >> k >> x;

    string ans = "No";
    if (k * 500 >= x) {
        ans = "Yes";
    }
    cout << ans << endl;
}

