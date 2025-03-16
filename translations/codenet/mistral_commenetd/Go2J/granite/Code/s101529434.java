

import java.util.Scanner;

public class s101529434{
    public static void main(String[] args) {
        // Declare two integer variables, K and X
        Scanner scanner = new Scanner(System.in);
        int K = scanner.nextInt();
        int X = scanner.nextInt();

        // Check if the condition 500*K >= X is true
        if (500 * K >= X) {
            // If the condition is true, print the string "Yes" to the standard output
            System.out.println("Yes");
        } else {
            // If the condition is false, print the string "No" to the standard output
            System.out.println("No");
        }
    }
}
