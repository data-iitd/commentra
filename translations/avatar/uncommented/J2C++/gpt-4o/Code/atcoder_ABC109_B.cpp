#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    unordered_map<int, string> map;
    
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        map[i] = input;
    }
    
    bool ans = true;
    unordered_map<int, string> past;
    string next = "";
    
    for (int i = 0; i < N; i++) {
        if (past.count(i) > 0 && past.find(i)->second == map[i]) {
            ans = false;
            break;
        }
        past[i] = map[i];
        
        if (i != 0) {
            if (next != map[i].substr(0, 1)) {
                ans = false;
                break;
            }
        }
        
        next = map[i].substr(map[i].length() - 1, 1);
    }
    
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}

// <END-OF-CODE>
