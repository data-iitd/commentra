import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        // Initialize a Scanner object to read input from the standard input stream
        Scanner sc = new Scanner(System.in);
        
        // Read the next input line and assign it to a String variable S
        String S = sc.next();
        
        String begin;
        String end;
        String answer;
        
        // Iterate through each character position i in the String S
        for (int i = 0; i < S.length(); i++) {
            
            // Initialize two String variables begin and end to store substrings of the String S
            begin = S.substring(0, i);
            end = S.substring(i + 1, S.length());
            
            // Concatenate the substrings begin and end to form a new String variable answer
            String answer = begin + end;
            
            // Check if the String answer equals the target string "keyence"
            if (answer.equals("keyence")) {
                System.out.println("YES");
                return;
            }
            
            // Check if the substring begin equals the target string "keyence"
            if (begin.equals("keyence")) {
                System.out.println("YES");
                return;
            }
            
            // Check if the substring end equals the target string "keyence"
            if (end.equals("keyence")) {
                System.out.println("YES");
                return;
            }
        }
        
        // If none of the conditions are true, print "NO"
        System.out.println("NO");
    }
}
