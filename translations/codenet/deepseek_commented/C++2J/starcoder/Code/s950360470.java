import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int k = in.nextInt();
    System.out.println(mod_nCk(k, n, MOD));
  }

  // Function to calculate a^n % mod
  static int mod_pow(int a, int n, int mod) {
    int res = 1; // Initialize result
    while (n > 0) { // Loop until n becomes 0
      if (n % 2 == 1) res = (res * a) % mod; // If n is odd, multiply result by a modulo mod
      a = (a * a) % mod; // Square a modulo mod
      n /= 2; // Divide n by 2
    }
    return res; // Return the result
  }

  // Function to calculate a^(-1) % mod (only if a % mod!= 0)
  static int mod_inv(int a, int mod) {
    return mod_pow(a, mod - 2, mod); // Use Fermat's little theorem: a^(mod-2) % mod is a^-1 % mod
  }

  // Function to calculate nCk % mod
  static int mod_nCk(int n, int k, int mod) {
    if (n == 0 || k == 0) return 1; // Base case: nCk is 1 if n or k is 0
    int p = 1, q = 1; // Initialize p and q
    for (int i = n - k + 1; i <= n; i++) // Calculate numerator
      p = (p * i) % mod;
    for (int i = 2; i <= k; i++) // Calculate denominator
      q = (q * i) % mod;
    q = mod_inv(q, mod); // Calculate inverse of denominator
    return (p * q) % mod; // Return the result
  }
}

