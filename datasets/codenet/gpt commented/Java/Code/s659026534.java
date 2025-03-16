import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        @SuppressWarnings("resource")
        Scanner scan = new Scanner(System.in);
        
        // Read an integer input from the user
        int n = scan.nextInt();
        
        // Initialize a variable to hold the sum of integers
        int count = 0;
        
        // Loop from 1 to n and accumulate the sum of integers
        for (int i = 1; i <= n; i++) {
            count += i; // Add the current integer to the count
        }
        
        // Output the total sum of integers from 1 to n
        System.out.println(count);
    }
}
