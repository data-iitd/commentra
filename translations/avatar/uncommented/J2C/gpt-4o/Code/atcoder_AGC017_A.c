#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char *digits;
    int size;
} BigInteger;

BigInteger createBigInteger(int size) {
    BigInteger bi;
    bi.size = size;
    bi.digits = (unsigned char *)malloc(size);
    for (int i = 0; i < size; i++) {
        bi.digits[i] = 0;
    }
    return bi;
}

void freeBigInteger(BigInteger *bi) {
    free(bi->digits);
}

BigInteger multiplyBigInteger(BigInteger a, BigInteger b) {
    // Implement multiplication logic for BigInteger
    // This is a placeholder for the actual implementation
    BigInteger result = createBigInteger(a.size + b.size);
    // ... (multiplication logic goes here)
    return result;
}

BigInteger divideBigInteger(BigInteger a, int b) {
    // Implement division logic for BigInteger
    // This is a placeholder for the actual implementation
    BigInteger result = createBigInteger(a.size);
    // ... (division logic goes here)
    return result;
}

BigInteger C(int n, int m) {
    BigInteger res = createBigInteger(1);
    for (int i = m - n + 1; i <= m; i++) {
        // res = res.multiply(BigInteger.valueOf(i));
        // Implement multiplication logic here
    }
    for (int i = 1; i <= n; i++) {
        // res = res.divide(BigInteger.valueOf(i));
        // Implement division logic here
    }
    return res;
}

int main() {
    int n, p;
    int k0 = 0, k1 = 0;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 1) {
            k1++;
        } else {
            k0++;
        }
    }
    
    BigInteger ans = createBigInteger(1);
    for (int i = 0; i < k0; i++) {
        // ans = ans.multiply(BigInteger.valueOf(2));
        // Implement multiplication logic here
    }
    
    if (p == 0) {
        BigInteger add = createBigInteger(1);
        for (int i = 0; i <= k1; i += 2) {
            add = multiplyBigInteger(add, C(i, k1));
        }
        ans = multiplyBigInteger(ans, add);
        // Print the result
    } else {
        BigInteger add = createBigInteger(1);
        for (int i = 1; i <= k1; i += 2) {
            add = multiplyBigInteger(add, C(i, k1));
        }
        ans = multiplyBigInteger(ans, add);
        // Print the result
    }

    freeBigInteger(&ans);
    return 0;
}

// <END-OF-CODE>
