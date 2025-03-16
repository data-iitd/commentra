
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long N;
    cin >> N;
    long min = 0;
    for (int i = 0; i < 5; i++) {
        if (i == 0)
            cin >> min;
        else
            min = min < (long)cin.nextLong() ? min : (long)cin.nextLong();
    }
    cout << (long)ceil((double)N / min) + 4 << endl;
    return 0;
}

