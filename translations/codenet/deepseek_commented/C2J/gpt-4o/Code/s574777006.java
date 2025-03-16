import java.util.Scanner;  // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        
        int n = scanner.nextInt();  // Read the number of elements
        int[] x = new int[10000];  // Declare array x
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();  // Read the elements of array x
        }
        
        int q = scanner.nextInt();  // Read the number of queries
        int[] y = new int[500];  // Declare array y
        for (int i = 0; i < q; i++) {
            y[i] = scanner.nextInt();  // Read the elements of array y
        }
        
        int sum = 0;  // Initialize sum
        for (int i = 0; i < q; i++) {  // For each query
            for (int j = 0; j < n; j++) {  // Check each element in array x
                if (y[i] == x[j]) {  // If the query matches an element in x
                    sum++;  // Increment the sum
                    break;  // Break out of the inner loop
                }
            }
        }
        
        System.out.println(sum);  // Print the sum of matches
        scanner.close();  // Close the scanner
    }
}

// <END-OF-CODE>
