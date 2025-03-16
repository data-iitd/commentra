#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int rt = static_cast<int>(sqrt(n));
    int minf = 100;

    for (int i = 1; i <= rt; i++) {
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
    return 0;
}

// <END-OF-CODE>
