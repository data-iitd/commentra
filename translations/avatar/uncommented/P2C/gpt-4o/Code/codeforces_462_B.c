#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char s[100001]; // Assuming the maximum length of s is 100000
    scanf("%s", s);
    
    int count[26] = {0};
    
    for (int i = 0; i < n; i++) {
        count[s[i] - 'A']++;
    }
    
    // Sort the count array in descending order
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (count[i] < count[j]) {
                int temp = count[i];
                count[i] = count[j];
                count[j] = temp;
            }
        }
    }
    
    int res = 0;
    
    for (int i = 0; i < 26; i++) {
        if (count[i] >= k) {
            res += k * k;
            printf("%d\n", res);
            return 0;
        }
        k -= count[i];
        res += count[i] * count[i];
    }
    
    printf("%d\n", res);
    return 0;
}

// <END-OF-CODE>
