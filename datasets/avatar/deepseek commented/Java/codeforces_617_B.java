
import java.util.* ;

public class Main {
    static Scanner input = new Scanner(System.in); // Step 3: Create a Scanner object to read input.

    public static void main(String[] args) { // Step 4: Define the main method.
        int n = input.nextInt(); // Step 5: Read the number of elements.
        List<Integer> arr = new ArrayList<>(); // Step 6: Create a list to store the indices of elements equal to 1.

        for (int i = 0; i < n; i++) { // Step 7: Read the elements and store their indices if they are equal to 1.
            if (input.nextInt() == 1) {
                arr.add(i);
            }
        }

        if (arr.isEmpty()) { // Step 8: Check if the list is empty.
            System.out.println(0); // If the list is empty, print 0.
        } else {
            long result = 1; // Initialize the result variable to 1.
            for (int i = 1; i < arr.size(); i++) { // Step 9: Calculate the product of differences between consecutive indices.
                result *= arr.get(i) - arr.get(i - 1);
            }
            System.out.println(result); // Print the result.
        }
    }
}