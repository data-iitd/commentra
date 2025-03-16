
import java.util.Scanner;

public class s470461127{
   public static void main(String[] args) {
      // Declare two integer variables x and y
      int x, y;
      
      // Initialize x and y to 0
      x = 0; 
      y = 0;   

      // Create a Scanner object to read input from the user
      Scanner scanner = new Scanner(System.in);
      
      // Read two integer values from the user and store them in x and y
      x = scanner.nextInt();	
      y = scanner.nextInt();
      
      // Calculate the product of x and y, and the perimeter of a rectangle with sides x and y
      // Print the product and the perimeter
      System.out.println(x * y + " " + (2*x) + (2*y));  

      // Close the Scanner object to release system resources
      scanner.close();
   }
}
