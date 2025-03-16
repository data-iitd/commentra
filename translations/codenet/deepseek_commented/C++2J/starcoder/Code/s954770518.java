import java.util.*; // Include header for the sort function
public class Main {
    public static void main(String[] args) {
        int s[] = new int[11]; // Declare an array to store the input numbers
        int i; // Declare a variable for the loop

        // Step 3: Read input numbers into the array
        for(i = 0; i < 10; i++) {
            s[i] = Integer.parseInt(args[i]); // Read input and store it in the array
        }

        // Step 4: Sort the array
        Arrays.sort(s); // Sort the array in ascending order

        // Step 5: Print the last four numbers of the sorted array
        for(i = 9; i > 6; i--) {
            System.out.println(s[i]); // Print the last four numbers
        }
    }
}
