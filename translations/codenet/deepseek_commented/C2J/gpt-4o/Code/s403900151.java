import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, r, p, c;

        while (true) { // Loop until both n and r are zero
            n = scanner.nextInt();
            r = scanner.nextInt(); // Read the number of elements and the number of operations
            if (n == 0 && r == 0)
                break; // Exit the loop if both n and r are zero

            // Initialize array a with elements from 1 to n
            int[] a = new int[51];
            for (int i = 0; i < n; i++)
                a[i] = i + 1;

            // Perform r operations
            for (int i = 0; i < r; i++) {
                p = scanner.nextInt();
                c = scanner.nextInt(); // Read the position and count of elements to be moved

                // Copy the last c elements to be moved to array b
                int[] b = new int[c];
                for (int j = 0; j < c; j++)
                    b[j] = a[n - p - c + 1 + j];

                // Shift the first p-1 elements before the position where the c elements will be moved
                for (int j = 0; j < p - 1; j++)
                    a[n - p - c + 1 + j] = a[n - p + j + 1];

                // Place the elements from b back into array a at the correct position
                for (int j = n - p - c + 1, k = 0; k < c; j++, k++)
                    a[j] = b[k];

                // Uncomment the following block to print the array after each operation for debugging
                /*
                for (int j = 0; j < n; j++)
                    System.out.println(a[j]);
                System.out.println("---");
                */
            }
            // Print the last element of the array a after all operations
            System.out.println(a[n - 1]);
        }
        scanner.close();
    }
}
// <END-OF-CODE>
