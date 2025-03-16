import java.util.*;

public class Main {
  public static void main(String... args) {
    // Create a Scanner object to read input from the user
    Scanner scan = new Scanner(System.in);
    
    // Read an integer input from the user, representing the radius
    int r = scan.nextInt();
    
    // Calculate the area of a circle using the formula area = π * r^2
    // Here, we are calculating r^2 (radius squared)
    int res = (int)Math.pow(r, 2);
    
    // Output the result (area of the circle) to the console
    System.out.println(res);
  }
}
