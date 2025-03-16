
import java.util.*;

class s957555615 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    TreeSet<Integer> set = new TreeSet<>();
    for (int i = 0; i < n; i++) {
      String com = sc.next();
      if (com.equals("insert")) {
        int x = sc.nextInt();
        set.add(x);
      } else if (com.equals("find")) {
        int x = sc.nextInt();
        if (set.contains(x)) {
          System.out.println("yes");
        } else {
          System.out.println("no");
        }
      } else if (com.equals("print")) {
        StringBuilder sb = new StringBuilder();
        for (int num : set) {
          sb.append(" ").append(num);
        }
        System.out.println(sb.substring(1));
        sb = new StringBuilder();
        for (int num : set) {
          sb.append(" ").append(num);
        }
        System.out.println(sb.substring(1));
      } else if (com.equals("delete")) {
        int x = sc.nextInt();
        set.remove(x);
      }
    }
  }
}
