#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    int a, b;
    int ans;

    scanf("%d %d", &a, &b);

    ans = 0;
    if (a >= 13) {
        ans = b;
    } else if (a >= 6) {
        ans = b/2;
    }

    cout << ans << endl;

    return 0;
}

