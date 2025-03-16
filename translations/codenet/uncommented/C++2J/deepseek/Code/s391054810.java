public class Main {
  public static void main(String[] args) {
    java.util.Scanner scanner = new java.util.Scanner(System.in);
    int h = scanner.nextInt();
    int w = scanner.nextInt();
    int hh = scanner.nextInt();
    int ww = scanner.nextInt();
    System.out.println((h - hh) * (w - ww));
  }
}
