import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a,b,c,d,e,i;
    a = sc.nextInt();
    b = sc.nextInt();
    c = sc.nextInt();
    if (b<=c) {
      System.out.println("NO");
      return;
    } else {
      d=a;
      e=d%b;
      for (i=0; i<b; i++) {
        d=d%b;
        if (d==c) {
          System.out.println("YES");
          return;
        } else if (i!=0&&d==c) {
          System.out.println("NO");
          return;
        }
        d+=a;
      }
    }
    System.out.println("NO");
  }
}
