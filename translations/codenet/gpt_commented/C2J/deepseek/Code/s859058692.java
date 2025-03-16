public class SumMinMax {
    public static void main(String[] args) {
        // Initialize variables to store the sum, current number, count of numbers, and min/max values
        long sum = 0; // To hold the sum of all numbers
        int n, m, i, min, max; // m: current number, n: total count of numbers, i: loop index, min: minimum value, max: maximum value

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read the total number of integers to be processed
        n = scanner.nextInt();

        // Initialize min and max with the first number read
        m = scanner.nextInt();
        min = m; // Set min to the first number
        max = m; // Set max to the first number
        sum = m; // Add the first number to the sum

        // Loop through each number to read and process
        for(i = 1; i < n; i++) {
            // Read the current number
            m = scanner.nextInt();
            
            // Add the current number to the sum
            sum += m;

            // Update min if the current number is less than the current min
            if(min > m) {
                min = m; // Update min
            }

            // Update max if the current number is greater than the current max
            if(max < m) {
                max = m; // Update max
            }
        }

        // Print the minimum, maximum, and sum of the numbers
        System.out.println(min + " " + max + " " + sum);
    }
}
