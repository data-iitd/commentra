import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the list from user input
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        // Initialize an empty dictionary 's' with default value 0 using HashMap
        Map<String, Integer> s = new HashMap<>();

        // Create an empty list 'l' with length 'n' by reading elements from user input
        List<String> l = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            l.add(scanner.nextLine());
        }

        // Initialize a flag 'f' with value 'Yes'
        String f = "Yes";

        // Iterate through each element 'v' in the list 'l'
        for (String v : l) {
            // Increment the count of 'v' in dictionary 's'
            s.put(v, s.getOrDefault(v, 0) + 1);

            // Check if the count of 'v' in dictionary 's' is greater than or equal to 2
            if (s.get(v) >= 2) {
                // If yes, set the flag 'f' to 'No'
                f = "No";
            }

            // Check if the index 'i' is not -1 and the last character of previous element is not equal to the current element
            // Note: In Java, we don't have direct access to the index 'i', so we assume the previous element is the last element in the list
            if (l.size() > 0 && !l.get(l.size() - 1).endsWith(v.substring(0, 1))) {
                // If yes, set the flag 'f' to 'No'
                f = "No";
            }
        }

        // Print the final value of flag 'f'
        System.out.println(f);
    }
}
