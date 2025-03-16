
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    // Read the number of elements in the array 'a'
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    // Initialize a vector 'a' of size 'n'
    long[] a = new long[n];

    // Initialize a vector 'acc' of size 'n+1' with zero as initial value
    long[] acc = new long[n + 1];

    // Read the elements of the array 'a' and calculate the cumulative sum
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextLong();

      // Update the cumulative sum 'acc' for the current index 'i+1'
      acc[i + 1] = acc[i] + a[i];

      // Perform modulo operation to keep the value within the range of 'MOD'
      acc[i + 1] %= MOD;
    }

    // Initialize the answer 'ans' to zero
    long ans = 0;

    // Calculate the answer using the formula
    for (int i = 0; i < n; i++) {
      // Calculate the contribution of the current element 'a[i]' to the answer
      long temp = a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD;

      // Add the contribution to the answer
      ans += temp;

      // Perform modulo operation to keep the value within the range of 'MOD'
      ans %= MOD;
    }

    // Print the answer
    System.out.println(ans);

    // Terminate the program
    sc.close();
  }
}

