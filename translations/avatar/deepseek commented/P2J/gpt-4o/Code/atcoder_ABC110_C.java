import java.util.*;

public class Main {
    // Define the main class

    public static String run(String s, String t) {
        // Define the run method that takes two arguments, s and t
        Map<Character, Integer> counterS = new HashMap<>();
        // Create a HashMap to count occurrences of characters in s
        for (char c : s.toCharArray()) {
            counterS.put(c, counterS.getOrDefault(c, 0) + 1);
        }

        Map<Character, Integer> counterT = new HashMap<>();
        // Create a HashMap to count occurrences of characters in t
        for (char c : t.toCharArray()) {
            counterT.put(c, counterT.getOrDefault(c, 0) + 1);
        }

        List<Integer> ss = new ArrayList<>(counterS.values());
        // Get the values from the counter for s
        Collections.sort(ss);
        // Sort the values for s

        List<Integer> tt = new ArrayList<>(counterT.values());
        // Get the values from the counter for t
        Collections.sort(tt);
        // Sort the values for t

        if (ss.equals(tt)) {
            // Check if the sorted values of s and t are equal
            return "Yes";
        } else {
            // If not equal, return "No"
            return "No";
        }
    }

    public static void main(String[] args) {
        // Define the main method to get input and print the result
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        // Get input for s from the user
        String t = scanner.nextLine();
        // Get input for t from the user
        System.out.println(run(s, t));
        // Call the run method with s and t as arguments and print the result
    }
}

// <END-OF-CODE>
