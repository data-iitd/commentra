import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a scanner for user input
        Scanner scanner = new Scanner(System.in);
        
        // Initialize an empty list called menu
        List<int[]> menu = new ArrayList<>();
        
        // Use a for loop to iterate 5 times
        for (int i = 0; i < 5; i++) {
            // Take user input and assign it to the variable m
            String m = scanner.nextLine();
            
            // Extract the last character of the string m to determine the exponent e
            int e = Character.getNumericValue(m.charAt(m.length() - 1));
            
            // If e is 0, set it to 10
            if (e == 0) {
                e = 10;
            }
            
            // Append an array containing the integer value of m and the exponent e to the menu list
            menu.add(new int[]{Integer.parseInt(m), e});
        }
        
        // Sort the menu list based on the exponent value using a custom comparator
        Collections.sort(menu, Comparator.comparingInt(a -> a[1]));
        
        // Initialize a variable called ans to 0
        int ans = 0;
        
        // Use a for loop to iterate through the menu list starting from the second element (index 1)
        for (int i = 1; i < menu.size(); i++) {
            int[] m = menu.get(i);
            // Calculate the number of full 10s that can be obtained by dividing the integer value by 10 and rounding up
            int numFull10s = (int) Math.ceil(m[0] / 10.0);
            
            // Multiply this value by 10 and add it to the ans variable
            ans += numFull10s * 10;
        }
        
        // Finally, print the sum of the first element in the menu list (which is the initial number) and the value of ans
        System.out.println(menu.get(0)[0] + ans);
        
        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
