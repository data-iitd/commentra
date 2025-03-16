
import java.util.*;
import java.io.*;

class s950360470 {
  static long MOD = 100000007; // Define a constant for modulo operation

  // Function to calculate a^n
  static long pow(long a, long n) {
    long res = 1; // Initialize result
    while (n > 0) { // Loop until n becomes 0
      if (n % 2 == 1) res *= a; // If n is odd, multiply result by a
      a *= a; // Square a
      n /= 2; // Divide n by 2
    }
    return res; // Return the result
  }

  // Function to calculate a^n % mod
  static long mod_pow(long a, long n, long mod) {
    long res = 1; // Initialize result
    while (n > 0) { // Loop until n becomes 0
      if (n % 2 == 1) res = res * a % mod; // If n is odd, multiply result by a modulo mod
      a = a * a % mod; // Square a modulo mod
      n /= 2; // Divide n by 2
    }
    return res; // Return the result
  }

  // Function to calculate a^(-1) % mod (only if a % mod!= 0)
  static long mod_inv(long a, long mod) {
    return mod_pow(a, mod - 2, mod); // Use Fermat's little theorem: a^(mod-2) % mod is a^-1 % mod
  }

  // Function to calculate nCk % mod
  static long mod_nCk(int n, int k, int mod) {
    if (n == 0 || k == 0) return 1; // Base case: nCk is 1 if n or k is 0
    long p = 1, q = 1; // Initialize p and q
    for (int i = n - k + 1; i <= n; i++) // Calculate numerator
      p = (p * i) % MOD;
    for (int i = 2; i <= k; i++) // Calculate denominator
      q = (q * i) % MOD;
    q = mod_inv(q, MOD); // Calculate inverse of denominator
    return (p * q) % MOD; // Return the result
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] input = br.readLine().split(" ");
    int n = Integer.parseInt(input[0]);
    int k = Integer.parseInt(input[1]);
    System.out.println(mod_nCk(k, n, (int)MOD)); // Calculate and print nCk % MOD
  }
}
