
import java.util.*;

public class Main{
  public static void main(String[] args){
    int n; // Variable to store the number of digits in the given number
    int sum=0; // Variable to store the sum of digits
    int m; // Variable to store the given number

    // Read the number of digits from the standard input
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();

    // Initialize m with the given number
    m = n;

    // Calculate the sum of digits
    while(m>0){
      sum+=m%10; // Add the last digit to the sum
      m/=10; // Remove the last digit and update m
    }

    // Check if the given number is divisible by the sum of its digits
    if(n%sum==0){
      System.out.println("Yes"); // If yes, print "Yes"
    }else{
      System.out.println("No"); // If no, print "No"
    }
  }
}

