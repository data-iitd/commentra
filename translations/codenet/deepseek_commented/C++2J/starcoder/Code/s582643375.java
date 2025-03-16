import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int X = in.nextInt();
    int Y = in.nextInt();
    // Check if the sum of X and Y is divisible by 3
    if((X+Y) % 3!= 0) {
      System.out.println(0);
      return;
    }
    // Calculate the number of steps needed to reach the target point
    int n = (X+Y) / 3+1;
    // Calculate the number of steps needed to reach the target point from the most upper point
    int k = 2*(n-1) - Y + 1; // y = 2xより最も上にくる点からどれだけ離れているか。
    // Output the number of ways to reach the target point
    System.out.println(C(n-1, k-1));
  }

  // Calculate the binomial coefficient C(n, k)
  public static long C(int n,int k) {
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    long ans = 1;
    for(int i = 0; i < k; i++) {
      ans = ans * (n-i) / (i+1);
    }
    return ans;
  }
}

