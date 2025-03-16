import java.io.*;
import java.util.*;
import java.math.*;

// Main function to solve the problem
public static void main(String[] args) {
    // Read input string from the user
    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();
    
    // Check if all characters in the string are the same
    if (s.length() == 1) {
        System.out.println(0);
        return;
    }
    
    // Count the frequency of each character in the string
    Map<Character, Integer> a = new HashMap<>();
    for (int i = 0; i < s.length(); i++) {
        char c = s.charAt(i);
        if (a.containsKey(c)) {
            a.put(c, a.get(c) + 1);
        } else {
            a.put(c, 1);
        }
    }
    
    // Calculate the answer as twice the minimum frequency of any character
    int ans = Integer.MAX_VALUE;
    for (int v : a.values()) {
        ans = Math.min(ans, v * 2);
    }
    
    // Print the answer and exit
    System.out.println(ans);
}

// End of code
