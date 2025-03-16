import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); // Step 1: Read input values
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    int d = sc.nextInt();

    // Step 4: Perform calculations
    int area = (a - c) * (b - d); // Calculate the area of the rectangle using the given coordinates

    // Step 5: Output the result
    System.out.println(area); // Print the calculated area to the console
  }
}

