
import java.util.*;

class s807902500 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String t = sc.next();
    s += s;
    System.out.println(s.indexOf(t)+1!= 0? "Yes" : "No");
  }
}
