import java.util.*; // Importing the necessary classes from the java.util package

public class Main {
    // Creating a static Scanner object for user input
    static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        // Reading an integer n from user input, which represents the number of elements
        int n = input.nextInt();
        
        // Initializing a list to store the indices of elements that are equal to 1
        List<Integer> arr = new ArrayList<>();

        // Looping through the input values to find indices of elements equal to 1
        for (int i = 0; i < n; i++) {
            // If the input value is 1, add the current index to the list
            if (input.nextInt() == 1) {
                arr.add(i);
            }
        }

        // Checking if the list of indices is empty
        if (arr.isEmpty()) {
            // If the list is empty, print 0
            System.out.println(0);
        } else {
            // If the list is not empty, initialize a result variable to 1
            long result = 1;

            // Calculate the product of the differences between consecutive indices
            for (int i = 1; i < arr.size(); i++) {
                result *= arr.get(i) - arr.get(i - 1);
            }

            // Print the final result
            System.out.println(result);
        }
    }
}
