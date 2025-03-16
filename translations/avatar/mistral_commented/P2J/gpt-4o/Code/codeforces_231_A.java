import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to take input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Take an integer 'n' as input from the user
        int n = scanner.nextInt();
        
        // Initialize a counter 'c' to 0
        int c = 0;
        
        // Iterate through the range of 'n'
        for (int i = 0; i < n; i++) {
            // Take 'n' lists of integers as input from the user
            int[] l1 = new int[n];
            for (int j = 0; j < n; j++) {
                l1[j] = scanner.nextInt();
            }
            
            // Check if the sum of the elements in the current list is greater than 1
            int sum = 0;
            for (int num : l1) {
                sum += num;
            }
            if (sum > 1) {
                // Increment the counter 'c' by 1 if the condition is true
                c++;
            }
        }
        
        // Print the value of the counter 'c'
        System.out.println(c);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
