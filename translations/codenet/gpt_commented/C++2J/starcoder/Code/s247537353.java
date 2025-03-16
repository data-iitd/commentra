import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    long A = in.nextLong();
    long B = in.nextLong();
    long C = in.nextLong();
    long K = in.nextLong();

    if (A + B >= K) {
      System.out.println(Math.min(A, K));
    } else {
      System.out.println(A - (K - (A + B)));
    }
  }
}

