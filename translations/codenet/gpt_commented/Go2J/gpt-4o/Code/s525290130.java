import java.util.Scanner;

public class Main {
    
    // Method to reverse a portion of the array in place
    public static void reva(int[] b, int start, int end) {
        while (start < end) {
            // Swap the elements at positions start and end
            int temp = b[start];
            b[start] = b[end];
            b[end] = temp;
            start++;
            end--;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements in the array
        int n = sc.nextInt();
        int[] a = new int[n]; // Initialize an array of integers with length n

        // Populate the array with integers from input
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt(); // Read each integer and store it in the array
        }

        // Read the number of queries
        int q = sc.nextInt();
        // Process each query
        for (int i = 0; i < q; i++) {
            int b = sc.nextInt(); // Read the starting index for the reversal
            int e = sc.nextInt(); // Read the ending index for the reversal
            reva(a, b, e - 1); // Reverse the slice from index b to e-1
        }

        // Output the modified array
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                System.out.print(" "); // Print a space before each element except the first
            }
            System.out.print(a[i]); // Print the current element
        }
        System.out.println(); // Print a newline after the output
        sc.close(); // Close the scanner
    }
}

// <END-OF-CODE>
