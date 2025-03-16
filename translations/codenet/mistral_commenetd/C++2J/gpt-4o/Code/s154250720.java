import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Define maximum size of the input array 'n'
    static final int maxn = 200000 + 10; 
    static int[] maps = new int[maxn];
    static int[] num = new int[maxn];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Start an infinite loop to read multiple test cases
        while (scanner.hasNextInt()) {
            // Read input size 'n'
            int n = scanner.nextInt();
            
            // Initialize 'maps' and 'num' arrays with input values
            for (int i = 1; i <= n; i++) {
                maps[i] = scanner.nextInt();
                num[i] = maps[i]; // copy input values to 'num' array
            }
            
            // Sort 'maps' array in ascending order
            Arrays.sort(maps, 1, n + 1);
            
            // Calculate the middle index 'm' of sorted 'maps' array
            int m = n / 2;
            
            // Process each element in 'num' array based on the middle index 'm'
            for (int i = 1; i <= n; i++) {
                // If current element 'num[i]' is smaller than or equal to middle element 'maps[m]'
                if (num[i] <= maps[m]) {
                    // Print the next element in sorted 'maps' array
                    System.out.println(maps[m + 1]);
                } else {
                    // Otherwise print the current middle element 'maps[m]'
                    System.out.println(maps[m]);
                }
            }
        }
        
        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
