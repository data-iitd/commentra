import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    // Declare variables A and B to hold input values, and flag to indicate if a condition is met
    int A, B, flag = 0;

    // Read two integers from user input
    Scanner in = new Scanner(System.in);
    A = in.nextInt();
    B = in.nextInt();

    // Loop through the values 1 to 3
    for(int i=1; i<=3; ++i) {
      // Check if the product of A, B, and i is odd
      if((A*B*i)%2 == 1) {
        // Set flag to 1 if the condition is met and exit the loop
        flag = 1;
        break;
      }
    }

    // Print "Yes" if flag is set, indicating at least one odd product was found; otherwise print "No"
    if(flag) System.out.println("Yes");
    else System.out.println("No");
  }
}
