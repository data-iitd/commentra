import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the maximum level from user input
        int maxLevel = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        // Read the levels completed by player X and convert them to a set of integers
        Set<Integer> x = new HashSet<>();
        String[] xLevels = scanner.nextLine().split(" ");
        for (int i = 1; i < xLevels.length; i++) {
            x.add(Integer.parseInt(xLevels[i]));
        }

        // Read the levels completed by player Y and convert them to a set of integers
        Set<Integer> y = new HashSet<>();
        String[] yLevels = scanner.nextLine().split(" ");
        for (int i = 1; i < yLevels.length; i++) {
            y.add(Integer.parseInt(yLevels[i]));
        }

        // Create a union of both sets to combine all unique levels completed by both players
        Set<Integer> z = new HashSet<>(x);
        z.addAll(y);

        // Check if the number of unique levels completed matches the maximum level
        if (z.size() != maxLevel) {
            // If not, print a message indicating that not all levels were completed
            System.out.println("Oh, my keyboard!");
        } else {
            // If all levels were completed, print a success message
            System.out.println("I become the guy.");
        }
    }
}
