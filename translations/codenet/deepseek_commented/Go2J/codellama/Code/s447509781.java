
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) {
    Input input = new Input();
    int n = input.nextInt(); // Read the number of elements
    int[] s = input.nextIntArray(); // Read the array of integers
    boolean[] u = new boolean[n]; // Initialize a boolean array to track visited positions
    long m = 0, f = 0;
    // Iterate over possible values of c to find the maximum sum
    for (int c = 1; c < n - 1; c++) {
      f = 0;
      // Iterate over possible multiples of c
      for (int k = 0; c < n - 1 - k * c; k++) {
        u[k * c] = true; // Mark the position as visited
        if (u[n - 1 - k * c]) {
          break; // If the position is already visited, break the loop
        }
        f += s[n - 1 - k * c] + s[k * c]; // Add the values at the current positions
        if (m < f) {
          m = f; // Update the maximum sum if the current sum is greater
        }
      }
      // Reset the boolean array for the next value of c
      for (int k = 0; k * c < n - 1; k++) {
        u[k * c] = false;
      }
    }
    System.out.println(m); // Print the maximum sum found
  }
}

class Input {
  private BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
  private StringTokenizer tokenizer = new StringTokenizer("");

  private String next() {
    while (!tokenizer.hasMoreTokens()) {
      try {
        tokenizer = new StringTokenizer(reader.readLine());
      } catch (Exception e) {
        throw new RuntimeException(e);
      }
    }
    return tokenizer.nextToken();
  }

  public int nextInt() {
    return Integer.parseInt(next());
  }

  public int[] nextIntArray() {
    String[] s = next().split(" ");
    int[] a = new int[s.length];
    for (int i = 0; i < s.length; i++) {
      a[i] = Integer.parseInt(s[i]);
    }
    return a;
  }
}

