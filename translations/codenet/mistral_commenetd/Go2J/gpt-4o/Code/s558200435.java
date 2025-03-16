import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize the variable 'n' to read the number of elements in the array 'a'
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Create an array 'a' of length 'n' to store the input elements
        int[] a = new int[n];

        // Read 'n' elements from the standard input and store them in array 'a'
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Initialize an empty array 'b' to store the unique elements
        int[] b = new int[n];
        int bSize = 0;

        // Iterate through each element 'v' in array 'a'
        for (int v : a) {
            // Use binary search to find the index 'x' where 'v' should be inserted in array 'b'
            int x = Arrays.binarySearch(b, 0, bSize, v);
            if (x < 0) {
                // If 'v' is not present in 'b', 'x' will be negative, so we calculate the insertion point
                x = -(x + 1);
                // Insert 'v' into 'b' at the found index
                if (bSize < b.length) {
                    System.arraycopy(b, x, b, x + 1, bSize - x);
                }
                b[x] = v;
                bSize++;
            }
        }

        // Print the length of array 'b' as the output
        System.out.println(bSize);

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
