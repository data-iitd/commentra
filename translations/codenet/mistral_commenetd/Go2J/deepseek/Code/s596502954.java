import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the first three integers from the input
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();

        // Check if the condition is true
        if (a + b >= c) {
            // If true, print "Yes" to the output
            System.out.println("Yes");
        } else {
            // If false, print "No" to the output
            System.out.println("No");
        }

        // End of code
    }
}
