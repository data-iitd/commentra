
// Declare three integer variables A, B, and C
public class Main {
  public static void main(String[] args) {
    int A, B, C;

    // Read three integers from the standard input using Scanner class
    Scanner scanner = new Scanner(System.in);
    A = scanner.nextInt();
    B = scanner.nextInt();
    C = scanner.nextInt();

    // Check if A is less than C and C is less than B
    if (A < C && C < B) {
      // If condition is true, print "Yes" to the standard output
      System.out.println("Yes");
    } // End of first if block

    // Else if condition checks if A is greater than C and C is greater than B
    else if (A > C && C > B) {
      // If condition is true, print "Yes" to the standard output
      System.out.println("Yes");
    } // End of second if block

    // Else condition is executed when neither first nor second condition is true
    else {
      // If condition is false, print "No" to the standard output
      System.out.println("No");
    } // End of else block
  } // End of main function
} // End of Main class

