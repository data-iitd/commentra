#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string input;
    cin >> input;
    vector<int> numbers;
    for (auto number : input) {
        numbers.push_back(number - '0');
    }
    if (numbers.size() == 2 && numbers.count(5) == 2 && sum(numbers) == 17) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

