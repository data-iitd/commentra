

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[1000];
    scanf("%d", &n);
    scanf("%s", s);
    
    long rc = 0;
    long gc = 0;
    long bc = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            rc++;
        } else if (s[i] == 'G') {
            gc++;
        } else {
            bc++;
        }
    }
    
    long result = rc * gc * bc;
    
    for (int i = 1; i <= n; i++) {
        for (int k = i + 1; k <= n; k++) {
            if ((i + k) % 2 == 0) {
                char is = s[i - 1];
                char ks = s[k - 1];
                char js = s[((i + k) / 2) - 1];
                
                if (is!= ks && ks!= js && js!= is) {
                    result--;
                }
            }
        }
    }
    
    printf("%ld\n", result);
    
    return 0;
}

