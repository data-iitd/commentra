
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <map>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    map<int, int> w;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        w[x]++;
    }
    long long c = 0;
    for (auto it = w.begin(); it!= w.end(); it++) {
        if (it->first == 0) {
            c += (long long)it->second * (it->second - 1);
        } else {
            if (w.find(-it->first)!= w.end()) {
                c += (long long)it->second * w[-it->first];
            }
        }
    }
    printf("%lld\n", c / 2);
    return 0;
}
