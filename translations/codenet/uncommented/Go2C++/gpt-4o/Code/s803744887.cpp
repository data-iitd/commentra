#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int MX = 10000;
    vector<int> sieve(MX, 0);
    vector<int> primes;

    for (int i = 2; i < MX; i++) {
        if (sieve[i] != 0) {
            continue;
        }
        primes.push_back(i);
        for (int j = i + i; j < MX; j += i) {
            sieve[j] = i;
        }
    }

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans++;
        for (size_t j = 0; j < primes.size(); j++) {
            if (x > primes[j] && x % primes[j] == 0) {
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
