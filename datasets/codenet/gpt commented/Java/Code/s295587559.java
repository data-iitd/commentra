import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner in = new Scanner(System.in);
        
        // Read the size of the array and initialize it with consecutive integers starting from 1
        int[] num = new int[in.nextInt()];
        for (int i = 0; i < num.length; i++) {
            num[i] = i + 1; // Fill the array with values 1 to n
        }
        
        // Read the number of swap operations to perform
        int count = in.nextInt();
        
        // Compile a regex pattern to match pairs of integers separated by a comma
        Pattern pt = Pattern.compile("(\\d+),(\\d+)");
        int line[] = new int[2]; // Array to hold the indices of the elements to swap
        
        // Perform the specified number of swap operations
        for (int i = 0; i < count; i++) {
            // Read the next input line that matches the pattern
            String next = in.next(pt);
            
            // Extract the indices from the matched input
            for (int j = 0; j < line.length; j++) {
                Matcher matcher = pt.matcher(next);
                matcher.matches(); // Ensure the input matches the pattern
                line[j] = Integer.parseInt(matcher.group(j + 1)) - 1; // Convert to zero-based index
            }
            
            // Swap the elements at the specified indices
            int change = num[line[0]];
            num[line[0]] = num[line[1]];
            num[line[1]] = change;
        }
        
        // Print the final state of the array after all swaps
        for (int i = 0; i < num.length; i++) {
            System.out.println(num[i]);
        }
    }
}
