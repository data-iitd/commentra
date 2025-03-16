import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read a string input from the user
        String s = sc.next();
        
        // Check the input string and print the corresponding weather condition
        if (s.equals("Sunny")) {
            // If the input is "Sunny", output "Cloudy"
            System.out.println("Cloudy");
        } else if (s.equals("Cloudy")) {
            // If the input is "Cloudy", output "Rainy"
            System.out.println("Rainy");
        } else {
            // For any other input, output "Sunny"
            System.out.println("Sunny");
        }
        
        // Close the scanner to prevent resource leaks
        sc.close();
    }
}
