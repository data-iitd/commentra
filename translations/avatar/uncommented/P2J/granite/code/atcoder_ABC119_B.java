
import java.util.*;

class atcoder_ABC119_B {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    double[] x = new double[N];
    for (int i = 0; i < N; i++) {
      String s = sc.next();
      if (s.equals("JPY")) {
        x[i] = sc.nextDouble();
      } else if (s.equals("BTC")) {
        x[i] = sc.nextDouble() * 380000.0;
      }
    }
    double sum = 0;
    for (int i = 0; i < N; i++) {
      sum += x[i];
    }
    System.out.println(sum);
  }
}
