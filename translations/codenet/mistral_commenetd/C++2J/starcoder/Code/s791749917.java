
import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    // Read input from stdin
    Scanner in = new Scanner(System.in);

    // Read the first line of input
    String[] HW = in.nextLine().split(" ");
    int H = Integer.parseInt(HW[0]);
    int W = Integer.parseInt(HW[1]);

    // Initialize answer variable
    int ans;

    // Check if the grid has only one cell
    if (H == 1 || W == 1) {
      ans = 1; // The answer is 1 in this case
    } else {
      // Calculate the total number of cells in the grid
      int m = H*W;

      // Check if the total number of cells is even
      if (m % 2 == 0) {
        ans = m/2; // The answer is half of the total number of cells if it's even
      } else {
        ans = m/2+1; // The answer is half of the total number of cells plus one if it's odd
      }
    }

    // Output the answer
    System.out.println(ans);
  }
}

