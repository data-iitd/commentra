import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    // Define a class to represent an arm with left and right bounds
    static class Arm {
        int l, r;

        Arm(int l, int r) {
            this.l = l;
            this.r = r;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of arms
        int n = scanner.nextInt();
        
        // Create an array to hold the arms
        Arm[] arms = new Arm[n];
        
        // Read the arm data from input
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int l = scanner.nextInt(); // Read the center and length of the arm
            arms[i] = new Arm(x - l, x + l); // Calculate the left and right bounds
        }
        
        // Sort the arms based on their right bounds
        Arrays.sort(arms, Comparator.comparingInt(a -> a.r));

        // Initialize the count of non-overlapping arms and the rightmost bound
        int ans = 1; // Start with the first arm
        int r = arms[0].r; // Set the rightmost bound to the right of the first arm
        
        // Iterate through the sorted arms to count non-overlapping arms
        for (int i = 1; i < n; i++) {
            // If the left bound of the current arm is greater than or equal to the rightmost bound
            if (arms[i].l >= r) {
                ans++; // Increment the count of non-overlapping arms
                r = arms[i].r; // Update the rightmost bound to the current arm's right bound
            }
        }
        
        // Print the total count of non-overlapping arms
        System.out.println(ans);
        
        scanner.close();
    }
}
// <END-OF-CODE>
