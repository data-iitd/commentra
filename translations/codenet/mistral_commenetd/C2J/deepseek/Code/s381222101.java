import java.util.Scanner; // Import the Scanner class to read input from the user

public class RectangleArea {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input

        int a, b, h; // Declare three integer variables: a, b, and h

        System.out.print("Enter the values of a, b, and h: "); // Print a message asking for user input
        a = scanner.nextInt(); // Read the first integer from the user and store it in variable a
        b = scanner.nextInt(); // Read the second integer from the user and store it in variable b
        h = scanner.nextInt(); // Read the third integer from the user and store it in variable h

        // Calculate the area of the rectangle using the formula: area = length * width
        System.out.println((a + b) * h / 2); // Print the result, which is the area of the rectangle

        scanner.close(); // Close the Scanner object to free up resources
    }
}
