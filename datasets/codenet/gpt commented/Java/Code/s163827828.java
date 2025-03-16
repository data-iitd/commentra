import java.util.*;

public class Main {
    public static void main(String args[]) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the number of strings to be processed
        int N = Integer.parseInt(sc.next());
        
        // Initialize an array to store the strings
        String s[] = new String[N];
        
        // Initialize counters for strings starting with 'B' and ending with 'A'
        int a_num = 0;
        int b_num = 0;
        
        // Flag to check if the conditions are met
        boolean flag = true;
        
        // Variable to count occurrences of "AB" in the strings
        int ans = 0;
        
        // Loop through each string input
        for(int i = 0; i < N; i++) {
            // Read the string from input
            s[i] = sc.next();
            
            // Count how many strings start with 'B'
            if(s[i].substring(0, 1).equals("B")) {
                b_num++;
            }
            
            // Count how many strings end with 'A'
            if(s[i].substring(s[i].length() - 1, s[i].length()).equals("A")){
                a_num++;
            }
            
            // Check if the string starts with 'B' or ends with 'A'
            if(s[i].substring(0, 1).equals("B") || s[i].substring(s[i].length() - 1, s[i].length()).equals("A")) {
                // If both conditions are not met, set the flag to false
                if(!(s[i].substring(0, 1).equals("B") && s[i].substring(s[i].length() - 1, s[i].length()).equals("A"))) {
                    flag = false;
                }
            }
            
            // Count occurrences of the substring "AB" in the current string
            for(int j = 0; j < s[i].length() - 1; j++) {
                if(s[i].substring(j, j + 2).equals("AB")) ans++;
            }
        }
        
        // Add the minimum of a_num and b_num to the answer
        ans += Math.min(a_num, b_num);
        
        // If there is at least one 'A' and one 'B', and the flag is true, decrement the answer
        if(Math.min(a_num, b_num) != 0 && flag) {
            ans--;
        }
        
        // Print the final result
        System.out.println(ans);
    }
}
