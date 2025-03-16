import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read input strings s and t from the user
        String s = sc.next();
        String t = sc.next();
        
        // Print the result of the run function which checks the character frequency
        System.out.println(run(s, t));
    }
    
    public static String run(String s, String t) {
        // Count the frequency of each character in string s and sort the frequencies
        List<Integer> ss = new ArrayList<Integer>(Collections.nCopies(26, 0));
        for (int i = 0; i < s.length(); i++) {
            ss.set(s.charAt(i) - 'a', ss.get(s.charAt(i) - 'a') + 1);
        }
        Collections.sort(ss);
        
        // Count the frequency of each character in string t and sort the frequencies
        List<Integer> tt = new ArrayList<Integer>(Collections.nCopies(26, 0));
        for (int i = 0; i < t.length(); i++) {
            tt.set(t.charAt(i) - 'a', tt.get(t.charAt(i) - 'a') + 1);
        }
        Collections.sort(tt);
        
        // Compare the sorted frequency lists of both strings
        if (ss.equals(tt)) {
            return "Yes";  // Return 'Yes' if the frequency distributions are the same
        } else {
            return "No";   // Return 'No' if the frequency distributions are different
        }
    }
}

