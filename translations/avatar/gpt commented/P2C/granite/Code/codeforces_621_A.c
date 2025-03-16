
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, sum = 0, ok = 0, od = 0;
    scanf("%d", &n);
    int lst[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &lst[i]);
    }
    for (i = 0; i < n; i++) {
        if (lst[i] % 2 == 0) {
            sum += lst[i];
        } else {
            if (ok || od > 1) {
                sum += lst[i];
                od--;
                ok =!ok;
            } else {
                od++;
            }
        }
    }
    printf("%d", sum);
    return 0;
}
// END-OF-CODE