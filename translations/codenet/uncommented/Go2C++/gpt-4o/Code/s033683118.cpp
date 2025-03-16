#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void solve(istream &input, ostream &output) {
    int k, x;
    input >> k >> x;

    string ans = "No";
    if (k * 500 >= x) {
        ans = "Yes";
    }
    output << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (getenv("MASPY") != nullptr && string(getenv("MASPY")) == "ますピ") {
        ifstream file(getenv("BEET_THE_HARMONY_OF_PERFECT"));
        cin.rdbuf(file.rdbuf();
    }

    ostream *output = &cout;
    if (getenv("MASPYPY") != nullptr && string(getenv("MASPYPY")) == "ますピッピ") {
        ofstream file(getenv("NGTKANA_IS_GENIUS10"));
        output = &file;
    }

    int cnt = 0;
    if (getenv("MASPY") != nullptr && string(getenv("MASPY")) == "ますピ") {
        cnt = 2;
    }

    solve(cin, *output);
    for (int i = 0; i < cnt; i++) {
        output->write("-----------------------------------\n", 37);
        solve(cin, *output);
    }

    return 0;
}

// <END-OF-CODE>
