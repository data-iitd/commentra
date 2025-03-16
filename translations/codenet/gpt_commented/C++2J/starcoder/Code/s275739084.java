
import java.util.*;

public class Main
{
  public static void main(String[] args)
  {
    // Declare two integer variables A and B
    int A, B;

    // Read input values for A and B from the user
    Scanner sc = new Scanner(System.in);
    A = sc.nextInt();
    B = sc.nextInt();

    // Calculate the sum of A and B and store it in variable C
    int C = A + B;

    // Check if A, B, and C are all not divisible by 3
    if (A % 3!= 0 && B % 3!= 0 && C % 3!= 0)
    {
      // If the condition is true, output "Impossible"
      System.out.println("Impossible");
    }
    else
    {
      // If the condition is false, output "Possible"
      System.out.println("Possible");
    }

    // Return 0 to indicate successful completion of the program
    return 0;
  }
}
