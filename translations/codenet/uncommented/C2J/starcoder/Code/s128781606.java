import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int A,B,C,D,E,max;
    A = sc.nextInt();
    B = sc.nextInt();
    C = A+B;
    D = A-B;
    E = A*B;
    max = C;
    if (max<D) {
      max = D;
    }
    if (max<E) {
      max = E;
    }
    System.out.println(max);
  }
}
