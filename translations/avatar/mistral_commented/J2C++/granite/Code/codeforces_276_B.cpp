

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string str;
    map<char, int> map;
    int oddCount = 0;

    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (map.find(ch)!= map.end()) {
            map[ch]++;
        } else {
            map[ch] = 1;
        }
    }

    for (auto const& [key, value] : map) {
        if (value % 2!= 0) {
            oddCount++;
        }
    }

    if (oddCount <= 1 || oddCount % 2!= 0) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}

