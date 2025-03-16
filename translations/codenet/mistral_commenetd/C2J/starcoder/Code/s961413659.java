import java.util.Scanner; // Include the standard input/output library
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); // Create a Scanner object to read from the standard input
        int a, b; // Declare two integer variables 'a' and 'b'
        a = input.nextInt(); // Read an integer from the standard input and store it in variable 'a'
        b = input.nextInt(); // Read an integer from the standard input and store it in variable 'b'

        // First if block: If 'a' is equal to 1, assign 14 to 'a'
        if (a == 1)
            a = 14;

        // Second if block: If 'b' is equal to 1, assign 14 to 'b'
        if (b == 1)
            b = 14;

        // Determine who wins based on the values of 'a' and 'b'
        if (a < b)
            System.out.println("Bob"); // If 'a' is less than 'b', print "Bob"
        else if (a > b)
            System.out.println("Alice"); // If 'a' is greater than 'b', print "Alice"
        else
            System.out.println("Draw"); // If 'a' is equal to 'b', print "Draw"
    }
}
