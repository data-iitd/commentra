
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <utility>
#include <iomanip>
#include <iterator>
#include <functional>
#include <cassert>
#include <bitset>
#include <random>
#include <valarray>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <complex>
#include <chrono>
#include <tuple>
#include <array>
#include <list>
#include <forward_list>
#include <optional>
#include <variant>

using namespace std;

// Define constants
const int MOD = 100000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// Define main function
int main() {
    // Read input string
    char s[100001];
    scanf("%s", s);

    // Check if all characters in the string are the same
    if (unique(s, s + strlen(s)) == s + strlen(s)) {
        // If so, print 0 and exit
        printf("0\n");
        return 0;
    }

    // Count the occurrences of each character in the string
    int a[26] = {};
    for (int i = 0; s[i]; i++) {
        a[s[i] - 'a']++;
    }

    // Calculate the answer
    int ans = *min_element(a, a + 26) * 2;

    // Print the answer
    printf("%d\n", ans);

    return 0;
}

Translate the above C code to Java and end with comment "