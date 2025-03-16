#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

int absint(int a) {
    return a < 0 ? -a : a;
}

int main(int argc, char* argv[]) {
    ifstream inputFile;
    if (argc > 1) {
        inputFile.open(argv[1]);
    }
    istream& input = (argc > 1) ? inputFile : cin;

    int n;
    input >> n;

    vector<int> aa(n + 2);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        input >> aa[i + 1];
        sum += absint(aa[i + 1] - aa[i]);
    }
    sum += absint(aa[n + 1] - aa[n]);

    for (int i = 1; i < n + 1; i++) {
        int ans = sum - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1]);
        cout << ans << endl;
    }

    if (inputFile.is_open()) {
        inputFile.close();
    }

    return 0;
}

// <END-OF-CODE>
