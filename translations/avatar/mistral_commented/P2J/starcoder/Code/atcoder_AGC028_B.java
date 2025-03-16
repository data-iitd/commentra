// Import required libraries
import java.util.*;

// Define constant value
final int MOD = 1000000007;

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
int[][] fact = new int[Nsq][Nsq];
fact[0][0] = 1;

// Calculate factorial for each cell in the 2D array fact using a loop
for (int n = 1; n < Nsq; n++) {
    for (int i = 0; i < Nsq; i++) {
        fact[i][n] = fact[i][n - 1] * fact[i][n - 1] % MOD;
    }
}

// Transpose the 2D array fact and calculate factorial for each cell in the new rows
for (int n = 1; n < Nsq; n++) {
    for (int i = 0; i < Nsq; i++) {
        fact[n][i] = fact[n - 1][i] * fact[n - 1][Nsq - 1] % MOD;
    }
}

// Flatten the 2D array fact into a 1D array
int[] fact1D = new int[Nsq * Nsq];
for (int i = 0; i < Nsq; i++) {
    for (int j = 0; j < Nsq; j++) {
        fact1D[i * Nsq + j] = fact[i][j];
    }
}

// Initialize array j with given size
int[] j = new int[N];

// Calculate the inverse of each element in the array inv using a list comprehension
int[] inv = new int[N];
for (int i = 0; i < N; i++) {
    inv[i] = pow(i + 1, MOD - 2, MOD);
}

// Calculate cumulative sum of the array inv
for (int i = 1; i < N; i++) {
    inv[i] = (inv[i] + inv[i - 1]) % MOD;
}

// Calculate temporary array temp using elements from j and inv
int[] temp = new int[N];
for (int i = 0; i < N; i++) {
    temp[i] = (inv[j[i]] + inv[N - 1 - j[i]]) % MOD;
}

// Calculate the answer ans using given formula
int ans = 0;
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        ans += A[i][j] * temp[i] * temp[j] % MOD;
        ans %= MOD;
    }
}

// Multiply the answer ans with the last element of fact array
ans *= fact1D[N * Nsq - 1];

// Modulo the answer ans with given constant value MOD
ans %= MOD;

// Print the answer ans
System.out.println(ans);

// 