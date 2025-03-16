#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    string input;
    getline(cin, input);

    istringstream iss(input);
    vector<int> list;

    int x;
    while (iss >> x) {
        list.push_back(x % 2);
    }

    int oddCount = 0;
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == 1) {
            oddCount++;
        }
    }

    if (oddCount == 1) {
        cout << list.size() - oddCount + 1 << endl;
    } else {
        for (int i = 0; i < list.size(); i++) {
            if (list[i] == 0) {
                cout << i + 1 << endl;
                break;
            }
        }
    }

    return 0;
}

