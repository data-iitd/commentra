import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(); // Read the value of n
        int m = scanner.nextInt(); // Read the value of m
        int x = scanner.nextInt(); // Read the value of x
        
        int[] a = new int[106]; // Initialize array to keep track of positions (size 106 to accommodate 0 to n)
        
        for (int i = 0; i < m; ++i) {
            int temp = scanner.nextInt(); // Read the positions to be marked
            a[temp] = 1; // Mark the positions in array a
        }
        
        int ansl = 0, ansr = 0; // Initialize variables to store distances
        
        for (int i = x; i <= n; ++i) { // Calculate the number of marked positions to the right of x
            ansr += a[i];
        }
        
        for (int i = x; i >= 0; --i) { // Calculate the number of marked positions to the left of x
            ansl += a[i];
        }
        
        System.out.println(Math.min(ansl, ansr)); // Print the minimum of the left and right distances
        
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
