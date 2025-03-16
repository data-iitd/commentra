public class Main {
    public static void main(String[] args) {
        // Declare variables
        int n, i; // n: number of elements, i: loop index
        int[] h = new int[100001]; // Array to store heights
        int max = -1; // Variable to track the maximum height
        boolean flag = false; // Flag to indicate if the condition is met

        // Read the number of elements
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();

        // Loop to read heights and determine the maximum height
        for(i = 0; i < n; i++) {
            // Read height into the array
            h[i] = scanner.nextInt();
            
            // Update maximum height if current height is greater
            if(max < h[i]) max = h[i];

            // Check if the difference between max height and current height is 2 or more
            if(max - h[i] >= 2) flag = true; // Set flag if condition is met
        }

        // Output result based on the flag value
        if(flag) 
            System.out.println("No"); // If flag is set, print "No"
        else 
            System.out.println("Yes"); // If flag is not set, print "Yes"
    }
}
