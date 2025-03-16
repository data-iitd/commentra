import java.io.*; 
import java.util.*; 

public class Main { 
    public static void main(String[] args) throws Exception { 
        // Initialize BufferedReader to read input from standard input
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in)); 
        
        // Initialize PrintWriter to output results to standard output
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out))); 
        
        // Read the first line of input and tokenize it to extract n and k
        StringTokenizer st = new StringTokenizer(f.readLine()); 
        int n = Integer.parseInt(st.nextToken()); // Number of cards
        int k = Integer.parseInt(st.nextToken()); // Maximum number of changes allowed
        
        // Create an array of c462b objects to count occurrences of each letter
        c462b[] cards = new c462b[26]; 
        for (int i = 0; i < 26; i++) { 
            cards[i] = new c462b(); // Initialize each card
        } 
        
        // Read the string of cards and count the occurrences of each letter
        String s = f.readLine(); 
        for (int t = 0; t < n; t++) { 
            cards[s.charAt(t) - 'A'].left++; // Increment the count for the corresponding letter
        } 
        
        long ans = 0; // Variable to store the final answer
        
        // Perform k operations to maximize the score
        for (int i = 0; i < k; i++) { 
            Arrays.sort(cards); // Sort the cards based on the count of letters
            
            // Determine the number of changes to make for the most frequent letter
            long change = Math.min(cards[25].left, k - i); 
            ans += change * change; // Update the answer with the square of changes
            
            // Decrease the count of the most frequent letter by the number of changes made
            cards[25].left -= change; 
            i += change - 1; // Adjust the loop counter based on changes made
        } 
        
        // Output the final result
        out.println(ans); 
        out.close(); // Close the output stream
    } 
} 

// Class to represent each card and implement Comparable for sorting
class c462b implements Comparable { 
    int left = 0; // Count of letters left
    
    @Override 
    public int compareTo(Object o) { 
        return left - ((c462b) o).left; // Compare based on the count of letters
    } 
}
