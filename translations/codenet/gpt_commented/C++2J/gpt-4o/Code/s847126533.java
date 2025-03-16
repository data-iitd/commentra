import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Function to check if it is possible to distribute weights
    public static boolean check(int n, int wei, List<Integer> book) {
        int tmp = wei; // Temporary variable to hold the remaining weight
        n--; // Decrease the number of available books by one
        for (int i = 0; i < book.size(); i++) {
            // If the current weight exceeds the available weight
            if (tmp < book.get(i)) {
                // If there are still books left to use
                if (n > 0) {
                    n--; // Use one book
                    tmp = wei; // Reset the temporary weight to the original weight
                    // Check again if the current weight exceeds the available weight
                    if (tmp < book.get(i))
                        return false; // Not possible to distribute
                } else {
                    return false; // No books left to use
                }
            }
            // Deduct the current book's weight from the temporary weight
            tmp -= book.get(i);
        }
        return true; // Successfully distributed the weights
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m, n; // m: maximum weight, n: number of books
        // Read input until m is zero
        while (true) {
            m = scanner.nextInt();
            n = scanner.nextInt();
            if (m == 0) break;

            List<Integer> book = new ArrayList<>(); // List to store the weights of the books
            // Read the weights of the books
            for (int i = 0; i < n; i++) {
                int tmp = scanner.nextInt(); // Read each book's weight
                book.add(tmp); // Add weight to the list
            }

            int l = 0; // Lower bound for binary search
            int r = 1500000; // Upper bound for binary search
            int ans = 0; // Variable to store the answer
            // Perform binary search to find the maximum weight that can be distributed
            while (l < r) {
                int mid = (l + r) / 2; // Calculate the middle point
                // Check if the middle weight can be distributed
                if (check(m, mid, book)) {
                    ans = mid; // Update answer
                    // If the upper bound equals the middle, break the loop
                    if (r == mid)
                        break;
                    r = mid; // Move the upper bound down
                } else {
                    // If the lower bound equals the middle, break the loop
                    if (l == mid)
                        break;
                    l = mid + 1; // Move the lower bound up
                }
            }
            System.out.println(ans); // Output the maximum weight that can be distributed
        }
        scanner.close();
    }
}

// <END-OF-CODE>
