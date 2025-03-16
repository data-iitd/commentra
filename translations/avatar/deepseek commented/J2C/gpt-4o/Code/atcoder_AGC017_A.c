#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char *digits;
    int size;
} BigInteger;

// Function to create a BigInteger initialized to 1
BigInteger createBigInteger(int value) {
    BigInteger bi;
    bi.size = 1;
    bi.digits = (unsigned char *)malloc(sizeof(unsigned char) * 1);
    bi.digits[0] = value;
    return bi;
}

// Function to multiply two BigIntegers
BigInteger multiplyBigInteger(BigInteger a, int b) {
    BigInteger result;
    int carry = 0;
    result.size = a.size + 1;
    result.digits = (unsigned char *)malloc(sizeof(unsigned char) * result.size);
    
    for (int i = 0; i < result.size; i++) {
        result.digits[i] = 0;
    }

    for (int i = 0; i < a.size; i++) {
        int prod = a.digits[i] * b + carry;
        result.digits[i] = prod % 256; // Assuming byte-sized digits
        carry = prod / 256;
    }
    result.digits[result.size - 1] = carry;

    // Remove leading zeros if any
    while (result.size > 1 && result.digits[result.size - 1] == 0) {
        result.size--;
    }
    return result;
}

// Function to divide a BigInteger by an integer
BigInteger divideBigInteger(BigInteger a, int b) {
    BigInteger result;
    result.size = a.size;
    result.digits = (unsigned char *)malloc(sizeof(unsigned char) * result.size);
    
    int carry = 0;
    for (int i = a.size - 1; i >= 0; i--) {
        int current = carry * 256 + a.digits[i];
        result.digits[i] = current / b;
        carry = current % b;
    }

    // Remove leading zeros if any
    while (result.size > 1 && result.digits[result.size - 1] == 0) {
        result.size--;
    }
    return result;
}

// Function to calculate combination (n choose m)
BigInteger C(int n, int m) {
    BigInteger res = createBigInteger(1);
    for (int i = m - n + 1; i <= m; i++) {
        res = multiplyBigInteger(res, i);
    }
    for (int i = 1; i <= n; i++) {
        res = divideBigInteger(res, i);
    }
    return res;
}

int main() {
    int n, p;
    int k0 = 0; // Count of even numbers
    int k1 = 0; // Count of odd numbers

    // Read number of items (n) and the value of p
    scanf("%d %d", &n, &p);

    // Count even and odd numbers in the input
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 1)
            k1++;
        else
            k0++;
    }

    // Initialize result for number of ways to arrange items
    BigInteger ans = createBigInteger(1);

    // Calculate number of ways based on the value of p
    for (int i = 0; i < k0; i++)
        ans = multiplyBigInteger(ans, 2); // Multiply by 2 for each even number

    BigInteger add = createBigInteger(0);
    if (p == 0) {
        // Sum combinations of odd numbers, taking 0, 2, 4, ... odd numbers
        for (int i = 0; i <= k1; i += 2) {
            BigInteger comb = C(i, k1);
            add = multiplyBigInteger(add, comb.digits[0]); // Simplified for demonstration
        }
    } else {
        // Sum combinations of odd numbers, taking 1, 3, 5, ... odd numbers
        for (int i = 1; i <= k1; i += 2) {
            BigInteger comb = C(i, k1);
            add = multiplyBigInteger(add, comb.digits[0]); // Simplified for demonstration
        }
    }

    ans = multiplyBigInteger(ans, add.digits[0]); // Simplified for demonstration
    printf("%d\n", ans.digits[0]); // Print final result (simplified)

    // Free allocated memory
    free(ans.digits);
    free(add.digits);

    return 0;
}

// <END-OF-CODE>
