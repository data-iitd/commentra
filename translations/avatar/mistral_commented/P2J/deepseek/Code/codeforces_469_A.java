import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // User inputs the maximum level of the set
        int maxLevel = Integer.parseInt(scanner.nextLine());

        // User inputs two lists, x and y, separated by a newline
        String[] xInput = scanner.nextLine().split(" ");
        String[] yInput = scanner.nextLine().split(" ");

        // Remove the first element from both lists, as they are not part of the sets
        Set<Integer> x = new HashSet<>();
        Set<Integer> y = new HashSet<>();

        for (int i = 1; i < xInput.length; i++) {
            x.add(Integer.parseInt(xInput[i]));
        }

        for (int i = 1; i < yInput.length; i++) {
            y.add(Integer.parseInt(yInput[i]));
        }

        // Combine both sets into a new set z
        Set<Integer> z = new HashSet<>(x);
        z.addAll(y);

        // Check if the size of the combined set is equal to the maximum level
        if (z.size() != maxLevel) {
            // If not, print an error message
            System.out.println("Oh, my keyboard!");
        } else {
            // Else, print a success message
            System.out.println("I become the guy.");
        }
    }
}

