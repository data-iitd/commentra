#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <stdlib.h>
#include <algorithm>
#include <functional>

int main(void){
    int n, a[100];
    double avg = 0, s, ans;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        avg += a[i];
    }
    avg /= n;
    s = fabs(a[0] - avg);
    ans = 0;
    for(int i = 1; i < n; i++){
        if(s > fabs(a[i] - avg)){
            s = fabs(a[i] - avg);
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
