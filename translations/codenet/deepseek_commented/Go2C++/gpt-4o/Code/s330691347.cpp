#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Data represents a structure holding a string.
struct Data {
    string X;
};

// The main function reads N strings, sorts them, and prints the concatenated result.
int main() {
    int N, L;
    cin >> N >> L;
    vector<Data> s(N);

    for (int i = 0; i < N; i++) {
        cin >> s[i].X;
    }

    // Sort the vector of Data structures based on the string values.
    sort(s.begin(), s.end(), [](const Data &a, const Data &b) {
        return a.X < b.X;
    });

    string ans = "";
    for (int i = 0; i < N; i++) {
        ans += s[i].X;
    }
    
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
