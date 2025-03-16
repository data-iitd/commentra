import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Declare variables to hold input values
        int a, b, c, d, e, k;

        // Read six integers from standard input
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();
        e = scanner.nextInt();
        k = scanner.nextInt();

        // Check if the difference between e and a is less than or equal to k
        // If true, print "Yay!", otherwise print ":("
        System.out.println((e - a <= k) ? "Yay!" : ":(");

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
