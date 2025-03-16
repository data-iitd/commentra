import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.TreeMap;

public class Main {
    private int n; // Number of elements in the array
    private int[] a; // Array to store the input integers
    private TreeMap<Integer, Integer> s; // TreeMap to keep track of counts of integers

    public static void main(String[] args) {
        // Create an instance of Main and invoke the solve method
        Main m = new Main();
        m.solve();
    }

    private void set() {
        // Read input values and initialize variables
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            n = Integer.parseInt(br.readLine()); // Read the number of elements
            // Read the array elements and convert them to an integer array
            a = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            s = new TreeMap<>(); // Initialize the TreeMap
        } catch (IOException e) {
            e.printStackTrace(); // Handle any IO exceptions
        }
    }

    private void solve() {
        // Main logic to find the maximum k using binary search
        set(); // Initialize input values
        int ng = 0; // Lower bound for binary search
        int ok = n; // Upper bound for binary search

        // Perform binary search to find the maximum k
        while (ok - ng > 1) {
            int k = (ng + ok) / 2; // Calculate mid-point
            // Check if it is possible to achieve the current k
            if (isPossible(k)) {
                ok = k; // If possible, adjust upper bound
            } else {
                ng = k; // If not possible, adjust lower bound
            }
        }
        // Output the result
        System.out.println(ok);
    }

    private boolean isPossible(int k) {
        // Check if it is possible to achieve the given k
        s.clear(); // Clear the TreeMap for new calculations
        int current = 0; // Initialize current value

        // Iterate through each element in the array
        for (int ai : a) {
            // If the current element is less than or equal to the current value
            if (ai <= current) {
                // If k is 1, return false as we cannot have duplicates
                if (k == 1) return false;

                // Remove elements from TreeMap that are greater than or equal to ai
                while (!s.isEmpty() && s.lastKey() >= ai) {
                    s.pollLastEntry(); // Remove the last entry
                }

                int p = ai - 1; // Start checking from the previous number
                while (true) {
                    // If p is less than 0, return false
                    if (p < 0) return false;

                    // Get the count of p from TreeMap and increment it
                    int sp = s.getOrDefault(p, 0) + 1;
                    s.put(p, sp); // Update the TreeMap with the new count

                    // If the count reaches k, remove p from TreeMap and decrement p
                    if (sp == k) {
                        s.remove(p);
                        p--;
                    } else {
                        break; // Exit the loop if count is less than k
                    }
                }
            }
            current = ai; // Update current to the current element
        }
        return true; // Return true if the condition is satisfied
    }
}
