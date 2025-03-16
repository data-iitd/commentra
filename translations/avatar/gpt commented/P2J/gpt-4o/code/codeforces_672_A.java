import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize an empty list to store the results
        List<Integer> li = new ArrayList<>();
        
        // Loop through numbers from 1 to 370
        for (int i = 1; i <= 370; i++) {
            // Initialize a temporary list to hold digits
            List<Integer> temp = new ArrayList<>();
            // Assign the current number to p and q for processing
            int p = i, q = i;
            // Initialize a count variable to track the number of digits
            int count = 0;
            
            // Count the number of digits in the current number i
            while (p != 0) {
                p /= 10;  // Remove the last digit
                count++;  // Increment the digit count
            }

            // If the number has 1 digit, add it directly to the list
            if (count == 1) {
                li.add(i);
            }
            
            // If the number has 2 digits
            if (count == 2) {
                temp.clear();  // Reset the temporary list
                // Extract digits of the number q
                while (q != 0) {
                    int x = q % 10;  // Get the last digit
                    q /= 10;  // Remove the last digit
                    temp.add(x);  // Append the digit to the temporary list
                }
                // Add the digits in reverse order to the main list
                for (int j = temp.size() - 1; j >= 0; j--) {
                    li.add(temp.get(j));
                }
            }
            
            // If the number has 3 digits
            if (count == 3) {
                temp.clear();  // Reset the temporary list
                // Extract digits of the number q
                while (q != 0) {
                    int x = q % 10;  // Get the last digit
                    q /= 10;  // Remove the last digit
                    temp.add(x);  // Append the digit to the temporary list
                }
                // Add the digits in reverse order to the main list
                for (int j = temp.size() - 1; j >= 0; j--) {
                    li.add(temp.get(j));
                }
            }
        }

        // Remove the last two elements from the list
        li.remove(li.size() - 1);
        li.remove(li.size() - 1);

        // Take user input for the index
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        // Print the n-th element from the list (1-based index)
        System.out.println(li.get(n - 1));
        
        scanner.close();
    }
}
// <END-OF-CODE>
