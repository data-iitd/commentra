
#include <stdio.h>

int main(){
    long long x1, x2, y1, y2;
    scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
    const long long dx = x2 - x1, dy = y2 - y1;
    long long x3 = x2 - dy, y3 = y2 + dx;
    long long x4 = x1 - dy, y4 = y1 + dx;
    printf("%lld %lld %lld %lld\n", x3, y3, x4, y4);
    return 0;
}
