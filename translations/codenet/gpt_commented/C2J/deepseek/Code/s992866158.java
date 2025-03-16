public class Main {
    public static void main(String[] args) {
        // Declare variables for the number of elements (n), the threshold (k), and a counter (cnt)
        int n, k, cnt;

        // Create a Scanner object to read user input
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read the number of elements and the threshold value from user input
        n = scanner.nextInt();
        k = scanner.nextInt();
        
        // Initialize the counter to zero
        cnt = 0;

        // Loop through each element, decrementing n until it reaches zero
        while (n-- > 0) {
            int h;

            // Read the current element from user input
            h = scanner.nextInt();
            
            // Check if the current element is greater than or equal to the threshold
            if (h >= k)
                // Increment the counter if the condition is met
                cnt++;
        }

        // Output the final count of elements that met or exceeded the threshold
        System.out.println(cnt);
        
        // Return 0 to indicate successful execution of the program
        // Note: In Java, the main method returns an int, but typically 0 is used to indicate success
        System.exit(0); // Using System.exit to match the original C code's return 0
    }
}
