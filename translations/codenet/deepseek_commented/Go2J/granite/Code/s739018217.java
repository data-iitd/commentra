

import java.util.Scanner;

public class s739018217{
    public static void main(String[] args) {
        // Declare variables to store the number of successful and failed runs
        int n, m;
        
        // Create a Scanner object to read input from the standard input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of successful and failed runs from the standard input
        n = scanner.nextInt();
        m = scanner.nextInt();
        
        // Close the Scanner object
        scanner.close();
        
        // Calculate the total time in milliseconds for the successful and failed runs
        int x = m*1900 + (n-m)*100;
        
        // Print the result of the expression (total time * 2^m)
        System.out.println(x * (int) Math.pow(2, m));
    }
}
