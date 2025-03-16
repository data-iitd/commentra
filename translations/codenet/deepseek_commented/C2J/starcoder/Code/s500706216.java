import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Declare variables for input
        int n, k;

        // Read the values of n and k from standard input
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();

        // Read n integers from standard input and store them in array a
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        // Initialize the light array based on the initial positions of the lights
        int[] light = new int[n + 10];
        for (int i = 0; i < n; i++) {
            int r, l;
            r = i - a[i];
            l = i + a[i];
            light[(r < 0? 0 : r)]++;
            light[(l + 1 > n? n + 1 : l + 1)]--;
        }

        // Apply the lights k times
        for (int i = 0; i < k; i++) {
            int sum = 0;
            // Update array a based on the light array
            for (int j = 0; j < n; j++) {
                sum += light[j];
                a[j] = sum;
            }

            // Adjust the light array based on the new state of array a
            for (int j = 0; j < n; j++) {
                int r = j - a[j];
                int l = j + a[j];
                light[(r < 0? 0 : r)]--;
                light[(l + 1 > n? n + 1 : l + 1)]++;
                r = j - a[j];
                l = j + a[j];
                light[(r < 0? 0 : r)]++;
                light[(l + 1 > n? n + 1 : l + 1)]--;
            }

            // Check if the array a has become stable
            boolean isSame = true;
            for (int j = 0; j < n - 1; j++) {
                if (a[j]!= a[j + 1]) {
                    isSame = false;
                    break;
                }
            }

            // Check if the array a is stable and the first element is n
            if (isSame && a[0] == n) {
                break;
            }
        }

        // Print the final state of array a
        for (int j = 0; j < n; j++) {
            System.out.print(a[j]);
            System.out.print(j == n - 1? "\n" : " ");
        }
    }
}

