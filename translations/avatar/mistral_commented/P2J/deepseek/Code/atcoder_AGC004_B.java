public class Main {
    public static void main(String[] args) {
        // Take input of number of test cases and number of elements in each test case
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();

        // Initialize an empty list 'a' to store the given elements
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Initialize a 2D list 'b' of size n x n with None values
        int[][] b = new int[n][n];

        // Iterate through each row of list 'a'
        for (int i = 0; i < n; i++) {
            // Initialize a variable 'm' to store the minimum element in the current row
            int m = a[i];

            // Iterate through each column of list 'b'
            for (int j = 0; j < n; j++) {
                // Calculate the index 'k' based on the current row and column indices
                int k = i - j;

                // If the index 'k' is negative, add the size of list 'n' to make it positive
                if (k < 0) {
                    k += n;
                }

                // Update the minimum value of 'm' with the minimum value of 'a[k]'
                m = Math.min(m, a[k]);

                // Update the corresponding cell in list 'b' with the minimum value of 'm'
                b[j][i] = m;
            }
        }

        // Initialize a variable 'm' with a large value to keep track of the minimum sum
        int minSum = Integer.MAX_VALUE;

        // Iterate through each row of list 'b'
        for (int i = 0; i < n; i++) {
            // Calculate the sum of elements in the current row and add 'x * i' to it
            int sumRow = 0;
            for (int j = 0; j < n; j++) {
                sumRow += b[i][j];
            }
            sumRow += x * i;

            // Update the minimum value of 'm' with the sum of the current row
            minSum = Math.min(minSum, sumRow);
        }

        // Print the minimum sum
        System.out.println(minSum);
    }
}
