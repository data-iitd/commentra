
import java.util.*;

// codeforces_327_A block of the code
public class codeforces_327_A{
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
        // Read the integer input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        // Read the string input and remove spaces
        String s = scanner.next().replace(" ", "");

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
                // Generate all combinations of two indices of '0'
                List<List<Integer>> combs = new ArrayList<>();
                for (int i = 0; i < indices.size(); i++) {
                    for (int j = i + 1; j < indices.size(); j++) {
                        List<Integer> pair = new ArrayList<>();
                        pair.add(indices.get(i));
                        pair.add(indices.get(j));
                        combs.add(pair);
                    }
                }

                // Iterate over each combination and calculate the maximum distance
                for (List<Integer> x : combs) {
                    maximum = Math.max(maximum, 2 + 2 * (Math.abs(indices.indexOf(x.get(0)) - indices.indexOf(x.get(1))) - 1) - (Math.abs(x.get(0) - x.get(1)) - 1));
                }

                // Print the count of '1's plus the maximum distance
                System.out.println(s.chars().filter(ch -> ch == '1').count() + maximum);
            }
        }
    }
}

Translate the above Java code to C++ and end with comment "