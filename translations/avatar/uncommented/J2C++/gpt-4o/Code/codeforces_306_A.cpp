#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);

    if (n % m == 0) {
        for (int i = 0; i < a.size(); i++) {
            a[i] = n / m;
        }
    } else {
        int sub = n / m;
        for (int i = 0; i < a.size(); i++) {
            a[i] = sub;
        }
        int test = n - (sub * m);
        int count = 0;
        for (int i = 0; i < test; i++) {
            a[count] += 1;
            count++;
            if (count >= a.size()) count = 0;
        }
    }

    for (int i = a.size() - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }

    return 0;
}

// <END-OF-CODE>
