
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    // Declare three integer variables: A, B, and flag
    int A, B, flag = 0;

    // Read two integers from the standard input and store them in variables A and B
    Scanner in = new Scanner(System.in);
    A = in.nextInt();
    B = in.nextInt();

    // Iterate from 1 to 3 using a for loop
    for(int i=1; i<=3; ++i) {
      // Check if the product of A, B, and the loop counter i is odd
      if((A*B*i)%2 == 1) {
        // Set the flag variable to 1 if the condition is true
        flag = 1;
        // Break out of the loop if the condition is true
        break;
      }
    }

    // Check the value of the flag variable
    if(flag) {
      // Print "Yes" to the standard output if the flag variable is 1
      System.out.println("Yes");
    } else {
      // Print "No" to the standard output if the flag variable is 0
      System.out.println("No");
    }
  }
}

