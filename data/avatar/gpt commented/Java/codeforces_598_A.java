import java.util.*; // Importing the utility package for Scanner class

public class Main {
    public static void main(String args[]) {
        // Creating a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Reading the number of test cases
        int q = sc.nextInt();
        
        // Looping through each test case
        while (q-- > 0) {
            // Reading the integer n for the current test case
            int n = sc.nextInt();
            
            // Initializing a variable to store the result
            long s = 0;
            
            // Calculating the highest power of 2 less than or equal to n
            int x = (int) (Math.log(n) / Math.log(2));
            x++;
            
            // Calculating the final result using the derived formula
            s = -1 * (long) Math.pow(2, x) + 2 + ((long) n * (long) (n + 1)) / 2 - (long) Math.pow(2, x);
            
            // Printing the result for the current test case
            System.out.println(s);
        }
        
        // Closing the scanner to prevent resource leaks
        sc.close();
    }
}
