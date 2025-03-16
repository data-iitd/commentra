
#include <stdio.h>
#include <math.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int x = m*1900 + (n-m)*100;
    printf("%d\n", x * (int)pow(2.0, (double)m));
    return 0;
}
