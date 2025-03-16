import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Initialize a constant N for the size of the arrays
        final int N = 368;

        // Create two arrays to track the values for 'M' and 'F'
        int[] m = new int[N];  // Array to track 'M' values
        int[] f = new int[N];  // Array to track 'F' values

        // Read the number of operations from input
        int operations = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < operations; i++) {
            // Read the operation type and the indices a and b
            String[] input = scanner.nextLine().split(" ");
            String x = input[0];  // Operation type
            int a = Integer.parseInt(input[1]);  // Convert a to an integer
            int b = Integer.parseInt(input[2]) + 1;  // Convert b to an integer and increment by 1 for range adjustment

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
        int cumulativeM = 0, cumulativeF = 0, minValue = 0;

        // Iterate through the range of N to calculate cumulative sums and find the minimum
        for (int i = 0; i < N; i++) {
            cumulativeM += m[i];  // Update cumulative sum for 'M'
            cumulativeF += f[i];  // Update cumulative sum for 'F'

            // Update the minimum value if the current minimum of cumulativeM and cumulativeF is greater than minValue
            if (Math.min(cumulativeM, cumulativeF) > minValue) {
                minValue = Math.min(cumulativeM, cumulativeF);  // Set minValue to the new minimum value
            }
        }

        // Print the final minimum value found
        System.out.println(minValue);
        
        scanner.close();
    }
}
// <END-OF-CODE>
