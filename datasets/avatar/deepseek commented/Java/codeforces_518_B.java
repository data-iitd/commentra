
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        // Step 1: Read the input string `s` and the target string `t`.
        StringBuilder s = new StringBuilder(scan.next());
        String t = scan.next();
        
        // Initialize counters for the number of replacements
        int ura = 0; // Counter for replacements in step 3
        int opa = 0; // Counter for replacements in step 4
        
        // Step 2: Create a frequency map `tmap` for characters in `t`.
        Map<Character, Integer> tmap = new HashMap<>();
        for (int i = 0; i < t.length(); i++) {
            Character ch = t.charAt(i);
            if (!tmap.containsKey(ch)) {
                tmap.put(ch, 1);
            } else {
                tmap.put(ch, tmap.get(ch) + 1);
            }
        }
        
        // Step 3: Iterate through `s` and replace characters that are in `t` with 'Я'.
        int length = s.length();
        for (int i = 0; i < length; i++) {
            Character ch = s.charAt(i);
            Integer num = tmap.get(ch);
            if (num == null) continue;
            int inum = num;
            if (inum == 1) {
                tmap.remove(ch);
            } else {
                tmap.put(ch, inum - 1);
            }
            s.setCharAt(i, 'Я');
            ura++;
        }
        
        // Step 4: Iterate through `s` again and replace characters that are the reverse of characters in `t` with their reverse.
        for (int i = 0; i < length; i++) {
            Character ch = s.charAt(i);
            Character rch = reverse(ch);
            Integer num = tmap.get(rch);
            if (num == null) continue;
            int inum = num;
            if (inum == 1) {
                tmap.remove(rch);
            } else {
                tmap.put(rch, inum - 1);
            }
            opa++;
        }
        
        // Step 5: Print the results `ura` and `opa`.
        System.out.println(ura + " " + opa);
    }
    
    // Helper method to reverse the case of a character
    public static Character reverse(Character ch) {
        if (Character.isLowerCase(ch)) {
            return Character.toUpperCase(ch);
        } else {
            return Character.toLowerCase(ch);
        }
    }
}

