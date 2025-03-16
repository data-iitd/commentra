#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int x;
    cin >> x;
    int sum = 0;
    int i = 1;
    while (true) {
        sum += i;
        if (sum >= x) {
            break;
        }
        i++;
    }
    cout << i << endl;
    return 0;
}

