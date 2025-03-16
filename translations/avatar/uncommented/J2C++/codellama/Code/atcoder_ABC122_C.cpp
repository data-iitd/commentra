
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n, q;
    char c[100000];
    int range[100000][2];
    int frag[100000];
    int rui[100000];
    cin >> n >> q;
    cin >> c;
    for (int i = 0; i < q; i++) {
        cin >> range[i][0] >> range[i][1];
    }
    for (int i = 2; i <= n; i++) {
        if (c[i - 2] == 'A' && c[i - 1] == 'C') {
            frag[i]++;
        }
        rui[i] = rui[i - 1] + frag[i];
    }
    for (int i = 0; i < q; i++) {
        int left = range[i][0];
        int right = range[i][1];
        cout << rui[right] - rui[left] << endl;
    }
    return 0;
}

