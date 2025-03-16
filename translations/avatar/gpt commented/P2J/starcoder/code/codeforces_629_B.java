import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Initialize a constant N for the size of the arrays
        int N = 368;

        // Create two lists to track the values for 'M' and 'F'
        int[] m = new int[N];  // List to track 'M' values
        int[] f = new int[N];  // List to track 'F' values

        // Read the number of operations from input
        int n = sc.nextInt();

        // Read the operations from input
        for (int i = 0; i < n; i++) {
            // Read the operation type and the indices a and b
            String x = sc.next();
            int a = sc.nextInt();
            int b = sc.nextInt() + 1;  // Increment b by 1 for range adjustment

            // Update the corresponding list based on the operation type
            if (x.equals("M")) {
                m[a] += 2;  // Increment the value at index a in the 'M' list
                m[b] -= 2;  // Decrement the value at index b in the 'M' list
            } else {
                f[a] += 2;  // Increment the value at index a in the 'F' list
                f[b] -= 2;  // Decrement the value at index b in the 'F' list
        }

        // Initialize variables to track cumulative sums and the minimum value
        int a = 0, b = 0, c = 0;

        // Iterate through the range of N to calculate cumulative sums and find the minimum
        for (int i = 0; i < N; i++) {
            a += m[i];  // Update cumulative sum for 'M'
            b += f[i];  // Update cumulative sum for 'F'
            
            // Update the minimum value if the current minimum of a and b is greater than c
            if (Math.min(a, b) > c) {
                c = Math.min(a, b);  // Set c to the new minimum value
        }

        // Print the final minimum value found
        System.out.println(c);
    }
}

