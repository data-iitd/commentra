public class Main {
    public static void main(String[] args) {
        // Declare variables
        int n, i, j, q;
        int[] x = new int[10000];
        int[] y = new int[500];
        int sum = 0;

        // Read the number of elements in array x
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();

        // Read n elements into array x
        for (i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
        }

        // Read the number of queries
        q = scanner.nextInt();

        // Read q elements into array y
        for (i = 0; i < q; i++) {
            y[i] = scanner.nextInt();
        }

        // Initialize sum to count how many elements in y are found in x
        for (i = 0; i < q; i++) {
            // Check each element in y against all elements in x
            for (j = 0; j < n; j++) {
                // If a match is found, increment sum and break the inner loop
                if (y[i] == x[j]) {
                    sum = sum + 1;
                    break;
                }
            }
        }

        // Output the total count of matches found
        System.out.println(sum);
    }
}
