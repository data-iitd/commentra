public class MinMaxSum {
    public static void main(String[] args) {
        // Declare variables
        int n, tmp; // n for number of inputs, tmp for temporary input storage
        long min = 1000000, max = -1000000, sum = 0; // Initialize min, max, and sum

        // Create a Scanner object to read input
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read the number of integers to be processed
        n = scanner.nextInt();
        
        // Loop to read n integers
        for(int i = 0; i < n; i++) {
            // Read the next integer
            tmp = scanner.nextInt();
            
            // Update min if the current number is smaller
            if(min > tmp) min = tmp;
            
            // Update max if the current number is larger
            if(max < tmp) max = tmp;
            
            // Add the current number to the sum
            sum += tmp;
        }

        // Print the minimum, maximum, and sum of the numbers
        System.out.println(min + " " + max + " " + sum);
    }
}
