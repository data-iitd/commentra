
import java.util.*;

class Main {
  public static void main(String[] args) {
    // Create a Scanner object to read input from the user
    Scanner sc = new Scanner(System.in);
    
    // Read a string input from the user
    String s = sc.next();
    
    // Extract the first four characters from the string
    String s1 = s.substring(0,1);
    String s2 = s.substring(1,2);
    String s3 = s.substring(2,3);
    String s4 = s.substring(3,4);
    
    // Initialize a variable to keep track of consecutive characters
    int a = 0;
    
    // Check if any two consecutive characters are the same
    if(s1.equals(s2)) a = 1;
    if(s2.equals(s3)) a = 1;
    if(s3.equals(s4)) a = 1;
    
    // Print "Bad" if any two consecutive characters are the same, otherwise print "Good"
    if (a==1) {
	    System.out.println("Bad");
    } else {
      System.out.println("Good");
    }
  }
}

