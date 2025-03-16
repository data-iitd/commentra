import java.util.*;

public class Main {
    public static String run(String s, String t) {
        // Count the frequency of each character in string s
        Map<Character, Integer> freqS = new HashMap<>();
        for (char c : s.toCharArray()) {
            freqS.put(c, freqS.getOrDefault(c, 0) + 1);
        }
        
        // Count the frequency of each character in string t
        Map<Character, Integer> freqT = new HashMap<>();
        for (char c : t.toCharArray()) {
            freqT.put(c, freqT.getOrDefault(c, 0) + 1);
        }
        
        // Get the frequency values and sort them
        List<Integer> ss = new ArrayList<>(freqS.values());
        List<Integer> tt = new ArrayList<>(freqT.values());
        
        Collections.sort(ss);
        Collections.sort(tt);
        
        // Compare the sorted frequency lists of both strings
        if (ss.equals(tt)) {
            return "Yes";  // Return 'Yes' if the frequency distributions are the same
        } else {
            return "No";   // Return 'No' if the frequency distributions are different
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input strings s and t from the user
        String s = scanner.nextLine();
        String t = scanner.nextLine();
        
        // Print the result of the run function which checks the character frequency
        System.out.println(run(s, t));
        
        scanner.close();
    }
}

// <END-OF-CODE>
