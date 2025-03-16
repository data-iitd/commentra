
import java.util.*;

class s237922865 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int cnt4 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++) {
      int wk = sc.nextInt();
      if (wk % 4 == 0) {
        cnt4++;
      } else if (wk % 2 == 0) {
        cnt2++;
      }
    }
    if (cnt4 + cnt2 / 2 >= n / 2) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
//END-OF-CODE