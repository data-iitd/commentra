import java.util.Scanner;  // Import the standard input/output library
public class Main {  // Define the main class
    public static void main(String[] args) {  // Define the main function
        Scanner input = new Scanner(System.in);  // Create a new input object
        long n, a, b = 0, i, j;  // Declare variables to store the input number and the result
        n = input.nextLong();  // Read the input number
        b = (n * (n - 1)) / 2;  // Calculate the result using the given formula
        System.out.println(b);  // Print the result
    }
}
