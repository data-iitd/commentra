import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); // Step 1: Read the input value N
        
        HashMap<Integer, String> map = new HashMap<>(); // Step 2: Initialize a HashMap
        
        for (int i = 0; i < N; i++) { // Step 3: Read N strings and store them in the HashMap
            map.put(i, sc.next());
        }
        
        boolean ans = true; // Step 4: Initialize a boolean variable 'ans'
        HashMap<Integer, String> past = new HashMap<>(); // Step 5: Initialize another HashMap
        String next = ""; // Step 6: Initialize a variable 'next'
        
        for (int i = 0; i < N; i++) { // Step 7: Loop through the strings
            if (past.containsValue(map.get(i))) { // Step 8: Check if the current string has been seen before
                ans = false;
                break;
            }
            past.put(i, map.get(i)); // Step 9: Store the current string in the 'past' HashMap
            
            if (i != 0) { // Step 10: Check if it's not the first string
                if (!next.equals(map.get(i).substring(0, 1))) { // Check if the starting character matches
                    ans = false;
                    break;
                }
            }
            next = map.get(i).substring(map.get(i).length() - 1, map.get(i).length()); // Step 11: Update 'next'
        }
        
        if (ans) { // Step 12: Check the value of 'ans'
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
