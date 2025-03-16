public class Main {
  public static void main(String[] args) {
    java.util.Scanner scanner = new java.util.Scanner(System.in);
    String s = scanner.next();
    if ((s.charAt(0) == s.charAt(1) && s.charAt(1) == s.charAt(2)) || (s.charAt(1) == s.charAt(2) && s.charAt(2) == s.charAt(3))) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
