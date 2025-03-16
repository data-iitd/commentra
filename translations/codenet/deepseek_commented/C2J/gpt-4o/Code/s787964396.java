import java.util.Scanner;

public class CountingSort {
    static final int I = 10000; // Define a constant I with the value 10000

    // Function to perform Counting Sort
    public static void countingSort(int[] a, int[] b, int k) {
        int[] c = new int[I + 1];

        // Initialize array c to store the count of each element
        for (int i = 0; i <= I; i++) {
            c[i] = 0;
        }

        // Count the occurrences of each element in array a
        for (int j = 0; j < k; j++) {
            c[a[j + 1]]++;
        }

        // Compute the cumulative count to determine the positions of elements in the sorted array
        for (int i = 1; i <= I; i++) {
            c[i] += c[i - 1];
        }

        // Place elements into array b in sorted order
        for (int j = k; j > 0; j--) {
            b[c[a[j]]] = a[j];
            c[a[j]]--;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = scanner.nextInt();
        
        // Dynamically allocate memory for arrays a and b
        int[] a = new int[n + 1];
        int[] b = new int[n + 1];
        
        // Read elements into array a starting from index 1 to n
        for (int i = 0; i < n; i++) {
            a[i + 1] = scanner.nextInt();
        }
        
        // Call countingSort function to sort the array
        countingSort(a, b, n);
        
        // Print the sorted elements starting from index 1 to n
        System.out.print(b[1]);
        for (int i = 2; i < n + 1; i++) {
            System.out.print(" " + b[i]);
        }
        System.out.println();
        
        scanner.close();
    }
}

// <END-OF-CODE>
