

import java.util.*;
import java.io.*;

class s582643375 {
  static int mod = 100000007; // Modulus value for modular arithmetic
  static long[] fac = new long[1000010]; // Array for storing factorials
  static long[] finv = new long[1000010]; // Array for storing fast inverses
  static long[] inv = new long[1000010]; // Array for storing inverses

  // Initialize the arrays with factorials, inverses, and fast inverse values
  static void init() {
    fac[0] = fac[1] = 1; // Base cases
    finv[0] = finv[1] = 1; // Base cases
    inv[1] = 1; // Base case
    for(int i = 2; i < 1000010; i++) { // Iterate from 2 to 1000000
      fac[i] = fac[i-1] * i % mod; // Multiply the current number with the previous factorial
      inv[i] = mod - inv[mod%i] * (mod/i) % mod; // Calculate the inverse of the current number using extended Euclidean algorithm
      finv[i] = finv[i-1] * inv[i] % mod; // Multiply the previous fast inverse with the current inverse to get the fast inverse
    }
  }

  // Calculate the binomial coefficient C(n, k) using the precomputed values
  static long C(int n,int k) {
    if(n < k) return 0; // Return 0 if n is less than k
    if(n < 0 || k < 0) return 0; // Return 0 if n or k is negative
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod; // Multiply the factorial of n with the product of the fast inverse of k and the fast inverse of n-k, then take the modulo
  }

  public static void main(String[] args) throws IOException {
    init(); // Initialize the arrays
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Create a BufferedReader object to read input from the user
    String[] input = br.readLine().split(" "); // Read input values for X and Y
    int X = Integer.parseInt(input[0]);
    int Y = Integer.parseInt(input[1]);
    if((X+Y) % 3!= 0) { // Check if the sum of X and Y is not divisible by 3
      System.out.println(0); // If not, print 0 and exit
      return;
    }
    int n = (X+Y) / 3+1; // Calculate the value of n = (X+Y)/3 + 1
    int k = 2*(n-1) - Y + 1; // Calculate the value of k = 2*(n-1) - Y + 1
    System.out.println(C(n-1, k-1)); // Print the binomial coefficient C(n-1, k-1)
    br.close(); // Close the BufferedReader object
  }
}

