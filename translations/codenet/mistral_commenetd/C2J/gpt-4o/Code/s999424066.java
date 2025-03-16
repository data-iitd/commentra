import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Start of the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int a, b, c, x, y; // Declare variables a, b, c, x, and y as integers
        a = scanner.nextInt(); // Read the first integer
        b = scanner.nextInt(); // Read the second integer
        c = scanner.nextInt(); // Read the third integer
        x = scanner.nextInt(); // Read the fourth integer
        y = scanner.nextInt(); // Read the fifth integer

        c *= 2; // Multiply the value of variable c by 2

        if (a + b <= c) { // Check if the sum of variables a and b is less than or equal to the value of variable c
            System.out.println(a * x + b * y); // If the condition is true, print the result of multiplying variables a and x, and variables b and y
        } else { // If the condition in the if statement is false, execute the code in the else block
            if (x <= y) { // Check if the value of variable x is less than or equal to the value of variable y
                if (b <= c) { // Check if the value of variable b is less than or equal to the value of variable c
                    System.out.println(c * x + (y - x) * b); // Print the result of the calculation
                } else { // If the first condition in the nested if statement is false
                    System.out.println(c * y); // Print the result of multiplying variable c by the value of variable y
                }
            } else { // If the condition in the outer if statement is false and the condition in the if statement that checks if x is less than or equal to y is also false
                if (a <= c) { // Check if the value of variable a is less than or equal to the value of variable c
                    System.out.println(c * y + (x - y) * a); // Print the result of the calculation
                } else { // If the condition in the if statement that checks if a is less than or equal to c is false
                    System.out.println(c * x); // Print the result of multiplying variable c by the value of x
                }
            } // End of the else statement that checks if x is greater than y
        } // End of the else statement that checks if the sum of a and b is greater than c

        scanner.close(); // Close the scanner
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
