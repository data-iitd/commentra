import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Declare variables a, b, c, and d of type int
        int a, b, c, d;

        // Read values of variables a, b, c, and d from standard input
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();

        // Calculate the difference between a and c, and the difference between b and d
        long difference_ab = (long) a - (long) c;
        long difference_cd = (long) b - (long) d;

        // Multiply the differences and print the result to standard output
        System.out.println(difference_ab * difference_cd);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
