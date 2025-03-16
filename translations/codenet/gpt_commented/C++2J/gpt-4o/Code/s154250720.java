import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Define constants for maximum size
    static final int maxn = 200000 + 10;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] maps = new int[maxn];
        int[] num = new int[maxn];

        // Continuously read input until EOF
        while (scanner.hasNextInt()) {
            int n = scanner.nextInt(); // Variable to hold the number of elements
            
            // Read n integers into the maps array and copy to num array
            for (int i = 1; i <= n; i++) {
                maps[i] = scanner.nextInt();
                num[i] = maps[i];
            }

            // Sort the maps array to find the median
            Arrays.sort(maps, 1, n + 1);
            
            // Calculate the index for the median element
            int m = n / 2;

            // For each element in the original array, determine and print the appropriate value
            for (int i = 1; i <= n; i++) {
                // If the current number is less than or equal to the median
                if (num[i] <= maps[m]) {
                    // Print the next higher number (the one after the median)
                    System.out.println(maps[m + 1]);
                } else {
                    // Print the median value
                    System.out.println(maps[m]);
                }
            }
        }
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
