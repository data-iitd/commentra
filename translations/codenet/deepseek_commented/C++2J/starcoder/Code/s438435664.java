import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    // Read two integers n and k
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int k = in.nextInt();
    int sum = 0;

    // Iterate over possible values of b
    for (int b = 1; b <= n; b++) {
      // Calculate the count and remainder
      int cnt = (n + 1) / b;
      int md = (n + 1) % b;

      // Update the sum based on the conditions involving k
      sum += cnt * Math.max(b - k, 0) + Math.max(md - k, 0);

      // Adjust the sum if k is 0
      if (k == 0) sum--;
    }

    // Print the computed sum
    System.out.println(sum);
  }
}

