
import java.util.Scanner;

public class s566920420{
    public static void main(String[] args) {
        // Declare an integer variable 'a' to store the user input
        int a;
        
        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input from the user and store it in 'a'
        a = scanner.nextInt();
        
        // Close the Scanner object
        scanner.close();
        
        // Print the result of the expression 'a + a*a + a*a*a'
        System.out.println(a + a*a + a*a*a);
    }
}
