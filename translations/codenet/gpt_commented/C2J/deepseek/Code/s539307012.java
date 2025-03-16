public class Main {
    public static void main(String[] args) {
        // Declare variables
        int n, x, min, m, i;

        // Create a Scanner object to read input
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read the number of elements (n), a value (x), and the initial minimum value (min)
        n = scanner.nextInt();
        x = scanner.nextInt();
        min = scanner.nextInt();

        // Adjust x by subtracting the initial minimum value
        x -= min;

        // Loop through the remaining n-1 elements to read their values
        for(i = 1; i < n; i++) {
            // Read the next element into variable m
            m = scanner.nextInt();

            // Subtract the current element from x
            x -= m;

            // Update min if the current element is smaller than the current minimum
            if(min > m) {
                min = m;
            }
        }

        // Calculate and print the result based on the number of elements and the adjusted x divided by the minimum value
        System.out.println(n + x / min);
    }
}
