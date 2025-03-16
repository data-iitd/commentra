import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<int[]> menu = new ArrayList<>();

        for (int i = 0; i < 5; i++) {
            String m = scanner.nextLine(); // Taking input from the user
            int lastDigit = Character.getNumericValue(m.charAt(m.length() - 1)); // Extracting the last digit
            if (lastDigit == 0) {
                lastDigit = 10; // If the last digit is 0, change it to 10
            }
            menu.add(new int[]{Integer.parseInt(m), lastDigit}); // Appending the input value and the processed last digit
        }

        // Sorting the menu list based on the last digit
        Collections.sort(menu, Comparator.comparingInt(a -> a[1]));

        int ans = 0;
        for (int i = 1; i < menu.size(); i++) {
            ans += Math.ceil(menu.get(i)[0] / 10.0) * 10; // Calculating the sum
        }

        System.out.println(ans + menu.get(0)[0]); // Printing the sum of the first element and the calculated ans
        scanner.close();
    }
}
// <END-OF-CODE>
