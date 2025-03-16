import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, a[] = new int[100], b[] = new int[100], sum = 0;
        n = in.nextInt(); // Read the number of elements

        // Read n integers into array a
        for (int i = 0; i < n; i++) a[i] = in.nextInt();

        // Read n integers into array b
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
            if (a[i] - b[i] > 0) { // Check if a[i] is greater than b[i]
                sum += a[i] - b[i]; // Add the difference to sum
            }
        }

        // Output the sum
        System.out.println(sum);
    }
}
