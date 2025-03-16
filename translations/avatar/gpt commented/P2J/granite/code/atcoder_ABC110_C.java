
import java.util.*;

public class atcoder_ABC110_C{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();
        System.out.println(run(s, t));
    }

    public static String run(String s, String t) {
        // Count the frequency of each character in string s and sort the frequencies
        Map<Character, Integer> ss = new HashMap<>();
        for (char c : s.toCharArray()) {
            ss.put(c, ss.getOrDefault(c, 0) + 1);
        }
        List<Integer> ssList = new ArrayList<>(ss.values());
        Collections.sort(ssList);
        
        // Count the frequency of each character in string t and sort the frequencies
        Map<Character, Integer> tt = new HashMap<>();
        for (char c : t.toCharArray()) {
            tt.put(c, tt.getOrDefault(c, 0) + 1);
        }
        List<Integer> ttList = new ArrayList<>(tt.values());
        Collections.sort(ttList);
        
        // Compare the sorted frequency lists of both strings
        if (ssList.equals(ttList)) {
            return "Yes";  // Return 'Yes' if the frequency distributions are the same
        } else {
            return "No";   // Return 'No' if the frequency distributions are different
        }
    }
}

