import java.util.Scanner; // Import the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        int r = scanner.nextInt(); // Read an integer value from standard input and store it in 'r'
        
        // Calculate the square of 'r' and print the result
        System.out.println(r * r); // Output the square of 'r'
    }
}
