
import java.util.Scanner;

public class codeforces_629_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Initialize a constant N for the size of the arrays
        int N = 368;

        // Create two arrays to track the values for 'M' and 'F'
        int[] m = new int[N];  // Array to track 'M' values
        int[] f = new int[N];  // Array to track 'F' values

        // Read the number of operations from input
        for (int i = 0; i < scanner.nextInt(); i++) {
            // Read the operation type and the indices a and b
            String x = scanner.next();
            int a = scanner.nextInt();
            int b = scanner.nextInt() + 1;  // Increment b by 1 for range adjustment

            // Update the corresponding array based on the operation type
            if (x.equals("M")) {
                m[a] += 2;  // Increment the value at index a in the 'M' array
                m[b] -= 2;  // Decrement the value at index b in the 'M' array
            } else {
                f[a] += 2;  // Increment the value at index a in the 'F' array
                f[b] -= 2;  // Decrement the value at index b in the 'F' array
            }
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
        }

        // Print the final minimum value found
        System.out.println(c);
    }
}
