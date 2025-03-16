#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char *digits;
    int size;
} BigInteger;

// Function to create a BigInteger initialized to 1
BigInteger createBigInteger() {
    BigInteger bi;
    bi.size = 1;
    bi.digits = (unsigned char *)malloc(sizeof(unsigned char) * 1);
    bi.digits[0] = 1; // Initialize to 1
    return bi;
}

// Function to multiply a BigInteger by an integer
BigInteger multiplyBigInteger(BigInteger bi, int num) {
    int carry = 0;
    for (int i = 0; i < bi.size; i++) {
        int product = bi.digits[i] * num + carry;
        bi.digits[i] = product % 10; // Store the last digit
        carry = product / 10; // Carry the rest
    }
    while (carry) {
        bi.digits = (unsigned char *)realloc(bi.digits, sizeof(unsigned char) * (bi.size + 1));
        bi.digits[bi.size] = carry % 10;
        carry /= 10;
        bi.size++;
    }
    return bi;
}

// Function to divide a BigInteger by an integer
BigInteger divideBigInteger(BigInteger bi, int num) {
    BigInteger result;
    result.size = 0;
    result.digits = (unsigned char *)malloc(sizeof(unsigned char) * bi.size);
    
    int remainder = 0;
    for (int i = bi.size - 1; i >= 0; i--) {
        int current = remainder * 10 + bi.digits[i];
        result.digits[result.size++] = current / num;
        remainder = current % num;
    }
    
    // Reverse the result
    for (int i = 0; i < result.size / 2; i++) {
        unsigned char temp = result.digits[i];
        result.digits[i] = result.digits[result.size - 1 - i];
        result.digits[result.size - 1 - i] = temp;
    }
    
    // Remove leading zeros
    while (result.size > 1 && result.digits[result.size - 1] == 0) {
        result.size--;
    }
    
    return result;
}

// Function to calculate the binomial coefficient C(n, m)
BigInteger C(int n, int m) {
    BigInteger res = createBigInteger(); // Initialize result as 1
    // Calculate the numerator part of the binomial coefficient
    for (int i = m - n + 1; i <= m; i++) 
        res = multiplyBigInteger(res, i); // Multiply by i from (m-n+1) to m
    
    // Calculate the denominator part of the binomial coefficient
    for (int i = 1; i <= n; i++) 
        res = divideBigInteger(res, i); // Divide by i from 1 to n
    
    return res; // Return the computed binomial coefficient
}

// Function to print BigInteger
void printBigInteger(BigInteger bi) {
    for (int i = bi.size - 1; i >= 0; i--) {
        printf("%d", bi.digits[i]);
    }
    printf("\n");
}

int main() {
    int n, p; // Declare variables for number of elements and parity
    int k0 = 0; // Counter for even numbers
    int k1 = 0; // Counter for odd numbers
    
    // Read the number of elements and the parity value
    scanf("%d %d", &n, &p);
    
    // Count the number of even and odd integers
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x); // Read the next integer
        if (x % 2 == 1) 
            k1++; // Increment odd counter
        else 
            k0++; // Increment even counter
    }
    
    BigInteger ans = createBigInteger(); // Initialize the answer as 1
    
    // Multiply the answer by 2 raised to the power of the number of even integers
    for (int i = 0; i < k0; i++) 
        ans = multiplyBigInteger(ans, 2); // Each even number contributes a factor of 2
    
    // If p is 0, calculate combinations for even selections of odd integers
    if (p == 0) {
        BigInteger add = createBigInteger(); // Initialize the sum for combinations
        // Sum the combinations of choosing even numbers of odd integers
        for (int i = 0; i <= k1; i += 2) 
            add = multiplyBigInteger(add, C(i, k1).digits[0]); // Add C(i, k1) for even i
        
        ans = multiplyBigInteger(ans, add); // Multiply the answer by the computed combinations
        printBigInteger(ans); // Output the final answer
    } else { // If p is 1, calculate combinations for odd selections of odd integers
        BigInteger add = createBigInteger(); // Initialize the sum for combinations
        // Sum the combinations of choosing odd numbers of odd integers
        for (int i = 1; i <= k1; i += 2) 
            add = multiplyBigInteger(add, C(i, k1).digits[0]); // Add C(i, k1) for odd i
        
        ans = multiplyBigInteger(ans, add); // Multiply the answer by the computed combinations
        printBigInteger(ans); // Output the final answer
    }

    return 0;
}

// <END-OF-CODE>
