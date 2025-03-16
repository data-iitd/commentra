import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, ans; // Declare variables for size of vector and answer count
        n = scanner.nextInt(); // Input the size of the vector
        ArrayList<Integer> p = new ArrayList<>(n); // Initialize a list of size n

        // Input the elements of the vector
        for (int i = 0; i < n; i++) {
            p.add(scanner.nextInt()); // Read each element into the list
        }

        ans = 0; // Initialize the answer counter to zero

        // Loop through the list to check for specific conditions
        for (int i = 0; i < n - 1; i++) {
            // Check if the current element matches its expected position (1-based index)
            if (p.get(i) == i + 1) {
                p.set(i + 1, p.get(i)); // Set the next element to the current element
                ans += 1; // Increment the answer counter
            }
        }

        // Check if the last element matches its expected position
        if (p.get(n - 1) == n) {
            ans += 1; // Increment the answer counter if the condition is met
        }

        System.out.println(ans); // Output the final count of matches
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
