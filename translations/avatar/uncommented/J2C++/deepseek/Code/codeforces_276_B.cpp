#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    string str;
    unordered_map<char, int> map;
    int oddCount = 0;

    getline(cin, str);

    for (char ch : str) {
        map[ch]++;
    }

    for (auto& entry : map) {
        if (entry.second % 2 != 0) {
            oddCount++;
        }
    }

    if (oddCount <= 1 || oddCount % 2 != 0) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}

