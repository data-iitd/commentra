#include <stdio.h>

typedef long long ll;

int main() {
<<<<<<< HEAD
    ll h;
    ll ans = 0, cnt = 1;
=======
    ll h, ans = 0, cnt = 1;
>>>>>>> 98c87cb78a (data updated)

    scanf("%lld", &h);
    while (h != 1) {
        if (h % 2 != 0) h--;
        h /= 2;
        cnt *= 2;
        ans += cnt;
    }
    printf("%lld\n", ans + 1);
    return 0;
}

// <END-OF-CODE>
