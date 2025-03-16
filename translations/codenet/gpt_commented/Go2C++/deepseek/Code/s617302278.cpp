#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    int x;
    cin >> x;
    int i = 1;
    int sum = 0;
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
