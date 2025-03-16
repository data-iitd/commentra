
import java.util.Scanner;
import java.math.BigInteger;

// Define the modulo constant
BigInteger MOD = new BigInteger("1000000007");

// Read the integer input N
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();

// Define a constant for the maximum size
int M = 1000000;

// Read the array A from input and convert it to a BigInteger array
BigInteger[] A = new BigInteger[N];
for (int i = 0; i < N; i++) {
    A[i] = sc.nextBigInteger();
}

// Define the size for factorial calculations
int Nsq = 1000;

// Initialize a 2D array to store factorial values
BigInteger[][] fact = new BigInteger[Nsq][Nsq];

// Set the first factorial value
fact[0][0] = BigInteger.ONE;

// Compute factorial values for columns
for (int n = 1; n < Nsq; n++) {
    for (int i = 0; i < Nsq; i++) {
        fact[i][n] = fact[i][n - 1].multiply(fact[i][n - 1]);
        fact[i][n] = fact[i][n].mod(MOD);
    }
}

// Compute factorial values for rows
for (int n = 1; n < Nsq; n++) {
    for (int i = 0; i < Nsq; i++) {
        fact[n][i] = fact[n - 1][i].multiply(fact[n - 1][Nsq - 1]);
        fact[n][i] = fact[n][i].mod(MOD);
    }
}

// Flatten the factorial array to 1D
BigInteger[] fact1D = new BigInteger[Nsq * Nsq];
for (int i = 0; i < Nsq; i++) {
    for (int j = 0; j < Nsq; j++) {
        fact1D[i * Nsq + j] = fact[i][j];
    }
}

// Create an array of indices from 0 to N-1
int[] j = new int[N];
for (int i = 0; i < N; i++) {
    j[i] = i;
}

// Calculate modular inverses of numbers from 1 to N
BigInteger[] inv = new BigInteger[N];
for (int i = 0; i < N; i++) {
    inv[i] = BigInteger.valueOf(i + 1).modPow(MOD.subtract(BigInteger.ONE), MOD);
}

// Compute cumulative sum of inverses and take modulo
for (int i = 1; i < N; i++) {
    inv[i] = inv[i].add(inv[i - 1]);
    inv[i] = inv[i].mod(MOD);
}

// Calculate temporary values based on the cumulative inverses
BigInteger[] temp = new BigInteger[N];
for (int i = 0; i < N; i++) {
    temp[i] = inv[j[i]].add(inv[N - 1 - j[i]]).subtract(BigInteger.ONE);
    temp[i] = temp[i].mod(MOD);
}

// Compute the final answer by multiplying A with temp and summing the result
BigInteger ans = BigInteger.ZERO;
for (int i = 0; i < N; i++) {
    ans = ans.add(A[i].multiply(temp[i]));
    ans = ans.mod(MOD);
}

// Multiply the answer by the factorial of N and take modulo
ans = ans.multiply(fact1D[N]);
ans = ans.mod(MOD);

// Print the final answer
System.out.println(ans);

