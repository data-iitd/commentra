import java.util.Scanner; // Importing Scanner for input operations

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for input

        // Read the number of vertices from the input
        int n = scanner.nextInt();

        // Initialize an answer array of size n
        int[] ans = new int[n];

        // Read the edges and increment the count of each vertex in the answer array
        for (int i = 0; i < n - 1; i++) {
            int a = scanner.nextInt();
            a--; // Decrement the vertex index as it is 0-indexed
            ans[a]++; // Increment the count of the vertex
        }

        // Print the answer array
        for (int i = 0; i < n; i++) {
            System.out.println(ans[i]);
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
