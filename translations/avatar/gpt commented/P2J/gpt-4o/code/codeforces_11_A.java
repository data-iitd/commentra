import java.util.Scanner;

public class Adjustments {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers n and d from input
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        
        // Initialize an array to store the elements
        int[] x = new int[n];
        
        // Read the elements of the list from input
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
        }
        
        // Initialize variables to keep track of the total adjustments (m) and the current adjustment count (q)
        int m = 0;
        int q;
        
        // Iterate through the list to compare adjacent elements
        for (int a = 0; a < n - 1; a++) {
            // Check if the current element is greater than or equal to the next element
            if (x[a] >= x[a + 1]) {
                // Calculate how many increments of d are needed to make x[a + 1] greater than x[a]
                q = (x[a] - x[a + 1]) / d + 1;
                // Update the total adjustments made
                m += q;
                // Adjust the next element by adding the necessary increments of d
                x[a + 1] += q * d;
            }
        }
        
        // Print the total number of adjustments made
        System.out.println(m);
        
        scanner.close();
    }
}
// <END-OF-CODE>
