
import java.util.Scanner;

public class s178339312{
    public static void main(String[] args) {
        // Declare a variable to store the input integer
        int x;
        
        // Create a Scanner object to read input from the standard input
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer from the standard input and store it in x
        x = scanner.nextInt();
        
        // Close the Scanner object
        scanner.close();
        
        // Calculate the cube of x (x*x*x)
        int result = x * x * x;
        
        // Print the result
        System.out.println(result);
    }
}
