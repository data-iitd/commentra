
import java.util.Scanner; // Importing the Scanner class for reading user input

public class s566920420{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read user input
        int a = scanner.nextInt(); // Read an integer value from standard input and store it in 'a'
        
        // Calculate the expression a + a^2 + a^3 and print the result
        System.out.println(a + a*a + a*a*a); 
    }
}
