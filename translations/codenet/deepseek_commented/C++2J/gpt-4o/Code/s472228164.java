import java.util.Scanner;

public class Main {
    // Function to check if a certain condition is met based on the values of x and y
    public static String check(int x, int y) {
        // Check if y is even
        if (y % 2 == 0) {
            // Calculate t as half of y minus x
            int t = (y / 2) - x;
            // Check if t is non-negative and x minus t is also non-negative
            if (t >= 0 && (x - t) >= 0) {
                return "Yes";
            }
        }
        // If the conditions are not met, return "No"
        return "No";
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read two integers x and y from the standard input
        int x = scanner.nextInt();
        int y = scanner.nextInt();

        // Call the check function with x and y, and print the result
        System.out.println(check(x, y));
        scanner.close();
    }
}

// <END-OF-CODE>
