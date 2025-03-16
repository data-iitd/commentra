#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int nextInt() {
    int n;
    cin >> n;
    return n;
}

int min(int i, int j) {
    return (i < j) ? i : j;
}

void checkDivisibility(int n) {
    int rt = sqrt(n);
    int minf = 100;
    for (int i = 1; i < rt + 1; i++) {
        if (n % i == 0) {
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            minf = min(minf, ndigit);
        }
    }
    cout << minf << endl;
}

int main() {
    int n = nextInt();
    checkDivisibility(n);
    return 0;
}

