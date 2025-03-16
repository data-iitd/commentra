import java.util.Scanner; // Import the standard input/output library

public class Main {
    public static void main(String[] args) { // Define the main function, the entry point of the program
        Scanner input = new Scanner(System.in); // Create a new Scanner object to read from the standard input
        int x = input.nextInt(); // Read an integer from the standard input and store it in x
        int y = input.nextInt(); // Read an integer from the standard input and store it in y
        System.out.println(x * y); // Print the product of x and y
        System.out.println(2 * x + 2 * y); // Print the perimeter of the rectangle
        input.close(); // Close the Scanner object
    }
}
