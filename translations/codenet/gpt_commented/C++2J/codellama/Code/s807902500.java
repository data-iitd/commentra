import java.util.Scanner; // Import the Scanner class for input operations

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); // Create a Scanner object for input operations
    String s = sc.nextLine(); // Read input string s from the user
    String t = sc.nextLine(); // Read input string t from the user

    s += s; // Concatenate string s with itself, effectively doubling it

    // Check if string t can be found within the doubled string s
    // If found, print "Yes", otherwise print "No"
    System.out.println(s.contains(t) ? "Yes" : "No");
  }
}

