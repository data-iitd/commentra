import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    
    // Function to find indices of a character in a string
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
        
        // Read the integer input
        int n = Integer.parseInt(scanner.nextLine());
        // Read the string input and remove spaces
        String s = scanner.nextLine().replace(" ", "");
        
        // If the string does not contain '0', print n - 1
        if (!s.contains("0")) {
            System.out.println(n - 1);
        } else {
            // Find all indices of '0' in the string
            List<Integer> indices = find(s, '0');
            
            // If there is only one '0', print n
            if (indices.size() == 1) {
                System.out.println(n);
            } else {
                // Initialize maximum to 0
                int maximum = 0;
                
                // Iterate over each combination of two indices of '0'
                for (int i = 0; i < indices.size(); i++) {
                    for (int j = i + 1; j < indices.size(); j++) {
                        int x0 = indices.get(i);
                        int x1 = indices.get(j);
                        maximum = Math.max(maximum, 2 + 2 * (Math.abs(i - j) - 1) - (Math.abs(x0 - x1) - 1));
                    }
                }
                
                // Print the count of '1's plus the maximum distance
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
