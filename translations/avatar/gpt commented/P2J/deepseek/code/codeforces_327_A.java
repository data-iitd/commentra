import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static List<Integer> find(String s, char ch) {
        List<Integer> indices = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ch) {
                indices.add(i);
            }
        }
        return indices;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input 'n' which represents the length of the string.
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        
        // Read the string input 's' and replace any empty string occurrences (this line seems to be incorrect).
        String s = scanner.nextLine().replace("", "");
        
        // Check if the string 's' contains the character '0'.
        if (!s.contains("0")) {
            // If '0' is not present, the output is n - 1.
            System.out.println(n - 1);
        } else {
            // Find all indices of '0' in the string 's'.
            List<Integer> indices = find(s, '0');
            
            // If there is only one '0', output the length of the string 'n'.
            if (indices.size() == 1) {
                System.out.println(n);
            } else {
                // Initialize a variable to keep track of the maximum value found.
                int maximum = 0;
                
                // Generate all combinations of indices of '0' taken 2 at a time.
                for (int i = 0; i < indices.size(); i++) {
                    for (int j = i + 1; j < indices.size(); j++) {
                        // Calculate the maximum value based on the distance between the two indices.
                        int current = 2 + 2 * (Math.abs(i - j) - 1) - (Math.abs(indices.get(i) - indices.get(j)) - 1);
                        if (current > maximum) {
                            maximum = current;
                        }
                    }
                }
                
                // Output the count of '1's in the string plus the maximum value calculated.
                System.out.println(s.length() - indices.size() + maximum);
            }
        }
        
        scanner.close();
    }
}
