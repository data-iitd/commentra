import java.util.*; // Importing the utility package for Scanner
import java.lang.*; // Importing the lang package (not necessary here, but included)
import java.io.*; // Importing the io package (not necessary here, but included)

public class Main {
    public static void main(String[] args) throws java.lang.Exception {
        // Creating a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Reading an integer input from the user
        int n = sc.nextInt();
        
        // Printing the input number
        System.out.println(n + " ");
        
        // Initializing a variable m to hold the current divisor, starting with n
        int m = n;
        
        // Looping from n-1 down to 1 to find and print all divisors of n
        for (int i = n - 1; i > 0; i--) {
            // Checking if i is a divisor of m
            if (m % i == 0) {
                // Printing the divisor
                System.out.println(i + " ");
                // Updating m to the current divisor
                m = i;
            }
        }
    }
}
