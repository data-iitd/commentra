#include <iostream>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    long long N;
    cin >> N;
    long long min = 0;
    for (int i = 0; i < 5; i++) {
        if (i == 0) min = N;
        else min = min < N ? min : N;
    }
    cout << (long long)ceil((double)N / min) + 4 << endl;
    return 0;
}
