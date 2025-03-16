import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long H = sc.nextLong();
    long W = sc.nextLong();
    long m = H * W;
    long ans;
    if (H == 1 || W == 1) {
      ans = 1;
    } else if (m % 2 == 0) {
      ans = m / 2;
    } else {
      ans = m / 2 + 1;
    }
    System.out.println(ans);
  }
}

