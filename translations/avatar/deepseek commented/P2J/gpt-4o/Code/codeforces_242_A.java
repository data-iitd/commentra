import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking input values for x, y, a, and b
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        List<int[]> games = new ArrayList<>();
        // Initializing an empty list called games
        
        for (int i = a; i <= x; i++) {
            // Looping from a to x
            if (i <= b) continue;
            // Skipping values of i that are less than or equal to b
            
            for (int j = b; j <= y; j++) {
                // Looping from b to y
                if (i > j) {
                    // Checking if i is greater than j
                    games.add(new int[]{i, j});
                    // Appending the tuple (i, j) to the games list
                }
            }
        }
        
        System.out.println(games.size());
        // Printing the length of the games list
        
        for (int[] game : games) {
            System.out.println(game[0] + " " + game[1]);
            // Printing each tuple in the games list
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
