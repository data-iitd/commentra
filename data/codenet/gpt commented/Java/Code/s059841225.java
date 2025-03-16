import java.util.*;

class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Continuously read input until there are no more tokens
        while (sc.hasNext()) {
            // Read the next input string and split it by commas
            String str = sc.next();
            String[] strArr = str.split(",");
            
            // Initialize an array to hold the first 10 integers and a variable to sum them
            int[] l = new int[10];
            int d = 0;
            
            // Parse the first 10 elements from the input string and calculate their sum
            for (int i = 0; i < 10; i++) {
                l[i] = Integer.parseInt(strArr[i]); // Convert string to integer
                d += l[i]; // Accumulate the sum
            }
            
            // Parse the next two elements from the input string into an array
            int[] v = {Integer.parseInt(strArr[10]), Integer.parseInt(strArr[11])};
            
            // Calculate the average based on the sum and the two additional values
            double t = (double) d / (v[0] + v[1]);
            d = 0; // Reset the sum for the next calculation
            
            // Iterate through the first 11 elements to find the index where the condition is met
            for (int i = 0; i < 11; i++) {
                // Check if the product of v[0] and t is less than or equal to the accumulated sum
                if (v[0] * t <= d) {
                    System.out.println(i); // Print the index if the condition is satisfied
                    break; // Exit the loop once the condition is met
                } else {
                    d += l[i]; // Accumulate the sum of the first 11 elements
                }
            }
        }
    }
}
