import java.util.*;

public class Main {
  public static void main(String[] args){
    // Initialize a Scanner object to read input from the user
    Scanner sc = new Scanner(System.in);
    
    // Read an integer n from the user
    int n = sc.nextInt();
    
    // Check if n divided by 10 is divisible by 111
    if((n / 10) % 111 == 0){
      // If true, print "Yes"
      System.out.println("Yes");
    } 
    // Check if the last three digits of n are divisible by 111
    else if((n % 1000) % 111 == 0){
      // If true, print "Yes"
      System.out.println("Yes");
    } 
    else {
      // If neither condition is true, print "No"
      System.out.println("No");
    }
  }
}
