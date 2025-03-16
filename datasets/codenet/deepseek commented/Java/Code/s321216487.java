
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        // Read the input string S from the user
        Scanner sc = new Scanner(System.in);
		String S = sc.next();
		
		// Initialize variables to store substrings
		String begin;
		String end;
		String answer;
		
		// Nested loop to generate all possible substrings
		for(int i = 0; i < S.length(); i++) {
		    
		    for(int j = 0; j < S.length(); j++) {
		        
		        // Generate the begin and end substrings
		        begin = S.substring(0, i);
		        end = S.substring(j, S.length());
		        answer = begin + end;
		        
		        // Check if the combined string is equal to "keyence"
		        if(answer.equals("keyence")) {
		            System.out.println("YES");
		            return; // Exit the program if condition is met
		        }
		        
		        // Check if begin or end is equal to "keyence"
		        if(begin.equals("keyence")) {
		            System.out.println("YES");
		            return; // Exit the program if condition is met
		        }
		        
		        if(end.equals("keyence")) {
		            System.out.println("YES");
		            return; // Exit the program if condition is met
		        }
		    }
		}
		
		// If none of the conditions are met, print "NO"
		System.out.println("NO");
	}
}

