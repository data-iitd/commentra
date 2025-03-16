import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int s = scanner.nextInt(); // Read an integer input from the user
        HashSet<Integer> a = new HashSet<>(); // Create a set to store unique values of s
        a.add(s); // Add the initial value of s to the set

        int d = 2; // Initialize the depth counter

        // Start an infinite loop to process the value of s
        while (true) {
            // Check if s is even
            if (s % 2 == 0) {
                int x = s / 2; // If even, calculate the next value as half of s
                // Check if the new value x already exists in the set
                if (a.contains(x)) {
                    System.out.println(d); // If it exists, print the depth and exit
                    return;
                }
                a.add(x); // Add the new value x to the set
            } else {
                // If s is odd, calculate the next value using the formula 3*s + 1
                int x = 3 * s + 1;
                // Check if the new value x already exists in the set
                if (a.contains(x)) {
                    System.out.println(d); // If it exists, print the depth and exit
                    return;
                }
                a.add(x); // Add the new value x to the set
            }
            s = x; // Update s to the new value x for the next iteration
            d++; // Increment the depth counter
        }

        // This line will never be reached due to the infinite loop
        // System.out.println(d); // Print the depth (not reached)
    }
}
