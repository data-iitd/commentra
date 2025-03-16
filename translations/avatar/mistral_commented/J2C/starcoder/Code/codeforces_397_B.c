
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, n, a, b, x, low, high, mid, ans;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &a, &b);
        if(n < a){
            printf("No\n");
            continue;
        }
        if(a == b){
            if(n % a == 0)
                printf("Yes\n");
            else
                printf("No\n");
            continue;
        }
        x = b / (b - a);
        if(n > x * a){
            printf("Yes\n");
            continue;
        }
        low = 1;
        high = x + 1;
        ans = 1;
        while(low <= high){
            mid = (low + high) / 2;
            if(mid * a < n)
                low = mid + 1;
            else{
                ans = mid;
                high = mid - 1;
            }
        }
        if(n > (ans - 1) * b && n < ans * a)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}

