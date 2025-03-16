
// Import the Scanner class for reading input from the user
import java.util.Scanner;

// Import the BigInteger class for efficient integer operations
import java.math.BigInteger;

// Create a Scanner object for reading input from the user
Scanner sc = new Scanner(System.in);

// Read the number of elements 'N' from the user
int N = sc.nextInt();

// Read 'N' integers from the user and store them in an array 'A'
BigInteger[] A = new BigInteger[N];
for (int i = 0; i < N; i++) {
    A[i] = sc.nextBigInteger();
}

// Initialize the result variable to zero
BigInteger result = BigInteger.ZERO;

// Iterate through each bit position 'b' from 0 to 59
for (int b = 0; b <= 59; b++) {
    
    // Calculate the sum of bits in position 'b' in all numbers of 'A'
    BigInteger bs = BigInteger.ZERO;
    for (int i = 0; i < N; i++) {
        if (A[i].testBit(b)) {
            bs = bs.add(BigInteger.ONE);
        }
    }
    
    // Calculate the contribution of this bit position 'b' to the result
    BigInteger contribution = bs.multiply(N.subtract(bs)).multiply(BigInteger.valueOf(1 << b));
    
    // Add this contribution to the result
    result = result.add(contribution).mod(BigInteger.valueOf(1000000007));
}

// Print the final result
System.out.println(result);

