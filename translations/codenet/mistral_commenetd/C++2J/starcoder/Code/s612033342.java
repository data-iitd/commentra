
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int h = sc.nextInt();
    int w = sc.nextInt();
    int k = sc.nextInt();
    int[][] hw = new int[h][w];
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        char c = sc.next().charAt(0);
        if (c == '#') hw[i][j] = 1;
      }
    }
    int sum = 0;
    for (int i = 0; i < (1 << h); i++) {
      for (int j = 0; j < (1 << w); j++) {
        if (count(hw, i, j) == k) sum++;
      }
    }
    System.out.println(sum);
  }

  // Function to calculate 2 raised to the power of a given number
  public static int pow2(int a) {
    int ret = 1; // Initialize result to 1
    for (int i = 0; i < a; i++) ret *= 2; // Multiply result by 2 for each iteration of the loop
    return ret; // Return the final result
  }

  // Function to count the number of 1's in the given 2D grid that match the binary representation of a and b
  public static int count(int[][] hw, int a, int b) {
    int sum = 0; // Initialize sum to 0
    for (int i = 0; i < hw.length; i++) { // Iterate through each row of the 2D grid
      for (int j = 0; j < hw[0].length; j++) { // Iterate through each column of the current row
        if ((a & (1 << i))!= 0 && (b & (1 << j))!= 0 && hw[i][j] == 1) sum++; // If the bits at the corresponding positions in a and b are set and the corresponding cell in the grid is 1, increment sum
      }
    }
    return sum; // Return the final sum
  }
}

