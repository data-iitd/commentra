public class Main {
  public static void main(String[] args) {
    java.util.Scanner scanner = new java.util.Scanner(System.in);  // Step 1: Create a Scanner object

    int a = scanner.nextInt();  // Step 2: Read input values
    int b = scanner.nextInt();
    int c = scanner.nextInt();

    if (b > a * c) {  // Step 3: Implement the if-else condition
      System.out.println(c);  // If true, print c
    } else {
      System.out.println(b / a);  // Otherwise, print b divided by a
    }
  }
}
