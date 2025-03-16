
import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a, b; // Declare two integer variables 'a' and 'b'
    // Initialize them to zero by default

    a = sc.nextInt(); // Read an integer value from the standard input and store it in variable 'a'
    b = sc.nextInt(); // Read an integer value from the standard input and store it in variable 'b'

    if((a*b)%2 == 0){ // Check if the product of 'a' and 'b' is even
      System.out.println("Even"); // If it is even, print "Even" to the standard output
    }else{
      System.out.println("Odd"); // If it is odd, print "Odd" to the standard output
    }
  }
}

