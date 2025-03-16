

import java.util.Scanner;

public class s558200435{
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
        int j = 0;

        // Iterate through each element 'v' in array 'a'
        for (int i = 0; i < n; i++) {
            int v = a[i];

            // Use 'Arrays.binarySearch' function to find the index 'x' where 'v' should be inserted in array 'b'
            int x = Arrays.binarySearch(b, 0, j, v);

            // If 'x' is equal to -1, it means 'v' is not present in the array, so insert it at index 'j'
            if (x < 0) {
                x = -x - 1;
                System.arraycopy(b, x, b, x + 1, j - x);
                b[x] = v;
                j++;
            }
        }

        // Print the length of array 'b' as the output
        System.out.println(j);

        // End of the code
    }
}

