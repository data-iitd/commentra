import java.util.*;

public class Main {
    public static String run(String s, String t) {
        // Count the frequency of each character in string s and sort the frequencies
        List<Integer> ss = countFrequencies(s);
        Collections.sort(ss);
        
        // Count the frequency of each character in string t and sort the frequencies
        List<Integer> tt = countFrequencies(t);
        Collections.sort(tt);
        
        // Compare the sorted frequency lists of both strings
        if (ss.equals(tt)) {
            return "Yes";  // Return 'Yes' if the frequency distributions are the same
        } else {
            return "No";   // Return 'No' if the frequency distributions are different
        }
    }
    
    private static List<Integer> countFrequencies(String str) {
        Map<Character, Integer> frequencyMap = new HashMap<>();
        for (char c : str.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }
        
        List<Integer> frequencies = new ArrayList<>(frequencyMap.values());
        return frequencies;
    }

    public static void main(String[] args) {
        // Read input strings s and t from the user
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();
        
        // Print the result of the run function which checks the character frequency
        System.out.println(run(s, t));
    }
}
