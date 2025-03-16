
#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

int main() {
    string str;
    map<char, int> map;
    int oddCount = 0;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        char ch = str.at(i);
        if (map.find(ch) != map.end()) {
            map[ch]++;
        } else {
            map[ch] = 1;
        }
    }
    for (map<char, int>::iterator it = map.begin(); it != map.end(); it++) {
        if (it->second % 2 != 0) {
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

