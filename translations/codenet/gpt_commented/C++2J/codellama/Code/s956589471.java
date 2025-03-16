import java.util.Scanner; // Import the Scanner class for input and output

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold input values
        int a, b, c, d, e, k;

        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Read six integers from standard input
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();
        e = scanner.nextInt();
        k = scanner.nextInt();

        // Check if the difference between e and a is less than or equal to k
        // If true, print "Yay!", otherwise print ":("
        System.out.println((e - a <= k ? "Yay!" : ":("));
    }
}

