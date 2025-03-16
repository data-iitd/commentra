#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    string input;
    cin >> input;
    
    unordered_map<char, int> dt;
    for (char i : input) {
        dt[i]++;
    }
    
    int cnt = 0;
    bool x = true;
    for (const auto& pair : dt) {
        if (pair.second % 2 != 0) {
            if (cnt < 1) {
                cnt++;
            } else {
                x = false;
                break;
            }
        }
    }
    
    if (x) {
        cout << "First" << endl;
    } else if (!x && input.length() % 2 == 0) {
        cout << "Second" << endl;
    } else if (!x && input.length() % 2 != 0) {
        cout << "First" << endl;
    }

    return 0;
}

// <END-OF-CODE>
