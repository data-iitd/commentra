import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int H = sc.nextInt();
    int W = sc.nextInt();
    int m = H*W;
    int ans;
    if (H == 1 || W == 1) {
      ans = 1;
    } else {
      if (m % 2 == 0) ans = m/2;
      else ans = m/2+1;
    }
    System.out.println(ans);
  }
}

