import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class MenuCostCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for user input
        List<Item> menu = new ArrayList<>();  // Initialize a list to store menu items

        // Loop to collect 5 menu items from user input
        for (int i = 0; i < 5; i++) {
            String m = scanner.nextLine();  // Take input from the user
            int e = Character.getNumericValue(m.charAt(m.length() - 1));  // Extract the last character and convert it to an integer
            if (e == 0) {  // If the last digit is 0
                e = 10;  // Change it to 10
            }
            menu.add(new Item(Integer.parseInt(m), e));  // Append a new Item to the menu
        }

        // Sort the menu based on the second element (e) of each Item
        Collections.sort(menu, Comparator.comparingInt(Item::getE));

        int ans = 0;  // Initialize a variable to accumulate the total cost

        // Loop through the sorted menu starting from the second item
        for (int i = 1; i < menu.size(); i++) {
            Item item = menu.get(i);
            // Calculate the cost for each item, rounding up to the nearest multiple of 10
            ans += (int) Math.ceil(item.getM() / 10.0) * 10;
        }

        // Print the total cost, including the first item's original value
        System.out.println(ans + menu.get(0).getM());  // Add the first item's value to the accumulated cost and print the result
    }
}

// Class to represent a menu item
class Item {
    private int m;  // The integer value of the menu item
    private int e;  // The extracted last digit (or 10 if it was 0)

    public Item(int m, int e) {
        this.m = m;
        this.e = e;
    }

    public int getM() {
        return m;
    }

    public int getE() {
        return e;
    }
}
<END-OF-CODE>
