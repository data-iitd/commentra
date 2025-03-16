import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the input string from the user
        String S = sc.next();
        
        // Initialize variables to hold substrings
        String begin;
        String end;
        String answer;
        
        // Loop through each character index in the string S
        for(int i = 0; i < S.length(); i++) {
            
            // Nested loop to check all possible substrings
            for(int j = 0; j < S.length(); j++) {
                
                // Get the substring from the start to the current index i
                begin = S.substring(0, i);
                
                // Get the substring from the current index j to the end of the string
                end = S.substring(j, S.length());
                
                // Concatenate the two substrings
                answer = begin + end;
                
                // Check if the concatenated string equals "keyence"
                if(answer.equals("keyence")) {
                    System.out.println("YES");
                    return; // Exit the program if "keyence" is found
                    
                // Check if the beginning substring equals "keyence"
                } else if(begin.equals("keyence")) {
                    System.out.println("YES");
                    return; // Exit the program if "keyence" is found at the beginning
                    
                // Check if the ending substring equals "keyence"
                } else if(end.equals("keyence")) {
                    System.out.println("YES");
                    return; // Exit the program if "keyence" is found at the end
                }
            }
        }
        
        // If none of the conditions were met, print "NO"
        System.out.println("NO");
    }
}
