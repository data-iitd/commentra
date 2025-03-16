
import java.util.Scanner; // Importing the Scanner class for reading user input

public class s102334995{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Declare two integer variables to hold user input
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Calculate and print the product of a and b, 
        // and also print the perimeter of a rectangle with sides a and b
        System.out.println(a * b);
        System.out.println((a + b) * 2);
    }
}
