
import java.util.Scanner;

public class s136583229{
    public static void main(String[] args) {
        // Declare a variable to store the input data
        int data;
        
        // Create a Scanner object to read input from the standard input
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer value from the standard input and store it in `data`
        data = scanner.nextInt();
        
        // Close the Scanner object to release system resources
        scanner.close();
        
        // Calculate the cube of `data` and store the result in `result`
        int result = data * data * data;
        
        // Print the result
        System.out.println(result);
    }
}
