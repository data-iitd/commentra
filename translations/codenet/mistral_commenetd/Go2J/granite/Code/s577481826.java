
// Importing required packages
import java.util.Scanner;

// s577481826 class
public class s577481826{
    // s577481826 method
    public static void main(String[] args) {
        // Creating a scanner for reading input from stdin
        Scanner sc = new Scanner(System.in);

        // Reading the first integer 'a' from stdin
        int a = sc.nextInt();

        // Reading the second integer 'b' from stdin
        int b = sc.nextInt();

        // Calculating the sum of 'a' and 'b'
        int ret = a + b;

        // Checking if the sum is less than the difference of 'a' and 'b'
        if (ret < (a - b)) {
            // If true, then update the value of'ret'
            ret = a - b;
        }

        // Checking if the sum is less than the product of 'a' and 'b'
        if (ret < (a * b)) {
            // If true, then update the value of'ret'
            ret = a * b;
        }

        // Printing the final value of'ret'
        System.out.println(ret);

        // End of the code
        sc.close();
    }
}

