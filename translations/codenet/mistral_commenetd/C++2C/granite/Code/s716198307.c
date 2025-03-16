
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<functional>

int main(void){
    int n;
    double avg;
    double s;
    double ans;

    scanf("%d", &n);
    int a[100];
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
    printf("%.0f\n", ans);

    return 0;
}
