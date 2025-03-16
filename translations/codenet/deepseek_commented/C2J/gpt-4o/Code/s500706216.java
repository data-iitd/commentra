import java.util.Scanner;

public class Main {
    // Define the size of the arrays
    static final int MAX_SIZE = 200000;

    public static void main(String[] args) {
        // Declare the arrays and variables
        int[] a = new int[MAX_SIZE];
        int[] tmpa = new int[MAX_SIZE];
        int[] light = new int[MAX_SIZE + 10];

        // Declare variables for input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        // Read n integers from standard input and store them in array a
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Initialize the light array based on the initial positions of the lights
        for (int i = 0; i < n; i++) {
            int r = i - a[i];
            int l = i + a[i];
            light[Math.max(0, r)]++;
            if (l + 1 <= n) {
                light[l + 1]--;
            }
        }

        // Apply the lights k times
        for (int i = 0; i < k; i++) {
            int sum = 0;
            // Update array a based on the light array
            for (int j = 0; j < n; j++) {
                tmpa[j] = a[j];
                sum += light[j];
                a[j] = sum;
            }

            // Adjust the light array based on the new state of array a
            for (int j = 0; j < n; j++) {
                int r = j - tmpa[j];
                int l = j + tmpa[j];
                light[Math.max(0, r)]--;
                if (l + 1 <= n) {
                    light[l + 1]++;
                }
                r = j - a[j];
                l = j + a[j];
                light[Math.max(0, r)]++;
                if (l + 1 <= n) {
                    light[l + 1]--;
                }
            }

            // Check if the array a has become stable
            boolean isSame = true;
            for (int j = 0; j < n - 1; j++) {
                if (a[j] != a[j + 1]) {
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
            if (j < n - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();

        scanner.close();
    }
}

// <END-OF-CODE>
