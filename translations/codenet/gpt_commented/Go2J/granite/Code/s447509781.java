
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s447509781{
  public static void main(String[] args) throws IOException {
    Input input = new Input();
    
    // Read the number of elements and the array of integers from input
    int n = input.nextInt();
    int[] s = input.nextIntArray();
    
    // Create a boolean array to track used indices
    boolean[] u = new boolean[n];
    
    // Initialize variables to store the maximum sum and a temporary sum
    long m = 0, f = 0;
    
    // Iterate through possible values of c from 1 to n-2
    for (int c = 1; c < n-1; c++) {
      f = 0; // Reset the temporary sum for each c
      
      // Iterate to find pairs of indices based on the current value of c
      for (int k = 0; c < n-1-k*c; k++) {
        u[k*c] = true; // Mark the current index as used
        
        // Break if the corresponding index is already used
        if (u[n-1-k*c]) { break; }
        
        // Calculate the sum of the elements at the current indices
        f += s[n-1-k*c] + s[k*c];
        
        // Update the maximum sum if the current sum is greater
        if (m < f) { m = f; }
      }
      
      // Reset the used indices for the next iteration of c
      for (int k = 0; k*c < n-1; k++) { u[k*c] = false; }
    }
    
    // Print the maximum sum found
    System.out.println(m);
  }
  
  // Input class to handle reading from standard input
  static class Input {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer tokenizer = new StringTokenizer("");
    
    // NextLine reads a full line from input
    String nextLine() throws IOException {
      while (!tokenizer.hasMoreTokens()) {
        tokenizer = new StringTokenizer(reader.readLine());
      }
      return tokenizer.nextToken("\n");
    }
    
    // NextInt reads an integer from input
    int nextInt() throws IOException {
      return Integer.parseInt(nextLine());
    }
    
    // NextIntArray reads a line of integers and returns them as an array
    int[] nextIntArray() throws IOException {
      String[] s = nextLine().split(" ");
      int[] a = new int[s.length];
      for (int i = 0; i < s.length; i++) {
        a[i] = Integer.parseInt(s[i]);
      }
      return a;
    }
  }
}

