
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a variable to store the input data
        int data;
        
        // Read an integer value from the standard input and store it in `data`
        Scanner scanner = new Scanner(System.in);
        data = scanner.nextInt();
        
        // Calculate the cube of `data` and store the result in `result`
        int result = data * data * data;
        
        // Print the result
        System.out.println(result);
    }
}

