
import java.util.*;
import java.io.*;

class s497487985 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] str = br.readLine().split(" ");
    int n = Integer.parseInt(str[0]);
    long k = Long.parseLong(str[1]);
    int q = Integer.parseInt(str[2]);
    long[] a = new long[q];
    long[] point = new long[n];
    Arrays.fill(point, k);
    for (int i = 0; i < q; i++) {
      a[i] = Long.parseLong(br.readLine());
      point[(int)a[i] - 1]--;
    }
    for (int i = 0; i < n; i++) {
      if (k - q + point[i] > 0) {
        System.out.println("Yes");
      } else {
        System.out.println("No");
      }
    }
  }
}
