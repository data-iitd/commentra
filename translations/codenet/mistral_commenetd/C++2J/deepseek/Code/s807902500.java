import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    // Declare two string variables s and t to store user input.
    String s, t;

    // Create a Scanner object to read user input.
    Scanner scanner = new Scanner(System.in);

    // Read user input and store it in variables s and t respectively.
    s = scanner.next();
    t = scanner.next();

    // Concatenate the string s with itself and store the result back in s.
    s += s;

    // Use the System.out.println() function to print the result to the console.
    System.out.println(s.contains(t) ? "Yes" : "No");
    // Check if the substring t is present in the string s. If it is, print "Yes" to the console. Otherwise, print "No".
  }
}
