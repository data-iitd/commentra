#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
using ll = long long;
using P = pair<int, int>;


def main():
    r, g, b, n = map(int, input().split())
    ans = 0
    for i in range(n // r + 1):
        for j in range(n // g + 1):
            num = n - r * i - g * j
            if num >= 0 and num % b == 0:
                ans += 1

    print(ans)


if __name__ == "__main__":
    main()


