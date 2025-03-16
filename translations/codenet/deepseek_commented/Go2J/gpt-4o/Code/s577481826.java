import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a scanner to read input from standard input
        Scanner sc = new Scanner(System.in);

        // Read the first integer from input
        int a = sc.nextInt();
        // Read the second integer from input
        int b = sc.nextInt();

        // Perform addition of the two integers
        int ret = a + b;

        // Check if the result is less than the difference between the two integers
        if (ret < (a - b)) {
            ret = a - b;
        }
        // Check if the updated result is less than the product of the two integers
        if (ret < (a * b)) {
            ret = a * b;
        }

        // Print the final result
        System.out.println(ret);
        
        // Close the scanner
        sc.close();
    }
}

// <END-OF-CODE>
