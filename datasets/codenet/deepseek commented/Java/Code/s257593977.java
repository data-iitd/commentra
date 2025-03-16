import java.util.Scanner; // Importing the Scanner class for input

public class Main {

    private static final int BASE = 3; // Defining a constant BASE with value 3

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize Scanner object to read input
        int input = scanner.nextInt(); // Read an integer input from the user
        int result = (int)Math.pow(input, BASE); // Raise the input to the power of BASE and cast to int
        System.out.println(result); // Print the result
    }
}
