
import java.util.Scanner; // Import the Scanner class to read input from the user

public class Main { // Define the Main class
    public static void main(String[] args) { // Define the main function, the entry point of the program
        Scanner sc = new Scanner(System.in); // Create a new Scanner object to read input from the standard input
        int x = sc.nextInt(); // Read an integer from the standard input and store it in x
        int y = sc.nextInt(); // Read an integer from the standard input and store it in y
        System.out.println(x * y); // Print the product of x and y
        System.out.println(2 * x + 2 * y); // Print the perimeter of the rectangle
    }
}

