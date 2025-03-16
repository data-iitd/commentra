import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class LevelCompletion {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the maximum level from user input
        int maxLevel = scanner.nextInt();

        // Read the levels completed by player X
        int xCount = scanner.nextInt();
        Set<Integer> xLevels = new HashSet<>();
        for (int i = 0; i < xCount; i++) {
            xLevels.add(scanner.nextInt());
        }

        // Read the levels completed by player Y
        int yCount = scanner.nextInt();
        Set<Integer> yLevels = new HashSet<>();
        for (int i = 0; i < yCount; i++) {
            yLevels.add(scanner.nextInt());
        }

        // Check if player X has completed level 0, if so, remove it from the set
        if (xLevels.contains(0)) {
            xLevels.remove(0);
        } 
        // If player X has not completed level 0, check if player Y has, and remove it if present
        else if (yLevels.contains(0)) {
            yLevels.remove(0);
        }

        // Create a union of both sets to combine all unique levels completed by both players
        Set<Integer> allLevels = new HashSet<>(xLevels);
        allLevels.addAll(yLevels);

        // Check if the number of unique levels completed matches the maximum level
        if (allLevels.size() != maxLevel) {
            // If not, print a message indicating that not all levels were completed
            System.out.println("Oh, my keyboard!");
        } else {
            // If all levels were completed, print a success message
            System.out.println("I become the guy.");
        }

        scanner.close();
    }
}
// <END-OF-CODE>
