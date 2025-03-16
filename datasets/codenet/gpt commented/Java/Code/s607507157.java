import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    // Create a Scanner object to read input from the user
    Scanner sc = new Scanner(System.in);
    
    // Read an integer input from the user
    int n = sc.nextInt();
    
    // Check if the last digit of n is 9 or if the first digit of n is 9
    if(n % 10 == 9 || n / 10 == 9) {
      // If either condition is true, print "Yes"
      System.out.println("Yes");
    } else {
      // If neither condition is true, print "No"
      System.out.println("No");
    }
  }
}
