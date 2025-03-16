import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Step 2: Take an integer input n which represents the number of strings.
        Map<String, Integer> s = new HashMap<>();  // Step 3: Initialize a HashMap named s with default value of 0.
        List<String> l = new ArrayList<>();  // Step 4: Create a List l to store the strings.
        String f = "Yes";  // Step 5: Initialize a variable f to "Yes" to keep track of the validity of the sequence.
        int i = -1;  // Step 6: Initialize a variable i to -1 to keep track of the index of the current string in the list.

        // Step 7: Enter a for loop to iterate over each string v in the list l.
        for (int j = 0; j < n; j++) {
            String v = scanner.next();  // Read the next string input.
            s.put(v, s.getOrDefault(v, 0) + 1);  // Step 8: Increment the count of the current string v in the map s.
            if (s.get(v) >= 2) {  // Step 9: If the count of v becomes 2 or more, set f to "No".
                f = "No";
            }
            if (i != -1 && !l.get(i).charAt(l.get(i).length() - 1) == v.charAt(0)) {  // Step 10: If i is not -1 and the last character of the previous string is not the same as the first character of the current string, set f to "No".
                f = "No";
            }
            l.add(v);  // Add the current string v to the list l.
            i++;  // Step 11: Increment the index i after processing each string.
        }

        // Step 12: Print the value of f, which indicates whether the sequence is valid or not.
        System.out.println(f);
    }
}
