import java.util.Scanner; // Import the Scanner class for input

public class Main { // Declare the Main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n, k; // Declare two integer variables n and k
        int[] p = new int[99999]; // Declare an array p of integers with a size of 99999
        int o = 0; // Declare an integer variable o and initialize it to 0

        n = scanner.nextInt(); // Read the first integer from input
        k = scanner.nextInt(); // Read the second integer from input

        for (int i = 0; i < n; i++) { // Iterate through the array p from index 0 to n-1
            p[i] = scanner.nextInt(); // Read an integer from input and store it in the array p at index i
        }

        for (int i = 0; i < n; i++) { // Iterate through the array p from index 0 to n-1
            int l = i; // Initialize variable l to i
            for (int j = i + 1; j < n; j++) { // Iterate through the array p from index i+1 to n-1
                if (p[j] < p[l]) { // If the element at index j is smaller than the element at index l
                    l = j; // Update the index of the smallest element
                }
            }
            if (l != i) { // If the index of the smallest element is not equal to i
                int m = p[i]; // Swap the elements at indices i and l
                p[i] = p[l];
                p[l] = m;
            }
        }

        for (int i = 0; i < k; i++) { // Iterate through the array p from index 0 to k-1
            o += p[i]; // Add the element at index i to the variable o
        }

        System.out.println(o); // Print the value of the variable o to the standard output
        scanner.close(); // Close the scanner
    }
} // End of Main class
// <END-OF-CODE>
