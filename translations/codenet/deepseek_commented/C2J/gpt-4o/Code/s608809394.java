import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the size of the array
        int n = scanner.nextInt();
        // Declare an array of size n
        int[] a = new int[n];
        
        // Read n integers and store them in the array a
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Initialize t to 0, which will store the final sum of products
        int t = 0;
        
        // Outer loop to iterate over each element in the array a
        for (int i = 0; i < n; i++) {
            // Initialize s to 0, which will store the sum of products for the current element
            int s = 0;
            
            // Inner loop to iterate over each element in the array a, skipping the current element
            for (int j = 0; j < n; j++) {
                if (j <= i) {
                    continue; // Skip the current element being processed by the outer loop
                }
                // Calculate the product of the current element and the current element in the inner loop
                int m = a[i] * a[j];
                // Add the product to the sum s
                s += m;
            }
            // Add the sum s to the final sum t
            t += s;
        }
        
        // Print the final sum of products
        System.out.println(t);
        
        scanner.close();
    }
}

// <END-OF-CODE>
