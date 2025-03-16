import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements in the list `w`
        int n = scanner.nextInt();
        
        // Read the list of integers `w`
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = scanner.nextInt();
        }
        
        // Initialize the variable `c` to 2
        int c = 2;
        
        // Loop through each element `i` in the list `w`
        for (int i : w) {
            // Check if `i` is equal to 1
            if (i == 1) {
                // Print the current value of `c`
                System.out.println(c);
            }
            // Check if `i` is even
            else if (i % 2 == 0) {
                // Toggle the value of `c` between 2 and 3 (i.e., 1 or 3)
                c = 3 - c;
                // Print the new value of `c`
                System.out.println(c);
            }
            // If `i` is odd
            else {
                // Print the current value of `c`
                System.out.println(c);
            }
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
