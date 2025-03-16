
import java.util.*; // Import the Scanner class for reading input

public class Main {
  public static void main(String[] args){
    // Create a new Scanner object named sc to read input from the user
    Scanner sc = new Scanner(System.in);

    // Read an integer n from the user using the nextInt() method of the Scanner class
    int n = sc.nextInt();

    // Check if the quotient of n by 10 (i.e., n/10) has a remainder of 0 when divided by 111
    if((n/10)%111 == 0){
      System.out.println("Yes"); // If it does, print "Yes" to the console
    }

    // If the check in the previous step fails, check if the last three digits of n (i.e., n%1000) have a remainder of 0 when divided by 111
    else if((n%1000)%111 == 0){
      System.out.println("Yes"); // If it does, print "Yes" to the console
    }

    // If both checks fail, print "No" to the console
    else{
      System.out.println("No");
    }
  }
}