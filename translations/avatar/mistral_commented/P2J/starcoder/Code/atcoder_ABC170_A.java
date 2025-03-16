
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Read a list of space-separated integers as input from the standard input
        Scanner sc = new Scanner(System.in);
        List<Integer> a = new ArrayList<Integer>();
        while (sc.hasNextInt()) {
            a.add(sc.nextInt());
        }

        // Iterate over the elements of the list a using the enhanced for loop
        for (int i = 0; i < a.size(); i++) {
            // Check if the current value is equal to zero
            if (a.get(i) == 0) {
                // Print the index of the first zero to the standard output
                System.out.println(i + 1);
                // Terminate the loop using the break statement
                break;
            }
        }
    }
}
