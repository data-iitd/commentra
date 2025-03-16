
import java.util.*;

public class s598010898{
    public static void main(String[] args) {
        // Declare variables
        int n, a[] = new int[100], b[] = new int[100], sum = 0;

        // Read the number of elements
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // Input the first array 'a'
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        // Input the second array 'b' and calculate the sum of positive differences
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt(); // Read each element of array 'b'

            // Check if the difference between corresponding elements of 'a' and 'b' is positive
            if (a[i] - b[i] > 0) {
                // If positive, add the difference to'sum'
                sum += a[i] - b[i];
            }
        }

        // Output the final sum of positive differences
        System.out.println(sum);

        sc.close(); // Close the scanner
    }
}
