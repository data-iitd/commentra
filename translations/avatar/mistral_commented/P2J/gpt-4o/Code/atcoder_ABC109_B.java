import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements in the list from user input
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());

        // Initialize a HashMap to store counts of elements
        Map<String, Integer> s = new HashMap<>();

        // Create a list to store the elements
        List<String> l = new ArrayList<>();

        // Read elements from user input
        for (int i = 0; i < n; i++) {
            l.add(scanner.nextLine());
        }

        // Initialize a flag 'f' with value 'Yes'
        String f = "Yes";
        int i = -1; // Initialize index 'i'

        // Iterate through each element 'v' in the list 'l'
        for (String v : l) {
            // Increment the count of 'v' in the HashMap 's'
            s.put(v, s.getOrDefault(v, 0) + 1);

            // Check if the count of 'v' in HashMap 's' is greater than or equal to 2
            if (s.get(v) >= 2) {
                // If yes, set the flag 'f' to 'No'
                f = "No";
            }

            // Check if the index 'i' is not -1 and the last character of previous element is not equal to the current element
            if (i != -1 && l.get(i).charAt(l.get(i).length() - 1) != v.charAt(0)) {
                // If yes, set the flag 'f' to 'No'
                f = "No";
            }

            // Increment the index 'i'
            i++;
        }

        // Print the final value of flag 'f'
        System.out.println(f);
    }
}
// <END-OF-CODE>
