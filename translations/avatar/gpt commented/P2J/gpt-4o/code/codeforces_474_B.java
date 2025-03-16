import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize an empty list to store the sequence
        List<Integer> L = new ArrayList<>();

        // Read input (not used, but could be for prompting the user)
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();

        // Initialize a variable 'r' to keep track of the current number to be added to the list
        int r = 1;

        // Read a line of input, split it into parts, and iterate over each part
        String[] parts = scanner.nextLine().split(" ");
        for (String k : parts) {
            // Extend the list 'L' by adding 'r' for 'Integer.parseInt(k)' times
            int count = Integer.parseInt(k);
            for (int i = 0; i < count; i++) {
                L.add(r);
            }
            // Increment 'r' for the next number
            r++;
        }

        // Read another line of input (not used, but could be for prompting the user)
        scanner.nextLine();

        // Read a line of input, split it into parts, and iterate over each part
        String[] indices = scanner.nextLine().split(" ");
        for (String j : indices) {
            // Print the element from list 'L' at the index specified by 'j' (adjusted for 0-based index)
            System.out.println(L.get(Integer.parseInt(j) - 1));
        }

        scanner.close();
    }
}
// <END-OF-CODE>
