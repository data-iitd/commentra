import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStream; 
import java.io.InputStreamReader; 
import java.io.OutputStream; 
import java.io.PrintWriter; 
import java.util.ArrayList; 
import java.util.Collections; 
import java.util.List; 
import java.util.StringTokenizer; 

public class Main { 
    public static void main(String[] args) { 
        // Set up input and output streams
        InputStream inputStream = System.in; 
        OutputStream outputStream = System.out; 
        InputReader in = new InputReader(inputStream); 
        PrintWriter out = new PrintWriter(outputStream); 
        
        // Read four integers from input
        int a = in.nextInt(); 
        int b = in.nextInt(); 
        int c = in.nextInt(); 
        int d = in.nextInt(); 
        
        // Check conditions to determine the output
        if (c > b) { 
            // If c is greater than b, output 0
            System.out.println(0); 
        } else if (a > d) { 
            // If a is greater than d, output 0
            System.out.println(0); 
        } else if (a < c) { 
            // If a is less than c, calculate and output the difference
            System.out.println(Math.min(b, d) - c); 
        } else { 
            // Create a list to hold the four integers
            List<Integer> l = new ArrayList<>(); 
            l.add(a); 
            l.add(b); 
            l.add(c); 
            l.add(d); 
            
            // Sort the list to find the second largest and third largest values
            Collections.sort(l); 
            
            // Output the difference between the second largest and third largest values
            System.out.println(l.get(2) - l.get(1)); 
        } 
    } 
    
    // InputReader class to handle input reading
    static class InputReader { 
        public BufferedReader reader; 
        public StringTokenizer tokenizer; 
        
        // Constructor to initialize the BufferedReader
        public InputReader(InputStream stream) { 
            reader = new BufferedReader(new InputStreamReader(stream), 32768); 
            tokenizer = null; 
        } 
        
        // Method to read the next token as a String
        public String next() { 
            while (tokenizer == null || !tokenizer.hasMoreTokens()) { 
                try { 
                    tokenizer = new StringTokenizer(reader.readLine()); 
                } catch (IOException e) { 
                    throw new RuntimeException(e); 
                } 
            } 
            return tokenizer.nextToken(); 
        } 
        
        // Method to read the next token as an integer
        public int nextInt() { 
            return Integer.parseInt(next()); 
        } 
        
        // Method to read the next token as a long
        public long nextLong() { 
            return Long.parseLong(next()); 
        } 
    } 
}
