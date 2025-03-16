
import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Read input values for n and m
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();

    // Initialize boolean array r0 with all elements set to false
    boolean[] r0 = new boolean[n];
    Arrays.fill(r0, false);

    // Initialize integer array r1 and counter for its size
    int[] r1 = new int[n];
    int nr1 = 0;

    // Process each of the m input pairs
    for (int i = 0; i < m; i++) {
      // Read input values for a and b
      int a = sc.nextInt();
      int b = sc.nextInt();

      // Swap a and b if a is greater than b
      if (a > b) {
        int t = a;
        a = b;
        b = t;
      }

      // If a is equal to 1, set the corresponding element in r0 to true
      if (a == 1) r0[b - 1] = true;

      // If b is equal to n, add its index to r1
      if (b == n) r1[nr1++] = a - 1;
    }

    // Initialize boolean variable res to false
    boolean res = false;

    // Check if there exists any pair in r1 whose corresponding element in r0 is true
    for (int i = 0; i < nr1; i++) {
      // If such a pair is found, set res to true
      if (r0[r1[i]]) res = true;
    }

    // Output the result based on the value of res
    System.out.println(res? "POSSIBLE" : "IMPOSSIBLE");
  }
}

