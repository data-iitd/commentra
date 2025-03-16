
import java.util.Scanner;

public class s807902500{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String s = scanner.next();
    String t = scanner.next();

    // Concatenate s with itself to double its length
    s += s;

    // Check if t is a substring of the doubled s
    // If found, find returns the position; otherwise, it returns -1
    // Convert the result to a boolean for easy printing
    System.out.println((s.indexOf(t)!= -1)? "Yes" : "No");
  }
}
