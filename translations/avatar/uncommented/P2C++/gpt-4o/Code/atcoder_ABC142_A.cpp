#include <iostream>
#include <vector>
using namespace std;

int next_int() {
    int x;
    cin >> x;
    return x;
}

vector<int> next_ints() {
    vector<int> nums;
    int x;
    while (cin >> x) {
        nums.push_back(x);
        if (cin.peek() == '\n') break; // Stop reading on newline
    }
    return nums;
}

int main() {
    int n = next_int();
    int t = 0;
    for (int i = 0; i < n; i++) {
        if ((i + 1) & 1) {
            t += 1;
        }
    }
    cout << static_cast<double>(t) / n << endl;
    return 0;
}

// <END-OF-CODE>
