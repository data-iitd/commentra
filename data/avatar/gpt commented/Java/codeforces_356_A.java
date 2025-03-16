import java.util.*; 
import java.io.*; 

public class Main { 
    public static void main(String[] args) throws Exception { 
        // Initialize FastReader to read input efficiently
        FastReader in = new FastReader(); 
        
        // Read the number of elements
        int n = in.nextInt(); 
        
        // Create a TreeSet to keep track of available positions on the left
        TreeSet<Integer> left = new TreeSet<>(); 
        
        // Initialize an array to store the answers
        int[] answer = new int[n]; 
        
        // Populate the TreeSet with indices from 0 to n-1
        for (int i = 0; i < n; i++) { 
            left.add(i); 
        } 
        
        // Read the number of queries
        int q = in.nextInt(); 
        
        // Process each query
        while (q-- > 0) { 
            // Read the range [l, r] and the winning index
            int l = in.nextInt() - 1; 
            int r = in.nextInt() - 1; 
            int win = in.nextInt(); 
            
            // Update the answer array for all positions in the range [l, r]
            while (left.ceiling(l) != null && left.ceiling(l) <= r) { 
                int curr = left.ceiling(l); // Get the smallest index >= l
                answer[curr] = win; // Set the answer for this position
                left.remove(curr); // Remove this position from available positions
            } 
            
            // Mark the winning index as available again
            answer[win - 1] = 0; 
            left.add(win - 1); // Add the winning index back to available positions
        } 
        
        // Build the output string from the answer array
        StringBuilder ans = new StringBuilder(); 
        for (int i = 0; i < n; i++) { 
            ans.append(answer[i] + ""); // Append each answer to the StringBuilder
        } 
        
        // Print the final answer
        System.out.println(ans); 
    } 
    
    // FastReader class for efficient input reading
    static class FastReader { 
        StringTokenizer st; 
        BufferedReader br; 
        
        public FastReader() { 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
        
        // Method to read the next token as a String
        String next() { 
            while (st == null || !st.hasMoreElements()) { 
                try { 
                    st = new StringTokenizer(br.readLine()); 
                } catch (IOException e) { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
        
        // Method to read the next token as an integer
        int nextInt() { 
            return Integer.parseInt(next()); 
        } 
        
        // Method to read the next token as a long
        long nextLong() { 
            return Long.parseLong(next()); 
        } 
        
        // Method to read the next token as a double
        double nextDouble() { 
            return Double.parseDouble(next()); 
        } 
        
        // Method to read the next line as a String
        String nextLine() { 
            String s = ""; 
            while (st == null || st.hasMoreElements()) { 
                try { 
                    s = br.readLine(); 
                } catch (IOException e) { 
                    e.printStackTrace(); 
                } 
            } 
            return s; 
        } 
    } 
}
