import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read three integers from the user: a, b, and t
        int a = sc.nextInt(); // Time increment for each count
        int b = sc.nextInt(); // Count increment
        int t = sc.nextInt(); // Total time limit
        
        // Initialize variables to track the total time and count
        double time = 0; // Total time elapsed
        int count = 0; // Total count accumulated
        
        // Loop until the total time exceeds the limit (t + 0.5)
        while (time < t + 0.5) {
            count += b; // Increment the count by b
            time += a; // Increment the time by a
            
            // Check if the total time exceeds the limit
            if (time > t + 0.5) {
                count -= b; // If exceeded, revert the last count increment
                break; // Exit the loop
            }
        }
        
        // Output the final count
        System.out.println(count);
    }
}
