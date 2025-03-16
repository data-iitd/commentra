import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read an integer input 'n' which represents the length of the string.
        int n = sc.nextInt();
        
        // Read the string input's' and replace any empty string occurrences (this line seems to be incorrect).
        String s = sc.next().replace("", "");
        
        // Check if the string's' contains the character '0'.
        if (s.indexOf('0') == -1) {
            // If '0' is not present, the output is n - 1.
            System.out.println(n - 1);
        } else {
            // Find all indices of '0' in the string's'.
            int[] indices = new int[s.length()];
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '0') {
                    indices[i] = i;
                }
            }
            
            // If there is only one '0', output the length of the string 'n'.
            if (indices.length == 1) {
                System.out.println(n);
            } else {
                // Initialize a variable to keep track of the maximum value found.
                int maximum = 0;
                
                // Generate all combinations of indices of '0' taken 2 at a time.
                for (int i = 0; i < indices.length - 1; i++) {
                    for (int j = i + 1; j < indices.length; j++) {
                        // Calculate the maximum value based on the distance between the two indices.
                        maximum = Math.max(maximum, 2 + 2 * (Math.abs(indices[i] - indices[j]) - 1) - (Math.abs(i - j) - 1));
                    }
                }
                
                // Output the count of '1's in the string plus the maximum value calculated.
                System.out.println(s.replaceAll("0", "").length() + maximum);
            }
        }
    }
}

