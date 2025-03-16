import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers n and k from input, where n is the total number of elements and k is the position of interest
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read the string of values (v) from input
        String v = scanner.next();
        
        // Define the directions for movement: LEFT and RIGHT
        String[] d = {"LEFT", "RIGHT"};
        
        // Determine if we should move LEFT or RIGHT based on the position k
        // If k is closer to the start (LEFT), f will be true; otherwise, it will be false
        boolean f = k - 1 < n - k;
        
        // Calculate the minimum number of moves needed to reach the desired position
        int m = Math.min(k - 1, n - k);
        
        // Initialize an empty list to store the sequence of moves and prints
        List<String> a = new ArrayList<>();
        
        // Append the necessary number of LEFT or RIGHT moves to the list based on the calculated minimum moves
        for (int i = 0; i < m; i++) {
            a.add(d[f ? 1 : 0]);  // Append the opposite direction of f
        }
        
        // Append the print commands for each character in the string v
        // The slicing reverses the order of characters if moving RIGHT (f is true)
        for (int i = v.length() - 1; i >= 0; i -= f ? -1 : 1) {
            a.add("PRINT " + v.charAt(i));  // Append the print command for the current character
            a.add(d[f]);                    // Append the direction for the next move
        }
        
        // Print the final sequence of moves and print commands, excluding the last move
        for (int i = 0; i < a.size() - 1; i++) {
            System.out.println(a.get(i));
        }
    }
}
