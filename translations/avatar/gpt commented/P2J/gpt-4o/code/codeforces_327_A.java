import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    
    // This function returns a list of indices where the character 'ch' appears in the string 's'.
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
        scanner.nextLine(); // Consume the newline character
        
        // Read the string input 's'.
        String s = scanner.nextLine();
        
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
                
                // Iterate through each combination of indices taken 2 at a time.
                for (int i = 0; i < indices.size(); i++) {
                    for (int j = i + 1; j < indices.size(); j++) {
                        int x0 = indices.get(i);
                        int x1 = indices.get(j);
                        // Calculate the maximum value based on the distance between the two indices.
                        maximum = Math.max(maximum, 2 + 2 * (Math.abs(i - j) - 1) - (Math.abs(x0 - x1) - 1));
                    }
                }
                
                // Output the count of '1's in the string plus the maximum value calculated.
                int countOfOnes = 0;
                for (char c : s.toCharArray()) {
                    if (c == '1') {
                        countOfOnes++;
                    }
                }
                System.out.println(countOfOnes + maximum);
            }
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
