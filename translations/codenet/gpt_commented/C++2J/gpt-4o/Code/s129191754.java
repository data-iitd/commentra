import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = scanner.nextInt();
        
        // Initialize an array to store the elements
        int[] a = new int[n];
        
        // Read the elements from input
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Sort the array to facilitate duplicate checking
        Arrays.sort(a);
        
        // Check for duplicates in the sorted array
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) {
                // If a duplicate is found, print "NO" and exit
                System.out.println("NO");
                return;
            }
        }
        
        // If no duplicates are found, print "YES"
        System.out.println("YES");
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
