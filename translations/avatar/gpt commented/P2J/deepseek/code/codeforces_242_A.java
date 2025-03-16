import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values for x, y, a, and b and convert them to integers
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Initialize an empty list to store valid game pairs
        List<Pair> games = new ArrayList<>();
        
        // Iterate over the range from a to x (inclusive)
        for (int i = a; i <= x; i++) {
            // Skip the iteration if i is less than or equal to b
            if (i <= b) {
                continue;
            } else {
                // Iterate over the range from b to y (inclusive)
                for (int j = b; j <= y; j++) {
                    // Check if the current i is greater than j
                    if (i > j) {
                        // If the condition is met, add the pair (i, j) to the games list
                        games.add(new Pair(i, j));
                    }
                }
            }
        }
        
        // Print the total number of valid game pairs found
        System.out.println(games.size());
        
        // Print each valid game pair
        for (Pair pair : games) {
            System.out.println(pair.first + " " + pair.second);
        }
    }
    
    // Custom Pair class to store pairs of integers
    static class Pair {
        int first;
        int second;
        
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
