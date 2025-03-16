import java.util.ArrayList;
import java.util.Scanner;

public class SequenceGenerator {
    public static void main(String[] args) {
        // Initialize an empty list to store the sequence
        ArrayList<Integer> L = new ArrayList<>();

        // Initialize a variable 'r' to keep track of the current number to be added to the list
        int r = 1;

        // Read input (not used, but could be for prompting the user)
        Scanner scanner = new Scanner(System.in);
        String[] parts = scanner.nextLine().split(" ");

        // Read a line of input, split it into parts, and iterate over each part
        for (String k : parts) {
            // Extend the list 'L' by adding 'r' for 'int(k)' times
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
        parts = scanner.nextLine().split(" ");
        for (String j : parts) {
            // Print the element from list 'L' at the index specified by 'j' (adjusted for 0-based index)
            int index = Integer.parseInt(j) - 1;
            System.out.println(L.get(index));
        }

        scanner.close();
    }
}
