import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static String run(String s, String t) {
        Map<Character, Integer> countS = new HashMap<>();
        Map<Character, Integer> countT = new HashMap<>();

        // Count the frequency of each character in s
        for (char c : s.toCharArray()) {
            countS.put(c, countS.getOrDefault(c, 0) + 1);
        }

        // Count the frequency of each character in t
        for (char c : t.toCharArray()) {
            countT.put(c, countT.getOrDefault(c, 0) + 1);
        }

        // Create a list of the frequencies and sort them
        ArrayList<Integer> ss = new ArrayList<>(countS.values());
        ArrayList<Integer> tt = new ArrayList<>(countT.values());
        Collections.sort(ss);
        Collections.sort(tt);

        // Check if the sorted lists are equal
        if (ss.equals(tt)) {
            return "Yes";
        } else {
            return "No";
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();
        System.out.println(run(s, t));
    }
}
