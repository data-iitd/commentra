import java.util.Scanner;

public class Main {
    // The main function is the entry point of the program
    public static void main(String[] args) {
        // Create a Scanner object for reading input
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers n and k from the standard input
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Initialize variable cnt to zero
        int cnt = 0;
        
        // Loop through n times using a while loop
        while (n-- > 0) {
            // Read an integer h from the standard input
            int h = scanner.nextInt();
            // If h is greater than or equal to k, increment cnt by 1
            if (h >= k) {
                cnt++;
            }
        }
        
        // Print the value of cnt to the standard output
        System.out.println(cnt);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
