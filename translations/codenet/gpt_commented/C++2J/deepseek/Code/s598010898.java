public class Main {
    public static void main(String[] args) {
        // Declare variables
        int n;
        int[] a = new int[100];
        int[] b = new int[100];
        int sum = 0;

        // Create a Scanner object to read input
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read the number of elements
        n = scanner.nextInt();

        // Input the first array 'a'
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Input the second array 'b' and calculate the sum of positive differences
        for (int i = 0; i < n; i++) {
            b[i] = scanner.nextInt(); // Read each element of array 'b'

            // Check if the difference between corresponding elements of 'a' and 'b' is positive
            if (a[i] - b[i] > 0) {
                // If positive, add the difference to 'sum'
                sum += a[i] - b[i];
            }
        }

        // Output the final sum of positive differences
        System.out.println(sum);
    }
}
