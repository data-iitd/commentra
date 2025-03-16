import java.util.*;

public class Main {
    // Define a method named 'run' that takes two arguments 's' and 't'
    public static String run(String s, String t) {
        // Using a HashMap to count the occurrences of each character in string 's'
        Map<Character, Integer> countS = new HashMap<>();
        for (char c : s.toCharArray()) {
            countS.put(c, countS.getOrDefault(c, 0) + 1);
        }

        // Using a HashMap to count the occurrences of each character in string 't'
        Map<Character, Integer> countT = new HashMap<>();
        for (char c : t.toCharArray()) {
            countT.put(c, countT.getOrDefault(c, 0) + 1);
        }

        // Extracting the values and sorting them
        List<Integer> ss = new ArrayList<>(countS.values());
        List<Integer> tt = new ArrayList<>(countT.values());
        Collections.sort(ss);
        Collections.sort(tt);

        // Comparing the sorted lists of occurrences of characters in strings 's' and 't'
        // If they are equal, then the strings have the same frequency distribution of characters
        // and thus are identical, so return 'Yes'
        // Otherwise, return 'No'
        if (ss.equals(tt)) {
            return "Yes";
        } else {
            return "No";
        }
    }

    // Define a method named 'main' that takes no arguments
    public static void main(String[] args) {
        // Taking input strings 's' and 't' from the user
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();

        // Calling the 'run' method with strings 's' and 't' as arguments and printing the result
        System.out.println(run(s, t));
    }
}

// <END-OF-CODE>
