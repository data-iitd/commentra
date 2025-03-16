import java.util.Scanner; // Importing the Scanner class to read input from the user

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object to read input from the user
        
        int a = scanner.nextInt(); // Reading the first integer input from the user
        int b = scanner.nextInt(); // Reading the second integer input from the user
        
        // Checking if the first number is positive
        if (a > 0) {
            System.out.println("Positive"); // Printing "Positive" if the first number is greater than 0
        } 
        // Checking if the first number is zero or the second number is non-negative
        else if (b >= 0) {
            System.out.println("Zero"); // Printing "Zero" if the second number is non-negative
        } 
        // Checking if the difference between b and a plus one is even
        else if ((b - a + 1) % 2 == 0) {
            System.out.println("Positive"); // Printing "Positive" if the difference is even
        } 
        else {
            System.out.println("Negative"); // Printing "Negative" if none of the above conditions are met
        }
    }
}
