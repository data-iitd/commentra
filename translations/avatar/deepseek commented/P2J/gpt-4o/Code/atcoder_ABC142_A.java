import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the value of n from input
        int n = scanner.nextInt();
        
        // Initialize a counter to keep track of odd numbers
        int t = 0;
        
        // Loop through each number from 0 to n-1
        for (int i = 0; i < n; i++) {
            // Check if the current index plus one is odd
            if ((i + 1) % 2 == 1) {
                // Increment the counter if the condition is true
                t++;
            }
        }
        
        // Calculate the ratio of odd numbers to the total numbers and print it
        System.out.println((double) t / n);
        
        scanner.close();
    }
}

// <END-OF-CODE>
