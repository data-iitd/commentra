import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // The code starts by taking input for the maximum level and two lists of integers.
        int maxLevel = scanner.nextInt();
        int n = scanner.nextInt(); // Read the size of the first list
        Set<Integer> x = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int value = scanner.nextInt();
            if (i > 0) { // Skip the first element
                x.add(value);
            }
        }
        
        int m = scanner.nextInt(); // Read the size of the second list
        Set<Integer> y = new HashSet<>();
        for (int i = 0; i < m; i++) {
            int value = scanner.nextInt();
            if (i > 0) { // Skip the first element
                y.add(value);
            }
        }

        // If there's a 0 in either set, discard it from the set.
        x.remove(0);
        y.remove(0);

        // Find the union of the two sets and check if its length is equal to the maximum level.
        Set<Integer> z = new HashSet<>(x);
        z.addAll(y);
        
        if (z.size() != maxLevel) {
            System.out.println("Oh, my keyboard!");
        } else {
            System.out.println("I become the guy.");
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
