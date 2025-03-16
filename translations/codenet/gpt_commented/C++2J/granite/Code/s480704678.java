
import java.io.*;
import java.util.*;

public class s480704678{

  // Constants for large values and mathematical constants
  static long INF = 1001001001001001L;
  static int inf = 1000000007;
  static long MOD = 1000000007L;
  static double PI = 3.1415926535897932;

  // Function to update the minimum value
  static <T1 extends Comparable<T1>, T2 extends Comparable<T2>> void chmin(T1 a, T2 b) {
    if (a.compareTo(b) > 0) a = b;
  }

  // Function to update the maximum value
  static <T1 extends Comparable<T1>, T2 extends Comparable<T2>> void chmax(T1 a, T2 b) {
    if (a.compareTo(b) < 0) a = b;
  }

  // Macros for convenience in iterating through containers
  static <T> void ALL(T[] a) {
    int n = a.length;
    for (int i = 0; i < n; i++) {
      System.out.print(a[i] + " ");
    }
    System.out.println();
  }

  static <T> void RALL(T[] a) {
    int n = a.length;
    for (int i = n - 1; i >= 0; i--) {
      System.out.print(a[i] + " ");
    }
    System.out.println();
  }

  public static void main(String[] args) {
    // Read the number of elements
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    // Initialize a vector to store the input values and a vector for prefix sums
    long[] a = new long[n];
    long[] acc = new long[n + 1];

    // Read input values and compute prefix sums modulo MOD
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextLong();
      acc[i + 1] = (acc[i] + a[i]) % MOD; // Update prefix sum
    }

    // Initialize the answer variable
    long ans = 0;

    // Calculate the final answer using the prefix sums
    for (int i = 0; i < n; i++) {
      ans = (ans + a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD) % MOD; // Update answer based on current element and remaining sum
    }

    // Output the final result
    System.out.println(ans);

    // End of the program
    sc.close();
  }
}

