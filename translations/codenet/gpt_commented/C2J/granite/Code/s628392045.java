
import java.util.Scanner;

public class s628392045{
    public static void main(String[] args) {
        // Declare variables
        int n, i; // n: number of elements, i: loop index
        int h[] = new int[100001]; // Array to store heights
        int max = -1; // Variable to track the maximum height
        int flag = 0; // Flag to indicate if the condition is met

        // Create a Scanner object to read input
        Scanner sc = new Scanner(System.in);

        // Read the number of elements
        n = sc.nextInt();

        // Loop to read heights and determine the maximum height
        for(i = 0; i < n; i++) {
            // Read height into the array
            h[i] = sc.nextInt();
            
            // Update maximum height if current height is greater
            if(max < h[i]) max = h[i];

            // Check if the difference between max height and current height is 2 or more
            if(max - h[i] >= 2) flag = 1; // Set flag if condition is met
        }

        // Close the Scanner object
        sc.close();

        // Output result based on the flag value
        if(flag == 1) 
            System.out.println("No"); // If flag is set, print "No"
        else 
            System.out.println("Yes"); // If flag is not set, print "Yes"
    }
}
