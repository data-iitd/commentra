import java.util.*; // Import the Scanner class

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); // Create a Scanner object to read input from the user

        int x = input.nextInt(); // Read an integer value from the user and store it in 'x'

        // Calculate the cube of 'x' and print the result
        System.out.println(x * x * x); // Output the cube of 'x' followed by a newline
    }
}
