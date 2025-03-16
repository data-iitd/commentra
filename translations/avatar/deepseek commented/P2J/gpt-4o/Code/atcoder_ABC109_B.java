import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Step 1: Take an integer input n which represents the number of strings.
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Step 2: Initialize a HashMap to keep track of the counts of each string.
        Map<String, Integer> s = new HashMap<>();
        
        // Step 3: Create a list to store the strings.
        List<String> l = new ArrayList<>();
        
        // Step 4: Take n inputs from the user and store them in the list.
        for (int i = 0; i < n; i++) {
            l.add(scanner.nextLine());
        }
        
        // Step 5: Initialize a variable f to "Yes" to keep track of the validity of the sequence.
        String f = "Yes";
        
        // Step 6: Initialize a variable i to -1 to keep track of the index of the current string in the list.
        int i = -1;
        
        // Step 7: Enter a for loop to iterate over each string v in the list l.
        for (String v : l) {
            // Step 8: Increment the count of the current string v in the map s.
            s.put(v, s.getOrDefault(v, 0) + 1);
            
            // Step 9: If the count of v becomes 2 or more, set f to "No".
            if (s.get(v) >= 2) {
                f = "No";
            }
            
            // Step 10: If i is not -1 and the last character of the previous string is not the same as the first character of the current string, set f to "No".
            if (i != -1 && l.get(i).charAt(l.get(i).length() - 1) != v.charAt(0)) {
                f = "No";
            }
            
            // Step 11: Increment the index i after processing each string.
            i++;
        }
        
        // Step 12: Print the value of f, which indicates whether the sequence is valid or not.
        System.out.println(f);
        
        scanner.close();
    }
}
// <END-OF-CODE>
