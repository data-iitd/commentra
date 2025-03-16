import java.util.Scanner; // Importing the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Reading two integer values from the user
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Checking if the first integer 'a' is positive
        if (a > 0) {
            System.out.println("Positive"); // Output "Positive" if 'a' is greater than 0
        } 
        // Checking if the second integer 'b' is non-negative (zero or positive)
        else if (b >= 0) {
            System.out.println("Zero"); // Output "Zero" if 'b' is greater than or equal to 0
        } 
        // Checking if the difference between 'b' and 'a' plus 1 is even
        else if ((b - a + 1) % 2 == 0) {
            System.out.println("Positive"); // Output "Positive" if the result is even
        } 
        // If none of the above conditions are met, it means the result is negative
        else {
            System.out.println("Negative"); // Output "Negative" for all other cases
        }
    }
}
