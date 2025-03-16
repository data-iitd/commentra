
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

using namespace std;

int main() {
    int x;
    cin >> x;
    int i = 1;
    int sum = 0;
    while (sum < x) {
        sum += i;
        i++;
    }
    cout << i - 1 << endl;
    return 0;
}
