import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class MenuCostCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<int[]> menu = new ArrayList<>();  // Use ArrayList to store menu items

        // Loop to collect 5 menu items from user input
        for (int i = 0; i < 5; i++) {
            String m = scanner.nextLine();  // Take input from the user
            int e = Character.getNumericValue(m.charAt(m.length() - 1));  // Extract the last character and convert it to an integer
            if (e == 0) {  // If the last digit is 0
                e = 10;  // Change it to 10 (to avoid zero as a value)
            }
            menu.add(new int[]{Integer.parseInt(m), e});  // Add a new int array containing the integer value of m and e to the menu
        }

        // Sort the menu based on the second element (e) of each array
        Collections.sort(menu, (a, b) -> Integer.compare(a[1], b[1]));

        int ans = 0;  // Initialize a variable to accumulate the total cost

        // Loop through the sorted menu starting from the second item
        for (int i = 1; i < menu.size(); i++) {
            // Calculate the cost for each item, rounding up to the nearest multiple of 10
            int cost = (int) Math.ceil((double) menu.get(i)[0] / 10) * 10;
            ans += cost;
        }

        // Print the total cost, including the first item's original value
        System.out.println(ans + menu.get(0)[0]);  // Add the first item's value to the accumulated cost and print the result
    }
}
