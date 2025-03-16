
public class Main {
  public static void main(String[] args) {
    int a, b, c;
    Scanner sc = new Scanner(System.in);
    a = sc.nextInt();
    b = sc.nextInt();
    c = sc.nextInt();
    if (b > a * c) {
      System.out.println(c);
    } else {
      System.out.println(b / a);
    }
  }
}

