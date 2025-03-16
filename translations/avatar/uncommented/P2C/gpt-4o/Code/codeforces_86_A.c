#include <stdio.h>
#include <math.h>

int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    
    int curr = r;
    int s = 0;
    
    while (curr) {
        s++;
        curr /= 10;
    }
    
    int first = pow(10, s);
    int second = first / 2;
    int ans = -1;

    int candidates[] = {l, r, first, second};
    for (int i = 0; i < 4; i++) {
        int candidate = candidates[i];
        if (candidate >= l && candidate <= r) {
            curr = candidate;
            char rev[20]; // Assuming the number won't exceed 20 digits
            int index = 0;
            for (char *k = (char *) &curr; *k != '\0'; k++) {
                rev[index++] = '9' - (*k - '0');
            }
            rev[index] = '\0'; // Null-terminate the string
            
            int rev_num = atoi(rev);
            ans = fmax(ans, rev_num * curr);
        }
    }
    
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
