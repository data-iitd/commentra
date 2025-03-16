import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the values of "n" and "k" from the standard input
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        // Check if the value of "k" is less than or equal to the middle index of the slice "n"
        if (k <= (n + n % 2) / 2) {
            // If the condition is true, print "YES" to the standard output
            System.out.println("YES");
        } else {
            // If the condition is false, print "NO" to the standard output
            System.out.println("NO");
        }
    }
}

