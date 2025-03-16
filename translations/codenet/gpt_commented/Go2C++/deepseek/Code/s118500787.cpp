#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string ReadString() {
    string s;
    getline(cin, s);
    return s;
}

int main() {
    string S = ReadString();
    string T = ReadString();
    
    int max = 0;
    
    for (size_t i = 0; i <= S.size() - T.size(); i++) {
        int c = 0;
        
        for (size_t j = 0; j < T.size(); j++) {
            if (S[i + j] == T[j]) {
                c++;
            }
        }
        
        if (max < c) {
            max = c;
        }
    }
    
    cout << T.size() - max << endl;
    
    return 0;
}

