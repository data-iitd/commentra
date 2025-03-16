import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n, k, t, i, p, ret = 0;

    // Loop to read input values and process them
    while (true) {
      // Read values of n and k
      n = sc.nextInt();
      k = sc.nextInt();
      if (n == 0 && k == 0) break; // Break the loop if both n and k are zero

      // Initialize the data and seq arrays to zero
      int[] data = new int[111111];
      int[] seq = new int[222222];
      Arrays.fill(data, 0);
      Arrays.fill(seq, 0);

      // Read k numbers and store their frequencies in data
      for (i = 0; i < k; i++) {
        t = sc.nextInt();
        data[t]++;
      }

      // Construct the seq array based on the frequencies in data
      p = 0;
      for (i = 1; i <= n; i++) {
        if (data[i]!= 0) {
          seq[p]++;
        } else {
          p += 2;
        }
      }
      p++;

      // Calculate the maximum value of ret based on the sequences in seq
      if (data[0]!= 0) {
        for (i = 0; i < p; i++) {
          ret = Math.max(ret, seq[i] + seq[i + 2] + 1);
        }
      } else {
        for (i = 0; i < p; i++) {
          ret = Math.max(ret, seq[i]);
        }
      }

      // Print the result
      System.out.println(ret);
    }
  }
}

