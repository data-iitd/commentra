#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    unordered_map<int, string> map;
    
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        map.insert(make_pair(i, s));
    }
    
    bool ans = true;
    unordered_map<int, string> past;
    string next = "";
    
    for (int i = 0; i < N; i++) {
        if (past.find(map.at(i)) != past.end()) {
            ans = false;
            break;
        }
        past.insert(make_pair(i, map.at(i)));
        
        if (i != 0) {
            if (next != map.at(i).substr(0, 1)) {
                ans = false;
                break;
            }
        }
        next = map.at(i).substr(map.at(i).length() - 1, map.at(i).length());
    }
    
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}

