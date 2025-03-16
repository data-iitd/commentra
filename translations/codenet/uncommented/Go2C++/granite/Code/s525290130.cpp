
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int b, e;
        scanf("%d %d", &b, &e);
        reverse(a.begin() + b, a.begin() + e);
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
