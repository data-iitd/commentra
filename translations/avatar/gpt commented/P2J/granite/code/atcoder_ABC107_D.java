
import java.io.*;
import java.util.*;

class BIT {
    // Initialize the Binary Indexed Tree (BIT) with size N
    public BIT(int N) {
        size = N;  // Store the size of the BIT
        tree = new int[N + 1];  // Initialize the BIT array with zeros
        depth = N.bitLength();  // Calculate the depth of the BIT
    }

    // Internal method to calculate the prefix sum up to index i
    private int _bitsum(int i) {
        int ret = 0;  // Initialize the sum
        while (i > 0) {
            ret += tree[i];  // Add the value at index i to the sum
            i ^= i & -i;  // Move to the parent index
        }
        return ret;  // Return the calculated sum
    }

    // Public method to calculate the sum in the range [l, r]
    public int bitsum(int l, int r) {
        if (r == null) {
            return _bitsum(l);  // If r is not provided, return the sum up to l
        } else {
            return _bitsum(r) - _bitsum(l);  // Return the sum in the range [l, r]
        }
    }

    // Method to add a value x at index i
    public void bitadd(int i, int x) {
        i++;  // Adjust index to match BIT's 1-based indexing
        while (i <= size) {
            tree[i] += x;  // Update the BIT with the value x
            i += i & -i;  // Move to the next index
        }
    }

    private int size;  // Size of the BIT
    private int[] tree;  // Array to store the BIT values
    private int depth;  // Depth of the BIT
}

// Read the number of elements
int n = Integer.parseInt(br.readLine());
// Calculate the target value m based on the number of elements
int m = n * (n + 1) / 4;
// Read the input array and convert it to a list of integers
String[] input = br.readLine().split(" ");
List<Integer> a = new ArrayList<>();
for (String s : input) {
    a.add(Integer.parseInt(s));
}
// Create a sorted list of unique values from a, including 0
List<Integer> _a = new ArrayList<>(new HashSet<>(a));
Collections.sort(_a);
_a.add(0);

// Map original values to their indices in the sorted list
Map<Integer, Integer> d = new HashMap<>();
for (int i = 0; i < _a.size(); i++) {
    d.put(_a.get(i), i);
}
// Replace original values in a with their corresponding indices
for (int i = 0; i < a.size(); i++) {
    a.set(i, d.get(a.get(i)));
}

// Function to check if a certain value X can be achieved
boolean check(int X) {
    // Create a new list b where each element indicates if the corresponding a[i] is >= X
    List<Integer> b = new ArrayList<>();
    b.add(0);
    for (int y : a) {
        b.add((y >= X) * 2 - 1);
    }
    // Calculate the prefix sums of b
    for (int i = 1; i <= n; i++) {
        b.set(i, b.get(i) + b.get(i - 1));
    }
    int c = Collections.min(b);  // Find the minimum value in b
    b = b.stream().map(x -> x - c).collect(Collectors.toList());  // Normalize b by subtracting the minimum value
    BIT bit = new BIT(Collections.max(b) + 2);  // Initialize a BIT for the range of b
    int ans = 0;  // Initialize the answer counter
    // Count the number of valid pairs using the BIT
    for (int x : b) {
        ans += bit.bitsum(x + 1);  // Count how many indices have been added that are less than x
        bit.bitadd(x, 1);  // Add the current index to the BIT
    }
    return ans >= m;  // Return whether the count is at least m
}

// Initialize the binary search bounds
int[] t = {Collections.max(_a), 0};
// Perform binary search to find the maximum value that satisfies the condition
while (t[0] - t[1] > 1) {
    int mid = (t[0] + t[1]) / 2;  // Calculate the midpoint
    t[check(mid)? 1 : 0] = mid;  // Update the bounds based on the check function
}

// Print the result corresponding to the found index
System.out.println(_a.get(t[1]));

Translate the above Java code to C++ and end with comment "