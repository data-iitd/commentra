
import java.util.*;

public class s598010898{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // Read the number of elements
        int[] a = new int[n]; // Create an array a with length n
        int[] b = new int[n]; // Create an array b with length n
        int sum = 0; // Initialize sum to 0

        // Read n integers into array a
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        // Read n integers into array b
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
            if (a[i] - b[i] > 0) { // Check if a[i] is greater than b[i]
                sum += a[i] - b[i]; // Add the difference to sum
            }
        }

        // Output the sum
        System.out.println(sum);
    }
}
