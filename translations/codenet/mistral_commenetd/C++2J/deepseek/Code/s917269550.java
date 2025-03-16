import java.util.Scanner; // Import Scanner class for input

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in); // Create a Scanner object

    long x, y; // Declare two long integers, x and y, to store user inputs

    // Read user inputs from standard input using scanner.nextLong()
    x = scanner.nextLong();
    y = scanner.nextLong();

    // Check if the absolute difference between x and y is less than or equal to 1
    if(Math.abs(x - y) <= 1){
      // If the condition is true, print "Brown" to the standard output
      System.out.println("Brown");
    }
    else{
      // If the condition is false, print "Alice" to the standard output
      System.out.println("Alice");
    }
  }
}
