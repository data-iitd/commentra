

import java.util.*;
// Import the java.util package for the Scanner class

public class atcoder_ABC110_C{
    // Define the atcoder_ABC110_C class as the entry point for the program

    public static void main(String[] args) {
        // Define the main method to get input and print the result
        Scanner scanner = new Scanner(System.in);
        // Create a Scanner object to read input from the user
        String s = scanner.nextLine();
        // Read the first line of input for s from the user
        String t = scanner.nextLine();
        // Read the second line of input for t from the user
        System.out.println(run(s, t));
        // Call the run method with s and t as arguments and print the result
    }

    public static String run(String s, String t) {
        // Define the run method that takes two arguments, s and t
        Map<Character, Integer> counterS = new HashMap<>();
        // Create a HashMap to store the count of each character in s
        Map<Character, Integer> counterT = new HashMap<>();
        // Create a HashMap to store the count of each character in t
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            // Iterate over the characters in s and count their occurrences
            counterS.put(c, counterS.getOrDefault(c, 0) + 1);
            // Update the count of the current character in counterS
        }
        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            // Iterate over the characters in t and count their occurrences
            counterT.put(c, counterT.getOrDefault(c, 0) + 1);
            // Update the count of the current character in counterT
        }
        List<Integer> valuesS = new ArrayList<>(counterS.values());
        // Create a list to store the values of counterS
        List<Integer> valuesT = new ArrayList<>(counterT.values());
        // Create a list to store the values of counterT
        Collections.sort(valuesS);
        // Sort the values in valuesS in ascending order
        Collections.sort(valuesT);
        // Sort the values in valuesT in ascending order
        if (valuesS.equals(valuesT)) {
            // Check if the sorted values of s and t are equal
            return "Yes";
        } else {
            // If not equal, return 'No'
            return "No";
        }
    }
}

