import java.util.Scanner; // Importing the Scanner class to read input from the user

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object to read input
        int a, b; // Declaring two integer variables a and b
        a = scanner.nextInt(); // Reading the first integer from the user and storing it in variable a
        b = scanner.nextInt(); // Reading the second integer from the user and storing it in variable b

        // Logical block to check if 500 times the value of variable 'a' is greater than or equal to the value of variable 'b'
        if(500 * a >= b) {
            System.out.println("Yes"); // If the condition is true, print 'Yes' to the standard output
        } else {
            System.out.println("No"); // If the condition is false, print 'No' to the standard output
        }

        scanner.close(); // Closing the Scanner object to free up resources
    }
}
