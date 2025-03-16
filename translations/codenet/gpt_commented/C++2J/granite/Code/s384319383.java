
import java.util.*;
import java.io.*;

public class s384319383{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()); // Read the number of characters
        String[] s = br.readLine().split(" "); // Read the characters and split them into an array
        long[] cnt = new long[26]; // Initialize an array to count occurrences of each character (a-z)
        Arrays.fill(cnt, 1); // Start with 1 to account for the multiplication later
        long ans = cnt[0]; // Initialize answer with the count of 'a'
        
        // Calculate the product of counts for all characters from 'b' to 'z'
        for(int i = 1; i < 26; ++i){
            for(String c : s){ // Iterate over each character
                if(c.charAt(0) - 'a' == i){ // Check if the character is the current one
                    cnt[i]++; // Increment the count for the current character
                }
            }
            ans *= cnt[i]; // Multiply the current answer by the count of the character
            ans %= 100000007; // Take modulo to prevent overflow
        }

        // Output the final result, subtracting 1 to exclude the empty product case
        System.out.println(ans - 1); // Output the final result
        br.close(); // Close the input stream
    }
}
