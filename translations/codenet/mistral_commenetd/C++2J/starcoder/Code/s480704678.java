
import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    // Read the number of elements in the array 'a'
    int n = Integer.parseInt(System.console().readLine());

    // Initialize a vector 'a' of size 'n'
    int[] a = new int[n];

    // Initialize a vector 'acc' of size 'n+1' with zero as initial value
    int[] acc = new int[n + 1];

    // Read the elements of the array 'a' and calculate the cumulative sum
    for (int i = 0; i < n; i++) {
      a[i] = Integer.parseInt(System.console().readLine());

      // Update the cumulative sum 'acc' for the current index 'i+1'
      acc[i + 1] = acc[i] + a[i];
    }

    // Initialize the answer 'ans' to zero
    long ans = 0;

    // Calculate the answer using the formula
    for (int i = 0; i < n; i++) {
      // Calculate the contribution of the current element 'a[i]' to the answer
      long temp = (long) a[i] * (MOD + acc[n] - acc[i + 1]) % MOD;

      // Add the contribution to the answer
      ans += temp;

      // Perform modulo operation to keep the value within the range of 'MOD'
      ans %= MOD;
    }

    // Print the answer
    System.out.println(ans);
  }
}

