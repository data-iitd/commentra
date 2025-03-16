// Import required libraries
import java.util.Scanner;
import java.math.BigInteger;

// Define constant value
final BigInteger MOD = new BigInteger("1000000007");

// Read input number of elements N
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();

// Define a constant value for the size of the 2D array A
final int M = 1000000;

// Initialize 2D array A with given size and input data
int[][] A = new int[N][N];
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        A[i][j] = sc.nextInt();
    }
}

// Define a constant value for the size of the 2D array fact
final int Nsq = 1000;

// Initialize 2D array fact with given size and initial value 1
BigInteger[][] fact = new BigInteger[Nsq][Nsq];
for (int i = 0; i < Nsq; i++) {
    for (int j = 0; j < Nsq; j++) {
        fact[i][j] = BigInteger.ONE;
    }
}

// Calculate factorial for each cell in the 2D array fact using a loop
for (int n = 1; n < Nsq; n++) {
    for (int i = 0; i < Nsq; i++) {
        fact[i][n] = fact[i][n - 1].multiply(fact[i][n]);
        fact[i][n] = fact[i][n].mod(MOD);
    }
}

// Transpose the 2D array fact and calculate factorial for each cell in the new rows
for (int n = 1; n < Nsq; n++) {
    for (int i = 0; i < Nsq; i++) {
        fact[n][i] = fact[n - 1][i].multiply(fact[n - 1][Nsq - 1]);
        fact[n][i] = fact[n][i].mod(MOD);
    }
}

// Flatten the 2D array fact into a 1D array
BigInteger[] fact1D = new BigInteger[Nsq * Nsq];
for (int i = 0; i < Nsq; i++) {
    for (int j = 0; j < Nsq; j++) {
        fact1D[i * Nsq + j] = fact[i][j];
    }
}

// Initialize array j with given size
int[] j = new int[N];
for (int i = 0; i < N; i++) {
    j[i] = i;
}

// Calculate the inverse of each element in the array inv using a list comprehension
BigInteger[] inv = new BigInteger[N];
for (int i = 0; i < N; i++) {
    inv[i] = BigInteger.valueOf(i + 1).modPow(MOD.subtract(BigInteger.ONE), MOD);
}

// Calculate cumulative sum of the array inv
for (int i = 1; i < N; i++) {
    inv[i] = inv[i].add(inv[i - 1]);
    inv[i] = inv[i].mod(MOD);
}

// Calculate temporary array temp using elements from j and inv
BigInteger[] temp = new BigInteger[N];
for (int i = 0; i < N; i++) {
    temp[i] = inv[j[i]].add(inv[N - 1 - j[i]]).subtract(BigInteger.ONE);
    temp[i] = temp[i].mod(MOD);
}

// Calculate the answer ans using given formula
BigInteger ans = BigInteger.ZERO;
for (int i = 0; i < N; i++) {
    ans = ans.add(A[i][j[i]].multiply(temp[i]));
    ans = ans.mod(MOD);
}

// Modulo the answer ans with given constant value MOD
ans = ans.mod(MOD);

// Multiply the answer ans with the last element of fact array
ans = ans.multiply(fact1D[Nsq * Nsq - 1]);

// Modulo the answer ans with given constant value MOD
ans = ans.mod(MOD);

// Print the answer ans
System.out.println(ans);

