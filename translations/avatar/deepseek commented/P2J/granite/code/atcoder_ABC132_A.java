

import java.util.Scanner;  // Import the Scanner class from the java.util package
import java.util.HashMap;  // Import the HashMap class from the java.util package

public class atcoder_ABC132_A{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  // Create a Scanner object to read input from the user
        String S = sc.next();  // Read a string input from the user
        HashMap<Character, Integer> c = new HashMap<>();  // Create a HashMap to store the frequency of each character in the string S

        // Iterate over the characters in the string S and update the frequency in the HashMap
        for (int i = 0; i < S.length(); i++) {
            char ch = S.charAt(i);
            if (c.containsKey(ch)) {
                c.put(ch, c.get(ch) + 1);
            } else {
                c.put(ch, 1);
            }
        }

        // Check if the number of unique characters is not equal to 2
        if (c.size()!= 2) {
            System.out.println("No");  // Print "No" and exit if the condition is true
            return;  // Exit the program
        }

        // Iterate over the HashMap and check if the frequency of each character is not equal to 2
        for (char ch : c.keySet()) {
            if (c.get(ch)!= 2) {
                System.out.println("No");  // Print "No" and exit if the condition is true
                return;  // Exit the program
            }
        }

        System.out.println("Yes");  // Print "Yes" if all characters have a frequency of 2
    }
}

