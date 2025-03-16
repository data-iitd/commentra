

#include <stdio.h>  // Including required C libraries for input and output
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <limits>
#include <iomanip>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int cards[26] = {0};
    char s[n];
    scanf("%s", s);

    for (int i = 0; i < n; i++) {
        cards[s[i] - 'A']++;
    }

    long long ans = 0;
    for (int i = 0; i < k; i++) {
        std::sort(cards, cards + 26, std::greater<int>());
        int change = std::min(cards[25], k - i);
        ans += (long long)change * change;
        cards[25] -= change;
        i += change - 1;
    }

    printf("%lld\n", ans);

    return 0;
}

Translate the above C code to Python and end with comment "