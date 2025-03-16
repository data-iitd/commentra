import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        int n, k, o = 0;
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements (n) and the number of smallest elements to sum (k)
        n = scanner.nextInt();
        k = scanner.nextInt();
        int[] p = new int[n];

        // Read n integers into the array p
        for (int i = 0; i < n; i++) {
            p[i] = scanner.nextInt();
        }

        // Selection sort algorithm to sort the array p in ascending order
        for (int i = 0; i < n; i++) {
            int l = i; // Assume the minimum is the first element
            for (int j = i + 1; j < n; j++) {
                // Update l if a smaller element is found
                if (p[j] < p[l]) {
                    l = j;
                }
            }
            // Swap the found minimum element with the first element
            if (l != i) {
                int m = p[i];
                p[i] = p[l];
                p[l] = m;
            }
        }

        // Calculate the sum of the first k smallest elements in the sorted array
        for (int i = 0; i < k; i++) {
            o += p[i];
        }

        // Print the result: the sum of the k smallest elements
        System.out.println(o);
        
        scanner.close();
    }
}

// <END-OF-CODE>
