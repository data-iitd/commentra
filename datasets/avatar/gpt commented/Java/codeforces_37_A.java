import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a FastScanner object to read input efficiently
        FastScanner input = new FastScanner(); 
        
        // Read the number of integers to be processed
        int n = input.nextInt(); 
        
        // Initialize a HashMap to store the frequency of each integer
        HashMap<Integer, Integer> map = new HashMap<>(); 
        
        // Loop through the input integers and populate the frequency map
        for (int i = 0; i < n; i++) { 
            int val = input.nextInt(); 
            // Update the count of the integer in the map
            map.put(val, map.getOrDefault(val, 0) + 1); 
        } 
        
        // Initialize a variable to track the maximum frequency found
        int max = Integer.MIN_VALUE; 
        
        // Iterate through the entries in the frequency map to find the maximum frequency
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) { 
            Integer value = entry.getValue(); 
            // Update max if the current frequency is greater than the current max
            max = Math.max(max, value); 
        } 
        
        // Print the maximum frequency and the number of unique integers
        System.out.println(max + "" + map.size()); 
    } 
    
    // FastScanner class for efficient input reading
    static class FastScanner { 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        StringTokenizer st = new StringTokenizer(""); 
        
        // Method to get the next token from input
        String next() { 
            // Read new line if there are no more tokens
            while (!st.hasMoreTokens()) { 
                try { 
                    st = new StringTokenizer(br.readLine()); 
                } catch (IOException e) { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
        
        // Method to read the next integer from input
        int nextInt() { 
            return Integer.parseInt(next()); 
        } 
        
        // Method to read the next long from input
        long nextLong() { 
            return Long.parseLong(next()); 
        } 
        
        // Method to read the next double from input
        double nextDouble() { 
            return Double.parseDouble(next()); 
        } 
        
        // Method to read the next line from input
        String nextLine() throws IOException { 
            return br.readLine(); 
        } 
    } 
}
