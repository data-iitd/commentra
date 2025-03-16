
import java.util.Scanner;  // Import the Scanner class for user input
import java.util.Arrays;  // Import the Arrays class for sorting

public class atcoder_ABC123_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read user input
        int[][] menu = new int[5][2];  // Create a 2D array to store menu items

        // Loop to collect 5 menu items from user input
        for (int i = 0; i < 5; i++) {
            String m = scanner.next();  // Take input from the user
            int e = Integer.parseInt(m.substring(m.length() - 1));  // Extract the last character of the input and convert it to an integer
            if (e == 0) {  // If the last digit is 0
                e = 10;  // Change it to 10 (to avoid zero as a value)
            }
            menu[i][0] = Integer.parseInt(m);  // Store the integer value of m in the first element of the subarray
            menu[i][1] = e;  // Store the value of e in the second element of the subarray
        }

        // Sort the menu based on the second element (e) of each subarray
        Arrays.sort(menu, (a, b) -> a[1] - b[1]);

        int ans = 0;  // Initialize a variable to accumulate the total cost
        for (int i = 1; i < menu.length; i++) {  // Loop through the sorted menu starting from the second item
            int cost = (menu[i][0] + 9) / 10 * 10;  // Calculate the cost for each item, rounding up to the nearest multiple of 10
            ans += cost;  // Accumulate the total cost
        }
        ans += menu[0][0];  // Add the first item's value to the accumulated cost

        System.out.println(ans);  // Print the total cost
    }
}
