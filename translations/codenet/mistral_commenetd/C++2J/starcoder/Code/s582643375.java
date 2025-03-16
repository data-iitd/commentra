
import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int X = in.nextInt();
    int Y = in.nextInt();
    if((X+Y) % 3!= 0) {
      System.out.println(0);
      return;
    }
    int n = (X+Y) / 3+1;
    int k = 2*(n-1) - Y + 1;
    System.out.println(C(n-1, k-1));
  }

  // Initialize the arrays with factorials, inverses, and fast inverse values
  public static void init() {
    fac[0] = fac[1] = 1; // Base cases
    finv[0] = finv[1] = 1; // Base cases
    inv[1] = 1; // Base case
    for(int i = 2; i < NMAX; i++) { // Iterate from 2 to NMAX-1
      fac[i] = fac[i-1] * i % mod; // Multiply the current number with the previous factorial
      inv[i] = mod - inv[mod%i] * (mod/i) % mod; // Calculate the inverse of the current number using extended Euclidean algorithm
      finv[i] = finv[i-1] * inv[i] % mod; // Multiply the previous fast inverse with the current inverse to get the fast inverse
    }
  }

  // Calculate the binomial coefficient C(n, k) using the precomputed values
  public static long C(int n,int k) {
    if(n < k) return 0; // Return 0 if n is less than k
    if(n < 0 || k < 0) return 0; // Return 0 if n or k is negative
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod; // Multiply the factorial of n with the product of the fast inverse of k and the fast inverse of n-k, then take the modulo
  }

  // Declare and initialize the arrays
  public static int NMAX = 1000010;
  public static int mod = 1000000007;
  public static long fac[] = new long[NMAX];
  public static long finv[] = new long[NMAX];
  public static long inv[] = new long[NMAX];
}

