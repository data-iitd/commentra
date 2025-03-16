import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n = scanner.nextInt(); // Read the size of the vector

        // Initialize an ArrayList to store the elements
        ArrayList<Integer> p = new ArrayList<>(n); 

        // Read elements of the vector p from the user
        for (int i = 0; i < n; i++) {
            p.add(scanner.nextInt()); // Read the value of the current element
        }

        // Initialize the answer variable ans to zero
        int ans = 0;

        // Check each element of the vector p starting from the first one
        for (int i = 0; i < n - 1; i++) {
            if (p.get(i) == i + 1) { // Check if the current element is equal to its index + 1
                p.set(i + 1, p.get(i)); // Swap the current element with the next one if it is in the wrong position
                ans += 1; // Increment the answer if a swap was made
            }
        }

        // Check the last element of the vector p
        if (p.get(n - 1) == n) { // Check if the last element is equal to its index + 1
            ans += 1; // Increment the answer if it is in the wrong position
        }

        // Print the answer to the user
        System.out.println(ans); // Output the answer
    }
}
// <END-OF-CODE>
