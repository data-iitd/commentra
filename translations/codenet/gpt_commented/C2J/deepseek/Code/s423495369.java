public class Main {
  public static void main(String[] args) {
    // Declare three integer variables A, B, and C
    int A, B, C;

    // Create a Scanner object to read user input
    java.util.Scanner scanner = new java.util.Scanner(System.in);

    // Read three integers from user input and store them in A, B, and C
    A = scanner.nextInt();
    B = scanner.nextInt();
    C = scanner.nextInt();

    // Check if C is between A and B (A < C < B)
    if (A < C && C < B) {
      // If true, print "Yes"
      System.out.println("Yes");
    } 
    // Check if C is between B and A (A > C > B)
    else if (A > C && C > B) {
      // If true, print "Yes"
      System.out.println("Yes");
    } 
    // If neither condition is met, print "No"
    else {
      System.out.println("No");
    }
  }
}
