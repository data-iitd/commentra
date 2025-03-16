import java.util.*;

class BIT {
    private int size; // Store the size of the BIT
    private long[] tree; // Initialize the BIT array

    // Initialize the Binary Indexed Tree (BIT) with size N
    public BIT(int N) {
        this.size = N; // Store the size of the BIT
        this.tree = new long[N + 1]; // Initialize the BIT array with zeros
    }

    // Internal method to calculate the prefix sum up to index i
    private long bitsum(int i) {
        long ret = 0; // Initialize the sum
        while (i > 0) {
            ret += tree[i]; // Add the value at index i to the sum
            i -= i & -i; // Move to the parent index
        }
        return ret; // Return the calculated sum
    }

    // Public method to calculate the sum in the range [l, r]
    public long bitsum(int l, int r) {
        return bitsum(r) - bitsum(l - 1); // Return the sum in the range [l, r]
    }

    // Method to add a value x at index i
    public void bitadd(int i, long x) {
        while (i <= size) {
            tree[i] += x; // Update the BIT with the value x
            i += i & -i; // Move to the next index
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = scanner.nextInt();
        // Calculate the target value m based on the number of elements
        long m = n * (n + 1) / 4;
        // Read the input array and convert it to a list of integers
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        Map<Integer, Integer> d = new HashMap<>(); // Dictionary to hold the mapping of values to their indices
        TreeSet<Integer> uniqueValues = new TreeSet<>(); // To hold unique values
        
        // Create a sorted list of unique values from a, including 0
        for (int value : a) {
            uniqueValues.add(value);
        }
        uniqueValues.add(0);
        
        // Map original values to their indices in the sorted list
        int index = 0;
        for (int value : uniqueValues) {
            d.put(value, index++);
        }
        
        // Replace original values in a with their corresponding indices
        for (int i = 0; i < n; i++) {
            a[i] = d.get(a[i]);
        }

        // Function to check if a certain value X can be achieved
        boolean check(int X) {
            int[] b = new int[n + 1];
            b[0] = 0;
            for (int i = 0; i < n; i++) {
                b[i + 1] = b[i] + (a[i] >= X ? 1 : -1);
            }
            int c = Arrays.stream(b).min().getAsInt(); // Find the minimum value in b
            for (int i = 0; i <= n; i++) {
                b[i] -= c; // Normalize b by subtracting the minimum value
            }
            BIT bit = new BIT(Arrays.stream(b).max().getAsInt() + 2); // Initialize a BIT for the range of b
            long ans = 0; // Initialize the answer counter
            
            // Count the number of valid pairs using the BIT
            for (int x : b) {
                ans += bit.bitsum(x + 1); // Count how many indices have been added that are less than x
                bit.bitadd(x + 1, 1); // Add the current index to the BIT
            }
            return ans >= m; // Return whether the count is at least m
        }

        // Initialize the binary search bounds
        int[] t = {uniqueValues.size(), 0};
        // Perform binary search to find the maximum value that satisfies the condition
        while (t[0] - t[1] > 1) {
            int mid = (t[0] + t[1]) / 2; // Calculate the midpoint
            if (check(mid)) {
                t[1] = mid; // Update the bounds based on the check function
            } else {
                t[0] = mid; // Update the bounds based on the check function
            }
        }

        // Print the result corresponding to the found index
        System.out.println(uniqueValues.toArray()[t[1]]);
        
        scanner.close();
    }
}
// <END-OF-CODE>
