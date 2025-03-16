import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int h = in.nextInt();
    int w = in.nextInt();
    int k = in.nextInt();
    
    // Initialize the grid with dimensions h x w, filled with 0s
    int[][] hw = new int[h][w];
    
    // Read the grid and set 1s where there is a '#'
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        char c = in.next().charAt(0);
        if (c == '#') hw[i][j] = 1;
      }
    }
    
    int sum = 0;
    
    // Iterate over all possible combinations of row and column selections
    for (int i = 0; i < (1 << h); i++) {
      for (int j = 0; j < (1 << w); j++) {
        if (count(hw, i, j) == k) sum++; // Check if the condition is met and sum the valid combinations
      }
    }
    
    // Output the result
    System.out.println(sum);
  }
  
  // Computes 2^a
  public static int pow2(int a) {
    int ret = 1;
    for (int i = 0; i < a; i++) ret *= 2;
    return ret;
  }
  
  // Counts the number of 1s in the grid hw where both the i-th row and the j-th column are selected
  public static int count(int[][] hw, int a, int b) {
    int sum = 0;
    for (int i = 0; i < hw.length; i++) {
      for (int j = 0; j < hw[0].length; j++) {
        if ((a >> i & 1) == 1 && (b >> j & 1) == 1 && hw[i][j] == 1) sum++;
      }
    }
    return sum;
  }
}

