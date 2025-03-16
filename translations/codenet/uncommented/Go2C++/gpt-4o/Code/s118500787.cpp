#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    int max = 0;

    for (size_t i = 0; i <= S.length() - T.length(); i++) {
        int c = 0;
        for (size_t j = 0; j < T.length(); j++) {
            if (S[i + j] == T[j]) {
                c++;
            }
        }
        max = std::max(max, c);
    }
    
    cout << T.length() - max << endl;
    return 0;
}

// <END-OF-CODE>
