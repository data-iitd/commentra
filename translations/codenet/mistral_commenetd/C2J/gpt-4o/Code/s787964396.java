import java.util.Scanner;

public class CountingSortExample {
    public static void main(String[] args) {
        // Declare variables
        int[] a, b;
        int max = 0, n;

        // Read the number of elements 'n' from the user
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        n = scanner.nextInt();

        // Allocate memory for arrays 'a' and 'b' of size (n+1)
        a = new int[n + 1];
        b = new int[n + 1];

        // Read elements of array 'a' from the user
        System.out.println("Enter " + n + " integers:");
        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
            // Update the maximum element if a new element is greater
            if (a[i] > max) max = a[i];
        }

        // Call the CountingSort function to sort the array 'a' using counting sort algorithm
        CountingSort(a, b, n);

        // Print the sorted elements of array 'b'
        System.out.print(b[1]);
        for (int i = 2; i <= n; i++) {
            System.out.print(" " + b[i]);
        }
        System.out.println();

        // Close the scanner
        scanner.close();
    }

    // Function to perform counting sort algorithm
    public static void CountingSort(int[] a, int[] b, int k) {
        // Declare an array 'c' of size 10000 to store the count of occurrences of each element
        int[] c = new int[10001]; // Adjusted size to accommodate max value

        // Initialize all elements of array 'c' to zero
        for (int i = 0; i <= 10000; i++) {
            c[i] = 0;
        }

        // Count the occurrences of each element in array 'a' and store it in array 'c'
        for (int j = 1; j <= k; j++) {
            c[a[j]]++;
        }

        // Calculate the cumulative sum of all elements in array 'c'
        for (int i = 1; i <= 10000; i++) {
            c[i] += c[i - 1];
        }

        // Sort the array 'b' by placing each element 'a[j]' at its correct position in array 'b'
        for (int j = k; j > 0; j--) {
            b[c[a[j]]] = a[j];
            c[a[j]]--;
        }
    }
}
// <END-OF-CODE>
