import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        // Check if all characters in the string are the same
        if (s.chars().distinct().count() == 1) {
            System.out.println(0); // If true, print 0 and exit
            return;
        }

        // Count the occurrences of each character in the string
        Map<Character, Integer> a = new HashMap<>();
        for (char c : s.toCharArray()) {
            a.put(c, a.getOrDefault(c, 0) + 1);
        }

        // Calculate the answer as twice the minimum frequency of any character
        int minFrequency = Collections.min(a.values());
        int ans = minFrequency * 2;

        // Print the final answer
        System.out.println(ans);
    }
}
