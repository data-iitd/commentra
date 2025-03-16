import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    String s = in.next();
    String t = in.next();

    // Concatenate s with itself to double its length
    s += s;

    // Check if t is a substring of the doubled s
    // If found, find returns the position; otherwise, it returns -1
    // Convert the result to a boolean for easy printing
    System.out.println(s.contains(t));
  }
}
