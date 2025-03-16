
import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Declare two string variables s and t to store user input.
    String s, t;

    // Read user input and store it in variables s and t respectively.
    Scanner sc = new Scanner(System.in);
    s = sc.next();
    t = sc.next();

    // Concatenate the string s with itself and store the result back in s.
    s += s;

    // Use the println() function to print the result to the console.
    System.out.println(s.contains(t)? "Yes" : "No");
    // Check if the substring t is present in the string s. If it is, print "Yes" to the console. Otherwise, print "No".
  }
}

