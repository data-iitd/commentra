
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare two integer variables, K and X
        int K, X;

        // Read two integers from the standard input and assign them to the variables K and X respectively
        Scanner sc = new Scanner(System.in);
        K = sc.nextInt();
        X = sc.nextInt();

        // Check if the condition 500*K >= X is true
        if (500*K >= X) {
            // If the condition is true, print the string "Yes" to the standard output
            System.out.println("Yes");
        } else {
            // If the condition is false, print the string "No" to the standard output
            System.out.println("No");
        }
    }
}

