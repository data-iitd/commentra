public class LightPropagation {
    // Define the size of the arrays
    static final int MAX_SIZE = 200000;

    // Declare the arrays and variables
    static int[] a = new int[MAX_SIZE];
    static int[] tmpa = new int[MAX_SIZE];
    static int[] light = new int[MAX_SIZE + 10];

    public static void main(String[] args) {
        // Declare variables for input
        int n, k;

        // Read the values of n and k from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();

        // Read n integers from standard input and store them in array a
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Initialize the light array based on the initial positions of the lights
        for (int i = 0; i < n; i++) {
            int r, l;
            r = i - a[i];
            l = i + a[i];
            if (r < 0) r = 0;
            light[r]++;
            if (l + 1 > n) l = n + 1;
            light[l + 1]--;
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
                if (r < 0) r = 0;
                light[r]--;
                if (l + 1 > n) l = n + 1;
                light[l + 1]++;
                r = j - a[j];
                l = j + a[j];
                if (r < 0) r = 0;
                light[r]++;
                if (l + 1 > n) l = n + 1;
                light[l + 1]--;
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
    }
}
