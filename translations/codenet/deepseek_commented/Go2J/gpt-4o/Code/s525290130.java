import java.util.Scanner; // For reading input efficiently
import java.util.Arrays; // For array operations

public class Main {
    
    // reva takes an array of integers and reverses it in place.
    public static void reva(int[] b) {
        int n = b.length;
        for (int i = 0; i < n / 2; i++) {
            int temp = b[i];
            b[i] = b[n - 1 - i];
            b[n - 1 - i] = temp;
        }
    }

    // main is the entry point of the program.
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt(); // Reads the number of elements
        int[] a = new int[n]; // Initializes an array of integers with size n
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt(); // Reads each element and assigns it to the array
        }
        
        int q = sc.nextInt(); // Reads the number of queries
        for (int i = 0; i < q; i++) {
            int b = sc.nextInt(); // Reads the start index of the segment to reverse
            int e = sc.nextInt(); // Reads the end index of the segment to reverse
            reva(Arrays.copyOfRange(a, b, e)); // Reverses the segment of the array
        }
        
        // Output the final array
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                System.out.print(" "); // Adds a space between elements, except before the first element
            }
            System.out.print(a[i]); // Writes the element to the output
        }
        System.out.println(); // Adds a newline after all elements
    }
}

// <END-OF-CODE>
