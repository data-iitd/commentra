import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from stdin

    int r = sc.nextInt(); // Read the radius value from user input

    System.out.println(r * r); // Output the calculated area (r squared)

    sc.close(); // Close the scanner object
  }
}

